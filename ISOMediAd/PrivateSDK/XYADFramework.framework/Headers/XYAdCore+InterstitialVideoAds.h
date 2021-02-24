//
//  XYAdCore+InterstitialVideoAds.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/7/22.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (InterstitialVideoAds)

- (void)xyAdCore_fetchInterstitialVideoAdsByPlacement:(NSString *)placement
                                            producers:(NSArray <NSString *>*)producers
                                               adType:(XYAdType)type
                                      adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                       viewController:(UIViewController *)viewController
                                                 from:(NSString *)from
                                                block:(XYAdFetchResultBlock)block;


- (BOOL)showInterstitialVideoAdsByPlacement:(NSString *)placement
                                  producers:(NSArray <NSString *>*)producers
                                     adType:(XYAdType)type
                             viewController:(UIViewController *)controller
                                       from:(NSString *)from;

@end

NS_ASSUME_NONNULL_END
