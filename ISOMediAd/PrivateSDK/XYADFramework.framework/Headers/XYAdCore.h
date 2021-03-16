//
//  XYAdCore.h
//  AFNetworking
//
//  Created by Frenzy Feng on 2018/8/6.
//

#import <Foundation/Foundation.h>
#import "XYAdKitConfigDef.h"
#import "XYAdModule.h"
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdCoreDelegate <NSObject>
@optional
- (void)xyAdCallback_adInitBefore:(NSString *)producer;
- (void)xyAdCallback_adInitAfter:(NSString *)producer;
- (void)xyAdCallback_adClosed:(XYAdModule *)adModule
                         type:(XYAdType)type
                    placement:(NSString *)placement
                 withoutClick:(BOOL)withoutClick;
@end

@class XYAdView;
@class XYAdCache;
@class XYAdFetchCache;
@class XYAdEngineConfiguration;
@class XYAdObserveHandler;
@class XYAdProducerConfigModel;
@protocol XYAdsFetchProtocol;
@protocol XYAdRewardCallbackProtocol;
@protocol XYAdNativeBannerCallbackProtocol;

@interface XYAdCore : NSObject

#pragma mark - 属性
@property (nonatomic, weak) id<XYAdCoreDelegate> delegate;
@property (nonatomic, weak) id<XYAdRewardCallbackProtocol> rewardAdDelegate;
@property (nonatomic, weak) id<XYAdNativeBannerCallbackProtocol> nativeBannerAdDelegate;
@property (nonatomic, strong, readonly) NSMutableArray <id <XYAdsFetchProtocol> > *producers;
@property (nonatomic, strong, readonly) XYAdCache *adEngineCache;
@property (nonatomic, strong, readonly) XYAdFetchCache *adFetchCache;
@property (nonatomic, strong, readonly) XYAdEngineConfiguration *engineConfigutation;
@property (nonatomic, strong, readonly) XYAdObserveHandler *adObserveHandler;

@property (nonatomic, strong) NSMutableDictionary *fetchStrategyDict;

#pragma mark - 初始化
+ (instancetype)core;

/*
 *  初始化 & 授权
 */
- (void)adCore_InitAdEngine:(NSString *)authorization
      adProducerConfigModel:(XYAdProducerConfigModel *)adProducerConfigModel;
- (void)adCore_InitAdEngine:(NSString *)authorization;
- (void)adCore_InitAdEngine:(NSString *)authorization producersDict:(NSDictionary *)dict;
- (void)adCore_AuthorizationAdEngine:(NSString *)authorization;
- (void)adCore_InitEngineConfigutation:(NSDictionary *)defList;

#pragma mark - 广告接口
/*
 *  请求广告
 */
- (BOOL)fetchAdsByPlacement:(NSString *)placement
                  producers:(NSArray<NSString *> *)producers
                     adType:(XYAdType)type
                    adCount:(NSInteger)count
             viewController:(UIViewController *)viewController
                       from:(NSString *)from;

- (BOOL)xyAdCore_fetchAdsByPlacement:(NSString *)placement
                           producers:(NSArray<NSString *> *)producers
                              adType:(XYAdType)type
                     adFetchStrategy:(XYAdFetchStrategyType)fetchStrategy
                             adCount:(NSInteger)count
                      viewController:(UIViewController *)viewController
                                from:(NSString *)from
                               block:(XYAdFetchResultBlock)block;
// banner
- (BOOL)xyAdCore_fetchAdsByPlacement:(NSString *)placement
                           producers:(NSArray<NSString *> *)producers
                              adType:(XYAdType)type
                              adSize:(CGSize)adSize
                     adFetchStrategy:(XYAdFetchStrategyType)fetchStrategy
                             adCount:(NSInteger)count
                      viewController:(UIViewController *)viewController
                                from:(NSString *)from
                               block:(XYAdFetchResultBlock)block;

/*
 *  请求view广告
 */
// splash
- (UIView *)xyAdCore_fetchAdsViewByPlacement:(NSString *)placement
                                   producers:(NSArray<NSString *> *)producers
                                      adType:(XYAdType)type
                                      adFrame:(CGRect)adFrame
                              viewController:(UIViewController *)controller
                                        from:(NSString *)from
                                      result:(XYAdRequestResult)result;
