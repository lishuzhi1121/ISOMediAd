//
//  XYAdLogTools.h
//  AFNetworking
//
//  Created by Frenzy Feng on 2018/9/27.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"

NS_ASSUME_NONNULL_BEGIN

#define LogAd(a, b) [XYAdCoreTools printAdLog:(a) desc:(b)];
#define LogAdFormat(a, b, c) [XYAdCoreTools printAdLog:(a) desc:([NSString stringWithFormat:b, (c)])];

@interface XYAdCoreTools : NSObject

/* For User Behavior */
+ (NSString *)adToolGetAdProducerName:(XYAdModule *)adModule;
+ (NSString *)adToolGetAdPlacementName:(XYAdModule *)adModule;

/* For Private */
+ (void)printAdLog:(NSString *)subtitle desc:(NSString *)desc;
+ (void)printAdLog:(NSString *)adType desc:(NSString *)desc adModule:(XYAdModule *)adModule;

@end

NS_ASSUME_NONNULL_END
