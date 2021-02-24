//
//  XYAdsFetchProtocol.h
//  Pods
//
//  Created by hongru qi on 2016/12/3.
//
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class XYAdModule;
@class XYAdView;

@protocol XYAdsFetchProtocol <NSObject>

@optional

#pragma mark - 初始化授权
- (void)authorization:(BOOL)authorization;

#pragma mark - Banner横幅广告
- (UIView *)createBannerAdViewWithPlacement:(NSString *)placement adId:(NSString *)adId adSize:(CGSize)adSize rootViewController:(UIViewController *)rootViewController;
- (void)removeBannerAdView:(NSString *)placement;

#pragma mark - Interstitial插屏广告
- (void)fetchInterstitialAd:(XYAdModule *)adModule
                       from:(NSString *)from
                     result:(XYAdFetchResultBlock)result;

- (BOOL)showInterstitialAdWithPlacementID:(NSString *)placementID
                               controller:(UIViewController *)controller;

#pragma mark - Reward激励视频广告
- (BOOL)preloadRewardedVideo:(XYAdModule *)adsModule
                      result:(XYAdFetchResultBlock)result;

- (BOOL)showRewardedVideo:(XYAdModule *)adsModule controller:(UIViewController *)controller;

#pragma mark - Native原生广告
- (BOOL)fetchNativeAds:(XYAdModule *)adModule
                result:(XYAdFetchResultBlock)result;

- (void)registerNativeAdsView:(XYAdView *)adView
                     adModule:(XYAdModule *)adModule
               viewController:(UIViewController *)viewController
               clickableViews:(nullable NSArray<UIView *> *)clickableViews;

#pragma mark - Splash开屏广告
- (BOOL)showSplashAdWithPlacementID:(NSString *)placementID controller:(UIViewController *)controller;
- (BOOL)isVideoCached:(XYAdModule *)adModule;

- (void)initSpecialAd;

@end

NS_ASSUME_NONNULL_END
