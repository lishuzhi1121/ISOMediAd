//
//  XYAdCore+InterstitialAds.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/8/29.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (InterstitialAds)

- (void)xyAdCore_fetchInterstitialAdsByPlacement:(NSString *)placement
                                       producers:(NSArray <NSString *>*)producers
                                          adType:(XYAdType)type
                                 adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                         adCount:(NSInteger)count
                                  viewController:(UIViewController *)viewController
                                            from:(NSString *)from
                                           block:(XYAdFetchResultBlock)block;

@end

NS_ASSUME_NONNULL_END
