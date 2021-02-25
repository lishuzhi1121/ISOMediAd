//
//  XYTableViewController.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/24.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYTableViewController.h"
#import "XYAdsCommonDefine.h"
#import <XYADFramework/XYAdPlatform.h>
#import <Masonry/Masonry.h>
#import <GoogleMobileAdsMediationTestSuite/GoogleMobileAdsMediationTestSuite.h>

#import "XYCommonAdsViewController.h"
#import "XYNativeAdsCollectionViewController.h"

@interface XYTableViewController ()

@property (nonatomic, strong) UIView *splashAdView;
@property (nonatomic, strong) UIWindow *splashAdContainerWindow;

@end

@implementation XYTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (IBAction)AdMobMediationClicked:(UIBarButtonItem *)sender {
    [GoogleMobileAdsMediationTestSuite presentOnViewController:self delegate:nil];
}



#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        // 开屏广告
        [self _handleSplashAd];
    }
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

#pragma mark - 开屏广告

- (void)_handleSplashAd {
    if (self.splashAdView) {
        [self.splashAdView removeFromSuperview];
        self.splashAdView = nil;
    }
    self.splashAdView = [[XYAdPlatform sharedInstance] createSplashAdViewWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"16").adFrame(self.view.bounds).viewController(self);
    } result:^(XYAdModule *adModule, XYAdRequestState state) {
        NSLog(@"userdata: %@ --- state: %lu", adModule.userData, (unsigned long)state);
        switch (state) {
            case XYAdRequestStateStart:
                NSLog(@"--- 开始加载开屏广告 ---");
                break;
            case XYAdRequestStateDidLoad:
            {
                NSLog(@"--- 开屏广告加载成功,即将展示 ---");
                // 广告加载成功后展示
                [[XYAdPlatform sharedInstance] showSplashAdViewWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
                    maker.placement(@"16").adFrame(self.view.bounds).viewController(self);
                }];
                break;
            }
            case XYAdRequestStateShow:
                NSLog(@"--- 开屏广告展示成功 ---");
                break;
            case XYAdRequestStateClose:
            {
                NSLog(@"--- 开屏广告关闭 ---");
                if (self.splashAdView) {
                    self.splashAdContainerWindow.hidden = YES;
                    [self.splashAdView removeFromSuperview];
                    self.splashAdView = nil;
                }
                break;
            }
                
            default:
                break;
        }
    }];
    // 一般广告商的开屏广告都是一个全屏VC,直接present出来即可,不会返回一个View视图
    // 但是部分广告商的开屏广告是返回一个View的形式,所以需要自己添加到一个父视图上展示
    if (self.splashAdView) {
        self.splashAdView.backgroundColor = [UIColor whiteColor];
        [self.splashAdContainerWindow addSubview:self.splashAdView];
        [self.splashAdView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(50);
            make.left.mas_equalTo(20);
            make.right.mas_equalTo(-20);
            make.width.mas_equalTo(self.splashAdView.mas_height).multipliedBy(0.75);
        }];
        // 展示容器
        self.splashAdContainerWindow.hidden = NO;
    }
}


#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    NSLog(@"%s -- sender: %@ -- des: %@", __func__, sender, [segue destinationViewController]);
    if ([sender isKindOfClass:[UITableViewCell class]]) {
        UITableViewCell *selectedCell = (UITableViewCell *)sender;
        NSIndexPath *selectedIndexPath = [self.tableView indexPathForCell:selectedCell];
        XYAdsDemoAdType selectedAdType = selectedIndexPath.row;
        UIViewController *desVC = [segue destinationViewController];
        if ([desVC isKindOfClass:[XYCommonAdsViewController class]]) {
            ((XYCommonAdsViewController *)desVC).demoAdType = selectedAdType;
        }
    }
}


#pragma mark - getter

- (UIWindow *)splashAdContainerWindow {
    if (!_splashAdContainerWindow) {
        _splashAdContainerWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        _splashAdContainerWindow.backgroundColor = [UIColor colorWithWhite:0.5 alpha:1.0];
        _splashAdContainerWindow.windowLevel = UIWindowLevelAlert + 1;
        _splashAdContainerWindow.hidden = YES;
    }
    return _splashAdContainerWindow;
}

@end
