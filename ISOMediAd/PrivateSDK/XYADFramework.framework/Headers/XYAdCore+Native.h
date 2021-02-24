//
//  XYAdCore+Native.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/9.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (Native)

- (void)xyAdCore_fetchNativeAdsByPlacement:(NSString *)placement
                                 producers:(NSArray <NSString *>*)producers
                                    adType:(XYAdType)type
                           adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                   adCount:(NSInteger)count
                            viewController:(UIViewController *)viewController
                                      from:(NSString *)from
                                     block:(XYAdFetchResultBlock)block;

+ (BOOL)isRatioSquareNativeAd:(XYAdModule *)mudule;
@end

NS_ASSUME_NONNULL_END
