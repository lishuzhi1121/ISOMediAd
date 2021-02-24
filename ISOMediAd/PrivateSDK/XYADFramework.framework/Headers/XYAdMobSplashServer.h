//
//  XYAdMobSplashServer.h
//  XYAdCore
//
//  Created by SandsLee on 2020/10/22.
//

#import "XYAdSplashServer.h"

@class GADAppOpenAd;

NS_ASSUME_NONNULL_BEGIN

@interface XYAdMobSplashServer : XYAdSplashServer

/// 开屏广告对象
@property (nonatomic, strong) GADAppOpenAd * _Nullable appOpenAd;

/// 开屏广告获取到的时间(用于计算广告有效时间)
@property (nonatomic, strong) NSDate *receiveDate;

@end

NS_ASSUME_NONNULL_END
