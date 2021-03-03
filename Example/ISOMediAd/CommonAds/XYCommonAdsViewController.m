//
//  XYCommonAdsViewController.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/24.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYCommonAdsViewController.h"
#import <XYADFramework/XYAdPlatform.h>
//#import <XYADFramework/XYAdVungleBannerContainer.h>
//#import <XYADFramework/XYAdVungleMediumContainer.h>
#import <Masonry/Masonry.h>

@interface XYCommonAdsViewController ()

/// banner 广告视图容器(默认隐藏)
@property (weak, nonatomic) IBOutlet UIView *bannerAdViewContainner;

/// banner 广告视图对象
@property (nonatomic, strong) UIView *bannerAdView;

/// Vungle MREC 广告视图容器(固定大小 300*250, 默认隐藏)
@property (weak, nonatomic) IBOutlet UIView *mediumAdViewContainner;

/// Vungle MREC 广告视图对象
@property (nonatomic, strong) UIView *mediumAdView;

@end

@implementation XYCommonAdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSString *title = [self titleWithAdType:self.demoAdType];
    if (title.length > 0) {
        self.title = title;
    }
    
    self.bannerAdViewContainner.hidden = !(self.demoAdType == XYAdsDemoAdTypeBanner);
    self.mediumAdViewContainner.hidden = !(self.demoAdType == XYAdsDemoAdTypeVungleMREC);
    
    // 请求广告
    [self fetchCommonAds];
    
}

#pragma mark - 请求广告

- (void)fetchCommonAds {
    switch (self.demoAdType) {
        case XYAdsDemoAdTypeBanner:
            [self fetchBannerAd];
            break;
        case XYAdsDemoAdTypeInterstital:
            [self fetchInterstitialAd];
            break;
        case XYAdsDemoAdTypeReward:
            [self fetchRewardAd];
            break;
        case XYAdsDemoAdTypeInterstitalVideo:
            [self fetchInterstitialVideoAd];
            break;
        case XYAdsDemoAdTypeVungleMREC:
            [self fetchMediumAD];
            break;
            
        default:
            NSLog(@"--- 其他广告类型单独处理 ---");
            break;
    }
}

#pragma mark - Banner 横幅广告

- (void)fetchBannerAd {
    BOOL success = [self showCachedBannerAd];
    // 未展示成功说明没有缓存好的广告,重新请求一个再展示
    if (!success) {
        __weak typeof(self) weakSelf = self;
        [[XYAdPlatform sharedInstance] fetchBannerAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
            maker.placement(@"2").adSize(CGSizeMake(self.view.bounds.size.width, 50)).viewController(weakSelf);
        } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
            if (status == XYAdFetchStatusSuccess) {
                [weakSelf showCachedBannerAd];
            }
        }];
    }
}

- (BOOL)showCachedBannerAd {
    if (self.bannerAdView) {
        return YES;
    }
    __weak typeof(self) weakSelf = self;
    self.bannerAdView = [[XYAdPlatform sharedInstance] createBannerAdViewWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"2").adSize(CGSizeMake(self.view.bounds.size.width, 50)).viewController(weakSelf);
    }];
    if (self.bannerAdView) {
//        if ([self.bannerAdView isKindOfClass:[XYAdVungleBannerContainer class]]) {
//            // NOTE: 如果是Vungle的banner广告, 则只需要添加到父视图上, 调整居中即可,不能改变大小
//            self.bannerAdView.center = self.bannerAdViewContainner.center;
//            [self.bannerAdViewContainner addSubview:self.bannerAdView];
//        } else {
//            // NOTE: 其他的banner广告可以添加到父视图之后进行自定义布局设置
//            [self.bannerAdViewContainner addSubview:self.bannerAdView];
//            [self.bannerAdView mas_remakeConstraints:^(MASConstraintMaker *make) {
//                make.top.left.right.bottom.mas_equalTo(0);
//            }];
//        }
        
        return YES;
    }
    
    return NO;
}

#pragma mark - Interstitial 插屏广告

- (void)fetchInterstitialAd {
    __weak typeof(self) weakSelf = self;
    [[XYAdPlatform sharedInstance] fetchInterstitialAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"3").viewController(weakSelf);
    } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
        if (status == XYAdFetchStatusSuccess) {
            [weakSelf showInterstitialAd];
        }
    }];
}

