//
//  XYAdCore+AdLog.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/8/23.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@class XYAdModule;
@interface XYAdCore (AdLog)

- (void)logAdShow:(XYAdModule *)adModule;
- (void)logAdClick:(XYAdModule *)adModule;
- (void)lodNativeAdWillImpression:(XYAdModule *)adModule;

- (void)logCardAdShow:(XYAdModule *)adModule;

@end

NS_ASSUME_NONNULL_END
