//
//  NSString+XYBase64.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYBase64)

/// 进行base64编码
/// @return base64字符串
- (NSString *)xy_base64EncodedString;

/// 进行base64解码
/// @param base64EncodedString 编码过的字符串
/// @return 原始字符串
+ (NSString *)stringWithBase64EncodedString:(NSString *)base64EncodedString;

@end

NS_ASSUME_NONNULL_END
