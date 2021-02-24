//
//  XYAdProtocol.h
//  XYAdSDK
//
//  Created by xuxinyuan on 3/2/16.
//  Copyright © 2016 QuVideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYAdView.h"
#import "XYAdModule.h"

@protocol XYAdProtocol <NSObject>

@required

@optional

#pragma mark - For Native Ad
- (void)registerNativeAdsViewForInteraction:(XYAdModule *)adsModule adView:(XYAdView *)adView;

- (UIView *)createMediaView:(XYAdModule *)adsModule frame:(CGRect)frame;
- (BOOL)isVideoCached:(XYAdModule *)adModule;

#pragma mark - For RewardedVideo Ads
- (BOOL)isRewardedVideoReadyForDisplay;
- (BOOL)showRewardedVideo;
- (void)preloadRewardedVideo;

#pragma mark - For Banner Ads
- (UIView *)createBannerAdViewWithPlacement:(NSString *)placement adId:(NSString *)adId adSize:(CGSize)adSize rootViewController:(UIViewController *)rootViewController;

@end