- (void)showInterstitialAd {
    __weak typeof(self) weakSelf = self;
    [[XYAdPlatform sharedInstance] showInterstitialAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"3").viewController(weakSelf);
    }];
}

#pragma mark - Reward 激励视频广告

- (void)fetchRewardAd {
    __weak typeof(self) weakSelf = self;
    [[XYAdPlatform sharedInstance] preloadRewardAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"2").from(NSStringFromClass(weakSelf.class)).viewController(weakSelf);
    } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
        if (status == XYAdFetchStatusSuccess) {
            [weakSelf showRewardAd];
        }
    }];
}

- (void)showRewardAd {
    __weak typeof(self) weakSelf = self;
    [[XYAdPlatform sharedInstance] showRewardAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"2").viewController(weakSelf);
    }
                                               onRewardResult:^(XYAdModule *adModule, BOOL isRewarded) {
        NSLog(@"--- placement: %@ producer: %@ isRewarded: %d ---", adModule.adsPlacement, adModule.adsProducer, isRewarded);
    }];
}

#pragma mark - InterstitialVideo 插屏视频广告

- (void)fetchInterstitialVideoAd {
    [[XYAdPlatform sharedInstance] fetchInterstitialVideoAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"18").viewController(self);
    } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
        [self showInterstitialVideoAd];
    }];
}

- (void)showInterstitialVideoAd {
    [[XYAdPlatform sharedInstance] showInterstitialVideoAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"18").viewController(self);
    }];
}

#pragma mark - Vungle MREC广告

- (void)fetchMediumAD {
    BOOL success = [self showCachedMediumAd];
    // 未展示成果说明没有缓存好的广告,重新请求一个再展示
    if (!success) {
        __weak typeof(self) weakSelf = self;
        [[XYAdPlatform sharedInstance] fetchMRECAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
            maker.placement(@"16").adSize(CGSizeMake(300, 250)).viewController(self);
        } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
            if (status == XYAdFetchStatusSuccess) {
                [weakSelf showCachedMediumAd];
            }
        }];
    }
}

- (BOOL)showCachedMediumAd {
    self.mediumAdView = [[XYAdPlatform sharedInstance] createMediumAdViewWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"16").adSize(CGSizeMake(300, 250)).viewController(self);
    }];
    if (self.mediumAdView) {
//        if ([self.mediumAdView isKindOfClass:[XYAdVungleMediumContainer class]]) {
//            // NOTE: 如果是Vungle的MREC广告, 则只需要添加到父视图上, 调整居中即可,不能改变大小
//            self.mediumAdView.center = self.mediumAdViewContainner.center;
//            [self.mediumAdViewContainner addSubview:self.mediumAdView];
//        }
        
        return YES;
    }
    
    return NO;
}


#pragma mark - 刷新广告

- (IBAction)refreshButtonItemClicked:(UIBarButtonItem *)sender {
    if (self.bannerAdView) {
        [self.bannerAdView removeFromSuperview];
        self.bannerAdView = nil;
    }
    if (self.mediumAdView) {
        [self.mediumAdView removeFromSuperview];
        self.mediumAdView = nil;
    }
    [self fetchCommonAds];
}

#pragma mark - getter

- (NSString *)titleWithAdType:(XYAdsDemoAdType)type {
    NSString *title = nil;
    switch (type) {
        case XYAdsDemoAdTypeSplash:
            return @"Splash 开屏广告";
            break;
        case XYAdsDemoAdTypeBanner:
            return @"Banner 横幅广告";
            break;
        case XYAdsDemoAdTypeInterstital:
            return @"Interstitial 插屏广告";
            break;
        case XYAdsDemoAdTypeReward:
            return @"Reward 激励视频广告";
            break;
        case XYAdsDemoAdTypeInterstitalVideo:
            return @"InterstitialVideo 插屏视频广告";
            break;
        case XYAdsDemoAdTypeVungleMREC:
            return @"Vungle MREC广告";
            break;
            
        default:
            break;
    }
    
    return title;
}


- (void)dealloc
{
    NSLog(@"%s", __func__);
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
