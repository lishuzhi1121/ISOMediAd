//
//  XYAdConfig.h
//  XYAdConfig
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>
#import "XYAdvertiseConfigResponseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdConfig : NSObject

+ (void)requestAdConfig:(NSDate * _Nullable)date
             completion:(void(^ _Nullable)(BOOL success, NSDictionary * _Nullable responseDict))block;

+ (void)requestAdConfig:(NSDate * _Nullable)date
            countryCode:(NSString *_Nullable)countryCode
             completion:(void(^ _Nullable)(BOOL success, NSDictionary * _Nullable responseDict))block;

+ (NSDictionary *)savedAdvertiseConfigResponse;

+ (NSDictionary *)loadSavedYYModelInstanceWithClass:(Class)theClass;

@end

NS_ASSUME_NONNULL_END
