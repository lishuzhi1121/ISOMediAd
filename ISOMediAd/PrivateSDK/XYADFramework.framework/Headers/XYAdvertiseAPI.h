//
//  XYAdvertiseAPI.h
//  XYCommonAPIManager
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>
#import "XYCommonAPIManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdvertiseAPI : NSObject


/// app获取广告配置
/// @param contentParams 目前只有一个国家参数， { "country" : "CN" }
/// @param finished  接口完成回调
+ (void)callAdvertiseConfigAPIWithExtraParams:(NSDictionary *)contentParams
                                     finished:(XYCommonAPICompleteCallback)finished;

@end

NS_ASSUME_NONNULL_END
