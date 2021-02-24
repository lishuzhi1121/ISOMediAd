//
//  XYAdCache.h
//  Pods
//
//  Created by hongru qi on 2016/12/26.
//
//

#import <Foundation/Foundation.h>

@class XYAdModule;

@interface XYAdCache : NSObject

- (void)addAdCache:(XYAdModule *)module;

- (void)removeAdCache:(XYAdModule *)module;

- (void)removeAdAll;

- (XYAdModule *)getAdModuleById:(NSString *)adsId;

- (void)removeCacheWithPlacement:(NSString *)placement producer:(NSString *)producer;

- (void)cleanOldAdCache:(XYAdModule *)adModule;

- (void)adapterAdModulesInCache:(NSNotification *)notification;

- (void)adapterAdModulesCacheFailed:(NSNotification *)notification;

- (NSArray *)getAdModulesAtPlacement:(NSString *)adsPlacement;

- (XYAdModule *)getAdModuleAtPlacement:(NSString *)adsPlacement adsProducer:(NSString *)adsProducer;

- (XYAdModule *)unexpiredAdModuleAtPlacement:(NSString *)placement producer:(NSString *)producer;

- (XYAdModule *)handleAdDelayLogicWithCachedAdMdoule:(XYAdModule *)cachedAdMdoule
                                           placement:(NSString *)placement
                                       producerOrder:(NSArray <NSString *>* _Nonnull) producerOrder
                                               delay:(NSInteger)delay;

- (NSString *)debugContext;

@end
