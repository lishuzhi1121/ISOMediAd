//
//  XYAdConfig.h
//  XYAdConfig
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>
#if __has_include(<XYCommonAPIManager/XYAdvertiseConfigResponseModel.h>)
#import <XYCommonAPIManager/XYAdvertiseConfigResponseModel.h>
#else
#import "XYAdvertiseConfigResponseModel.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface XYAdConfig : NSObject

+ (void)requestAdConfig:(NSDate * _Nullable)date
             completion:(void(^ _Nullable)(BOOL success, NSDictionary * _Nullable responseDict))block;

+ (void)requestAdConfig:(NSDate * _Nullable)date
            countryCode:(NSString *_Nullable)countryCode
             completion:(void(^ _Nullable)(BOOL success, NSDictionary * _Nullable responseDict))block;

+ (NSDictionary *)savedAdvertiseConfigResponseModel;

+ (NSDictionary *)loadSavedYYModelInstanceWithClass:(Class)theClass;

@end

NS_ASSUME_NONNULL_END
