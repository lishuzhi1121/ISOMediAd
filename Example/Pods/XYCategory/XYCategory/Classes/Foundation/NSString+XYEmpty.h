//
//  NSString+XYEmpty.h
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYEmpty)

/// 字符串是否不为空
@property (readonly) BOOL xy_isNotEmpty;

/// 字符串是否为空
/// @param string 字符串
/// @return 是否为空
+ (BOOL)xy_isEmpty:(nullable NSString *)string;

@end

NS_ASSUME_NONNULL_END
