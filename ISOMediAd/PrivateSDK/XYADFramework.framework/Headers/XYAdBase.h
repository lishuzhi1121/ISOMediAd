//
//  XYAdBase.h
//  XYAdSDK
//
//  Created by xuxinyuan on 3/3/16.
//  Copyright © 2016 QuVideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"
#import "XYAdsFetchProtocol.h"
#import "XYAdIntertitialProtocal.h"
#import "XYAdCardProtocol.h"
#import "XYAdNativeBannerProtocol.h"

#import "XYAdRewardCallbackProtocol.h"
#import "XYAdBannerProtocol.h"
#import "XYAdInterstitialVideoProtocol.h"

#import "XYAdProducerConfigProtocol.h"
#import "XYAdMediumProtocol.h"

@protocol XYAdBaseDelegate<NSObject>

- (void)onAdInitBefore:(NSString *)producer;
- (void)onAdInitAfter:(NSString *)producer;

- (void)onAdViewClick:(NSString *)adUnitId;
- (void)onVideoAdViewClick:(NSString *)adUnitId;

- (void)fetchNativeAdSuccees:(XYAdModule *)successModule;
- (void)fetchNativeAdFailed:(XYAdModule *)failedModule error:(NSError *)error;
- (void)onNativeAdWillImpression:(NSString *)adsId;

- (void)onRewardValidationFailed:(XYAdModule *)response error:(NSError *)error;
- (void)onRewardValidationSuccess:(XYAdModule *)response;
- (void)onRewardAdClose:(NSString *)adsId;
- (void)onRewardVideoDidStartPlay:(NSString *)adsId;
- (void)onRewardVideoDidEndPlay:(NSString *)adsId;
- (void)onRewardAdShown:(NSString *)adsId;
- (void)onRewardAdResult:(NSString *)adsId producer:(NSString *)producer isRewarded:(BOOL)isRewarded;

- (void)onIntertitialAdLoaded:(XYAdModule *)adModule isSuccess:(BOOL)success;
- (void)onIntertitialAdShown:(XYAdModule *)adModule isSuccess:(BOOL)success;
- (void)onIntertitialAdClicked:(XYAdModule *)adModule;
- (void)onIntertitialAdClosed:(XYAdModule *)adModule hasClicked:(BOOL)hasClicked;

- (void)onCardAdDidLoaded:(XYAdModule *)adModule isSuccess:(BOOL)success;
- (void)onCardAdDidShown:(XYAdModule *)adModule isSuccess:(BOOL)success;
- (void)onCardAdDidStartPlay:(XYAdModule *)adModule;
- (void)onCardAdDidEndPlay:(XYAdModule *)adModule;
- (void)onCardAdClicked:(XYAdModule *)adModule;

@end

@interface XYAdBase : NSObject <XYAdsFetchProtocol, XYAdIntertitialProtocol, XYAdCardProtocol, XYAdNativeBannerProtocol, XYAdBannerProtocol, XYAdInterstitialVideoProtocol, XYAdMediumProtocol>

@property (nonatomic, weak) id <XYAdBaseDelegate,XYAdProducerConfigProtocol> delegate;
@property (nonatomic, weak) id <XYAdRewardCallbackProtocol> rewardAdDelegate;
@property (nonatomic, assign) BOOL           isLoading;
@property (nonatomic, assign) BOOL           isLoadingReward;
@property (nonatomic, strong) NSMutableArray *todoList;
@property (nonatomic, strong) NSMutableArray *todoRewardList;
@property (nonatomic, strong) NSString       *currentAdsPlacement;
@property (nonatomic, copy  ) NSString       *adProducer;
@property (nonatomic, assign) NSInteger     adProducerType;
@property (nonatomic, assign) NSTimeInterval adStartProcessTime;
@property (nonatomic, copy)   NSString      *adRewardPlacementId;

@property (nonatomic, strong) XYAdModule     *cardAdModule;
@property (nonatomic, strong) XYAdModule     *intertitialAdModule;
@property (nonatomic, assign) BOOL           isIntertitialAdClicked; //用于判断:用户主动关闭插屏广告

@property (nonatomic, assign) BOOL           isAuthorized;
@property (nonatomic, copy) XYAdFetchResultBlock nativeResultBlock;
@property (nonatomic, copy) XYAdFetchResultBlock rewardResultBlock;
@property (nonatomic, copy) XYAdFetchResultBlock interstitialResultBlock;

- (void)fetchNativeAdsByTodoAdModule:(XYAdModule *)toDoAdModule;
- (void)notifyFetchNativeAdFailed:(XYAdModule *)failedModule error:(NSError *)error;
- (void)notifyFetchNativeAdSuccees:(XYAdModule *)successModule;
- (void)notifyNativeAdWillImpression:(NSString *)adsId;

- (void)downloadAndCacheImage:(NSURL *)url;
- (void)downloadAndCacheVideo:(NSURL *)url;
- (BOOL)isVideoCached:(XYAdModule *)adModule;

- (void)rewardValidationFailed:(XYAdModule *)response error:(NSError *)error;
- (void)rewardValidationSuccess:(XYAdModule *)response;
- (void)rewardAdClose:(NSString *)adsId;
- (void)rewardVideoDidStartPlay:(NSString *)adsId;
- (void)rewardVideoDidEndPlay:(NSString *)adsId;
- (void)rewardAdShown:(NSString *)adsId;
- (void)rewardAdResult:(NSString *)adsId isRewarded:(BOOL)isRewarded;

- (NSString *)identifierForAdvertising;
- (NSDictionary *)parseUrlParams:(NSString *)urlString;

- (UIViewController *) getVisibleViewControllerFrom:(UIViewController *) vc;
- (UIViewController *) getTopMostViewController;

+ (void)authorizationBeforeInitialize:(BOOL)authorization;
- (void)preloadRewardedVideo:(XYAdModule *)toDoAdModule;
- (void)fetchInterstitialAdWithPlacementID:(NSString *)placementID andPlacement:(NSString *)placement from:(NSString *)from;
- (void)fetchInterstitialAd:(XYAdModule *)adModule from:(NSString *)from;
@end
