//
//  NSData+XYBase64.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (XYBase64)

/// 获取base64字符串
/// @return base64字符串
- (nullable NSString *)xy_base64EncodedString;

/// 从base64字符串中获取NSData
/// @param base64EncodedString base64字符串
/// @return NSData实例
+ (nullable NSData *)xy_dataWithBase64EncodedString:(nullable NSString *)base64EncodedString;

@end

NS_ASSUME_NONNULL_END
