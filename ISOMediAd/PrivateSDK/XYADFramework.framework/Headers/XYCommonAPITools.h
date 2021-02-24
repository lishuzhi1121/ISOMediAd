//
//  XYCommonAPITools.h
//  Pods
//
//  Created by lizitao on 2019/8/20.
//

#import <Foundation/Foundation.h>

#define XYObtainSafeStringValue(obj)   [NSString stringWithFormat:@"%@",obj];

NS_ASSUME_NONNULL_BEGIN

@interface XYCommonAPITools : NSObject

+ (void)saveValueToCache:(id)object forKey:(NSString *)key;

+ (id)valueForKey:(NSString *)key;

+ (BOOL)isInternal;

+ (NSString *)obtainParamSign:(NSDictionary *)dict httpMethod:(NSString *)httpMethod;

+ (NSDictionary *)dictionaryWithModel:(id)model;

+ (NSString *)simCardCountryCode;

+ (NSString *)zoneNameWithCountryCode:(NSString *)countryCode;

@end

NS_ASSUME_NONNULL_END
