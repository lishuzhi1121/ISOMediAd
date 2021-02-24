//
//  XYAdCore+Banner.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/1/14.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (Banner)

- (BOOL)xyAdCore_fetchBannerAdsByPlacement:(NSString *)placement
                                 producers:(NSArray <NSString *>*)producers
                                    adType:(XYAdType)type
                                    adSize:(CGSize)adSize
                           adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                   adCount:(NSInteger)count
                            viewController:(UIViewController *)viewController
                                      from:(NSString *)from
                                     block:(XYAdFetchResultBlock)block;


- (XYAdModule *)xyAdCore_getAdBanner:(NSString *)placement
                           producers:(NSArray <NSString *>*)producers;

- (UIView *)xyAdCore_getAdBannerView:(NSString *)placement
                           producers:(NSArray <NSString *>*)producers;

@end

NS_ASSUME_NONNULL_END