/*
 *  是否配置了view广告，并且广告商已支持
 */
- (BOOL)xyAdCore_hasAdsViewByPlacement:(NSString *)placement
                             producers:(NSArray<NSString *> *)producers
                                adType:(XYAdType)type;

/*
 *  获取广告对象
 */
- (XYAdModule *)loadAdsByPlacement:(NSString *)placement
                         producers:(NSArray<NSString *> *)producers
                            adType:(XYAdType)type
                    viewController:(UIViewController *)viewController
                              from:(NSString *)from
                             delay:(NSInteger)delay;

- (XYAdModule *)xy_loadAdsByPlacement:(NSString *)placement
                            producers:(NSArray<NSString *> *)producers
                               adType:(XYAdType)type
                  adFetchStrategyType:(XYAdFetchStrategyType)fetchStrategyType
                       viewController:(UIViewController *)viewController
                                 from:(NSString *)from
                                delay:(NSInteger)delay;

/*
 *  展示广告
 */
- (BOOL)showAdsByPlacement:(NSString *)placement
                 producers:(NSArray<NSString *> *)producers
                    adType:(XYAdType)type
            viewController:(UIViewController *)viewController
                      from:(NSString *)from;

- (BOOL)showAdsByPlacement:(NSString *)placement
                 producers:(NSArray <NSString *>*)producers
                    adType:(XYAdType)type
            viewController:(UIViewController *)controller
                customView:(nullable UIView *)customView
                      from:(NSString *)from;

/*
 *  预加载广告
 */
- (void)preloadAdsByPlacement:(NSString *)placement
                   producers:(NSArray<NSString *> *)producers
                      adType:(XYAdType)type
                        from:(NSString *)from;

- (void)xy_preloadAdsByPlacement:(NSString *)placement
                       producers:(NSArray<NSString *> *)producers
                          adType:(XYAdType)type
                 adFetchStrategy:(XYAdFetchStrategyType)fetchStrategy
                            from:(NSString *)from;

/*
 *  注册广告View
 */
- (void)xyAdCore_registerAdsView:(XYAdView *)adView
                          adType:(XYAdType)type
                  viewController:(UIViewController *)controller;

- (void)xyAdCore_registerAdsView:(XYAdView *)adView
                          adType:(XYAdType)type
                  viewController:(UIViewController *)controller
                  clickableViews:(nullable NSArray<UIView *> *)clickableViews;

- (void)xyAdCore_registerAdsView:(XYAdView *)adView
                          adType:(XYAdType)type
                  viewController:(UIViewController *)controller
                withoutMediaView:(BOOL)withoutMediaView;

- (void)xyAdCore_registerAdsView:(XYAdView *)adView
                          adType:(XYAdType)type
                  viewController:(UIViewController *)controller
                  clickableViews:(nullable NSArray<UIView *> *)clickableViews
                withoutMediaView:(BOOL)withoutMediaView;

/*
 *  获取广告View
 */
- (UIView *)xyAdCore_getAdsView:(NSString *)placement
                      producers:(NSArray<NSString *> *)producers
                         adType:(XYAdType)type
                         adSize:(CGSize)adSize
                 viewController:(UIViewController *)controller;

/*
 *  广告是否Ready
 */
- (BOOL)isAdReadyForDisplay:(NSString *)placement
                  producers:(NSArray<NSString *> *)producers
                     adType:(XYAdType)type
                       from:(NSString *)from;

- (void)initSpecialAd:(NSString *)producerName;

#pragma mark - Public
/* 视频是否缓存 */
- (BOOL)xyAdCore_isVideoCached:(XYAdModule *)adModule;
- (void)xyAdCore_removeExpiredAdCache:(XYAdModule *)adModule;
- (void)xyAdCore_removeExpiredAdCacheWithPlacement:(NSString *)placement;
- (UIView *)xyAdCore_createMediaView:(XYAdModule *)adsModule frame:(CGRect)frame;
- (NSString *)xyAdCore_debugContext;


- (NSArray<NSString *> *)xyAdCore_defaultProducersByPlacement:(NSString *)placement
                                                       adType:(XYAdType)type;

#pragma mark - AdObserver
/* AdObserver */
- (void)registerAdObserver:(id)observer;
- (void)unregisterAdObserver:(id)observer;

@end

NS_ASSUME_NONNULL_END
