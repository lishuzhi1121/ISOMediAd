//
//  XYAdEngineConfiguration.h
//  Pods
//
//  Created by hongru qi on 2016/12/24.
//
//

#import <Foundation/Foundation.h>

@interface XYAdEngineConfiguration : NSObject

- (NSInteger)adsCacheFlagByPlacement:(NSString *)placement;
- (void)setConfiguration:(NSDictionary *)defList;
- (NSInteger)adsImpressionIntervalByPlacement:(NSString *)placement;
- (NSString *)adsIdByPlacement:(NSString *)placement producer:(NSString *)producer type:(NSString *)type;
- (NSString *)placementByAdsId:(NSString *)adsId;

- (NSArray <NSString *>* _Nonnull)producersByPlacement:(NSString * _Nonnull)placement type:(NSString *)type;

@end
