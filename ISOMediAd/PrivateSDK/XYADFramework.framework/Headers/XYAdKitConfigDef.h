//
//  XYAdKitConfigDef.h
//  AFNetworking
//
//  Created by Frenzy Feng on 2018/8/15.
//

#import <Foundation/Foundation.h>

/* Notification --- Splash */
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashDidLoad;
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashDidLoadFailed;
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashDidClick;
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashDidClose;
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashWillClose;
FOUNDATION_EXTERN NSString * const XYAdNotificationSplashWillVisible;

/* Producers */
FOUNDATION_EXTERN NSString * const XYAdProducerFacebook;
FOUNDATION_EXTERN NSString * const XYAdProducerAdMob;
FOUNDATION_EXTERN NSString * const XYAdProducerMobv;//维斯塔
FOUNDATION_EXTERN NSString * const XYAdProducerBaidu;
FOUNDATION_EXTERN NSString * const XYAdProducerYeahmobi;
FOUNDATION_EXTERN NSString * const XYAdProducerWM;
FOUNDATION_EXTERN NSString * const XYAdProducerJR;
FOUNDATION_EXTERN NSString * const XYAdProducerVungle;
FOUNDATION_EXTERN NSString * const XYAdProducerMoPub;

/* Types */
FOUNDATION_EXTERN NSString * const XYAdTypeNative;
FOUNDATION_EXTERN NSString * const XYAdTypeRewardVideo;
FOUNDATION_EXTERN NSString * const XYAdTypeInterstitial;
FOUNDATION_EXTERN NSString * const XYAdTypeBanner;
FOUNDATION_EXTERN NSString * const XYAdTypeSplash;
FOUNDATION_EXTERN NSString * const XYAdTypeCard;
FOUNDATION_EXTERN NSString * const XYAdTypeNativeBanner;
FOUNDATION_EXTERN NSString * const XYAdTypeInterstitialVideo;

//广告商编号（1:Facebook 2:Admob 3:MOB维斯塔 4:Pingstart 5:Altamob 6:Loopme 7:AdColony 9:AppLovin ）
typedef NS_ENUM(NSInteger, XYAdProducers) {
    XYAdProducers_Facebook       = 1,
    XYAdProducers_AdMob          = 2,
    XYAdProducers_Mobv           = 3, //Mob维斯塔
    XYAdProducers_AppLovin       = 9,  //已移除
    XYAdProducers_Baidu          = 10, //已移除
    XYAdProducers_YeahMobi       = 11,
    XYAdProducers_InMobi         = 12, //已移除
    XYAdProducers_Into           = 19, //Into沃尔沃 已移除
    XYAdProducers_MoPub          = 20, //MoPub
    XYAdProducers_WM             = 21, //头条网盟SDK
    XYAdProducers_Vungle         = 25, //Vungle
};

/*
 * 广告类型
 * 文档地址：https://quvideo.worktile.com/drive/58ed998f9287cd7a778c0c10/58ed998f9287cd7a778c0c79
 */
typedef NS_ENUM(NSInteger, XYAdType) {
    XYAdType_Native       = 0,
    XYAdType_Reward       = 1, //奖励下载
    XYAdType_Interstitial = 2,
    XYAdType_Install      = 3, //激励下载，目前仅限Android端
    XYAdType_Banner       = 4, //View类型
    XYAdType_Splash       = 5, //View类型
    XYAdType_Card         = 6, //卡片类型，目前仅有广告商Into沃尔沃(已移除)
    XYAdType_NativeBanner = 7, //原生横幅，目前仅限Android端
    XYAdType_Medium       = 8, //大banner，目前仅限Android端
    XYAdType_InterstitialVideo  = 9, //插屏视频，目前仅有Mobv
    XYAdType_Wall         = 666, //广告墙，目前仅有Mobv，且不在广告类型配置中.目前使用todocode配置
};

typedef enum : NSUInteger {
    XYAdFetchStrategyType_Sync,     //请求等待优先级高的广告商先返回
    XYAdFetchStrategyType_Async,    //同时发起N个广告商请求
} XYAdFetchStrategyType;

@class XYAdModule;
@interface XYAdKitConfigDef : NSObject

/*
 * 获取 producerId 对应的 XYAdProducer
 */
+ (NSString *)xy_adConfigProducerByProducerId:(NSString *)producerId;
/*
 * 获取 producerName 对应的 producerId
 */
+ (NSInteger)xy_adConfigProducerIdByProducerName:(NSString *)producerName;

/*
 * 获取 typeId 对应的 XYAdType
 */
+ (NSString *)xy_adConfigType:(NSString *)typeId;

/*
 * 获取 对应广告商 Name
 */
+ (NSString *)xy_adGetProducerName:(XYAdModule *)adModule;
    
@end
