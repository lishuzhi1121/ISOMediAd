//
//  XYAdCore+RewardAds.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/8/29.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (RewardAds)

- (void)xyAdCore_preloadRewardAdsByPlacement:(NSString *)placement
                                   producers:(NSArray <NSString *>*)producers
                                      adType:(XYAdType)type
                             adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                        from:(NSString *)from
                                       block:(XYAdFetchResultBlock)block;

@end

NS_ASSUME_NONNULL_END
