//
//  XYAdFetchCache.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"

NS_ASSUME_NONNULL_BEGIN

@class XYAdFetcher;
@interface XYAdFetchCache : NSObject

/* Fetch Cache */
- (void)addAdCache:(XYAdFetcher *)fetcher;
- (void)removeAdCache:(XYAdFetcher *)fetcher;
- (void)removeAdCacheByModule:(XYAdModule *)module;
- (void)removeAdAll;

- (void)removeCache:(NSString *)placement;
- (void)removeCacheWithPlacement:(NSString *)placement producer:(NSString *)producer;

/* Module */

- (void)cleanOldAdCache:(XYAdModule *)adModule;

- (XYAdModule *)getAdModuleById:(NSString *)adsId;
- (XYAdModule *)getAdModuleAtPlacement:(NSString *)adsPlacement adsProducer:(NSString *)adsProducer;
- (NSArray <XYAdModule *>*)getAdModulesAtPlacement:(NSString *)adsPlacement;

- (void)adapterAdModulesInCache:(NSNotification *)notification;
- (void)adapterAdModulesCacheFailed:(NSNotification *)notification;

- (XYAdFetcher *)getAdFetcherByAdModule:(XYAdModule *)adModule;
- (XYAdFetcher *)unexpiredAdFetcherAtPlacement:(NSString *)placement producer:(NSString *)producer;
- (XYAdModule *)unexpiredAdModuleAtPlacement:(NSString *)placement producer:(NSString *)producer;
- (XYAdModule *)handleAdDelayLogicWithCachedAdMdoule:(XYAdModule *)cachedAdMdoule;

@end

NS_ASSUME_NONNULL_END
