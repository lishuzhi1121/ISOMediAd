//
//  XYAdMediumFetcher.h
//  XYAdCore
//
//  Created by SandsLee on 2020/12/4.
//

#import "XYAdFetcher.h"
#import "XYAdFetchMediumProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdMediumFetcher : XYAdFetcher <XYAdFetchMediumProtocol>

@property (nonatomic, strong) UIView *adMediumView;

/*
 * 创建对应广告商Fetcher
 */
+ (instancetype)fetcherWithType:(NSInteger)type;

@end

NS_ASSUME_NONNULL_END
