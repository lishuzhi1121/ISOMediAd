//
//  XYAdCore+MREC.h
//  XYAdCore
//
//  Created by SandsLee on 2020/12/3.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (MREC)

- (BOOL)xyAdCore_fetchMediumAdsByPlacement:(NSString *)placement
                                 producers:(NSArray <NSString *>*)producers
                                    adType:(XYAdType)type
                                    adSize:(CGSize)adSize
                           adFetchStrategy:(XYAdFetchStrategyType)fetchStrategyType
                                   adCount:(NSInteger)count
                            viewController:(UIViewController *)viewController
                                      from:(NSString *)from
                                     block:(XYAdFetchResultBlock)block;

- (XYAdModule *)xyAdCore_getAdMedium:(NSString *)placement
                           producers:(NSArray <NSString *>*)producers;

- (UIView *)xyAdCore_getAdMediumView:(NSString *)placement
                           producers:(NSArray <NSString *>*)producers;

@end

NS_ASSUME_NONNULL_END
