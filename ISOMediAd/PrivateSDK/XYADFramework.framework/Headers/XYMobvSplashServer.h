//
//  XYMobvSplashServer.h
//  XYAdCore
//
//  Created by SandsLee on 2020/12/25.
//

#import "XYAdSplashServer.h"

NS_ASSUME_NONNULL_BEGIN

@class MTGSplashAD;

@interface XYMobvSplashServer : XYAdSplashServer

/// 开屏广告对象
@property (nonatomic, strong) MTGSplashAD * _Nullable mtgSplashAd;

/// 开屏广告获取到的时间(用于计算广告有效时间)
@property (nonatomic, strong) NSDate *receiveDate;

@end

NS_ASSUME_NONNULL_END
