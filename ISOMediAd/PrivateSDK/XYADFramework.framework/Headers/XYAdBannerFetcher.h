//
//  XYAdBannerFetcher.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/1/14.
//

#import "XYAdFetcher.h"
#import "XYAdFetchBannerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdBannerFetcher : XYAdFetcher <XYAdFetchBannerProtocol>

@property (nonatomic, strong) UIView *adBannerView;

/*
 * 创建对应广告商Fetcher
 */
+ (instancetype)fetcherWithType:(NSInteger)type;

@end

NS_ASSUME_NONNULL_END
