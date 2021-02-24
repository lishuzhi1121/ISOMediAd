//
//  XYAdCore+NativeBanner.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (NativeBanner)

- (BOOL)xyAdCore_fetchNativeBannerAdsByPlacement:(NSString *)placement
                                       producers:(NSArray <NSString *>*)producers
                                          adType:(XYAdType)type
                                 adFetchStrategy:(XYAdFetchStrategyType)fetchStrategy
                                         adCount:(NSInteger)count
                                  viewController:(UIViewController *)viewController
                                            from:(NSString *)from
                                           block:(XYAdFetchResultBlock)block;

- (void)xyAdCore_registerNativeBannerAdsView:(XYAdView *)adView
                                      adType:(XYAdType)type
                              viewController:(UIViewController *)controller
                                        from:(NSString *)from;

@end

NS_ASSUME_NONNULL_END
