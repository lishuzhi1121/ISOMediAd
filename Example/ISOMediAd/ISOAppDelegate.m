//
//  ISOAppDelegate.m
//  ISOMediAd
//
//  Created by SandsLee on 02/24/2021.
//  Copyright (c) 2021 SandsLee. All rights reserved.
//

#import "ISOAppDelegate.h"

#import <XYADFramework/XYCommonAPIManager.h>
#import <XYADFramework/XYMediEventManager.h>

#import <XYADFramework/XYAdPlatform.h>
#import <XYADFramework/XYAdCore.h>
#import <XYADFramework/XYAdConfig.h>
//#import <XYADFramework/XYUserBehaviorLog.h>
//#import <XYADFramework/UIDevice+XYInfo.h>
#import "XYAdsCommonDefine.h"

@implementation ISOAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    [XYMediEventManager sharedInstance].eventAdapter = self;

    [XYCommonAPIManager manager].curRouterDomain = @"https://medi.rthdo.com";
    [[XYCommonAPIManager manager] configCommonAPIManagerParams:^(XYCommonParamsModel *model) {
        model.appKey = @"20008300";
        model.productId = 10;
        model.device = @"DIjkdj";
    }];
    
    // 初始化日志组件
    [self setupUserLoggerKit];
    
    // 初始化广告组件
    [self setupAdPlatform];
    
//    NSString *idfa = [UIDevice currentDevice].xy_IDFAString;
//    NSLog(@"\n=====================\n本机IDFA: %@\n=====================\n", idfa);
    
    return YES;
}

- (void)setupUserLoggerKit {
    NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
//    NSDictionary *firebaseInfo = @{
//        XYLogAppKey:appVersion,
//        XYIsConfigured:@(1)// 目前设置为0,广告Google部分已经初始化,如果没有Google部分就必须为1
//    };
    
//    NSDictionary *aliyunInfo = @{
//        XYLogAppKey:@"28137171",
//        XYLogSecretKey:@"e1f246373650fcdb2b238ad3e0b7bb4c",
//        XYLogAppVersion:appVersion,
//        XYLogAppChannel:@"TS"
//    };
//
//    NSDictionary *kakaInfo = @{
//        XYLogProductId: @"10",
//        XYLogAppKey:@"28137171",
//        XYLogSecretKey:@"e1f246373650fcdb2b238ad3e0b7bb4c",
//        XYLogAppVersion:appVersion,
//        XYLogAppChannel:@"TS",
////        @"debugEnable": @(YES),
//        @"KakaAnalysisEnable": @(NO),
//    };
//
//    NSDictionary *behaviorLogInfos = @{
//        XYAliAnalytics:aliyunInfo,
//        XYKaKaAnalytics: kakaInfo
//    };
//
//    [[XYUserBehaviorLog shareInstance] startWithConfig:behaviorLogInfos needWebEventLog:NO];
}

/**
 Vungle tempo 测试数据:
     appId：5fc7551e475ee1a5e723cbdb
     插屏：BACK_TEMPLATE_DETAIL-1655565
     激励：TEMPLATE_UNLOCK-0236995
     MREC：MEDIUM_BANNER-9690163
     Banner：GALLERY_BANNER-1455330
 */

#define USE_LOCAL_CONFIG    1

- (void)setupAdPlatform {
    BOOL isVIP = [[NSUserDefaults standardUserDefaults] boolForKey:VIP_IS_ON_KEY];
    [[XYAdPlatform sharedInstance] enableAd:!isVIP];
    
    // 定义初始化广告中台block
    void (^setupBlock)(NSDictionary *) = ^(NSDictionary *configDict) {
        NSArray *dataList = configDict[@"data"];
        if ([dataList isKindOfClass:[NSArray class]] && dataList.count > 0) {
            XYAdProducerConfigModel *adProducerConfigModel = [XYAdProducerConfigModel new];
//            adProducerConfigModel.mobVistaAppId = @"23419";
//            adProducerConfigModel.mobVistaAppKey = @"4903e31828cd7bb519654c7216cf401f";
//            adProducerConfigModel.mobVistaAppId = @"118692";
//            adProducerConfigModel.mobVistaAppKey = @"7c22942b749fe6a6e361b675e96b3ee9";
//            adProducerConfigModel.wmAppId = @"5002398";
//            adProducerConfigModel.jRtoken = @"10045";
//            adProducerConfigModel.vungleAppId = @"5fc7551e475ee1a5e723cbdb";
//            adProducerConfigModel.mopubAdUnitId = @"4f117153f5c24fa6a3a92b818a5eb630";
            
            [[XYAdPlatform sharedInstance] initAdPlatformWithConfig:configDict
                                                      authorization:YES
                                              adProducerConfigModel:adProducerConfigModel];
        } else {
            UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"Error" message:@"广告中台配置异常" preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *okAc = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                
            }];
            [alertVc addAction:okAc];
            [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alertVc animated:YES completion:nil];
        }
    };
    
    if (USE_LOCAL_CONFIG) {
        // 使用本地配置
        NSString *configFilePath = [[NSBundle mainBundle] pathForResource:@"config" ofType:@"json"];
        NSData *configJsonData = [NSData dataWithContentsOfFile:configFilePath];
        NSError *error = nil;
        id jsonObj = [NSJSONSerialization JSONObjectWithData:configJsonData options:0 error:&error];
        NSLog(@"本地广告配置: %@", jsonObj);
        if (!error && [jsonObj isKindOfClass:[NSDictionary class]]) {
            NSDictionary *configDict = (NSDictionary *)jsonObj;
            if (setupBlock) {
                setupBlock(configDict);
            }
        }
    } else {
        // 请求线上配置
        [XYAdConfig requestAdConfig:nil completion:^(BOOL success, NSDictionary * _Nullable responseDict) {
            NSLog(@"线上广告配置: %@", responseDict);
            if (setupBlock) {
                setupBlock(responseDict);
            }
        }];
    }
    
}



#pragma mark - XYMediEventProtocol

- (void)appEventWithName:(NSString *)name attribute:(NSDictionary *)attribute {
    NSLog(@"--- %s --- name: %@ attribute: %@", __func__, name, attribute);
//    if ([name isKindOfClass:[NSString class]] && name.length > 0) {
//        [XYUserBehaviorLog event:name block:^NSDictionary *{
//            return attribute;
//        }];
//    }
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
