//
//  NSString+XYURLEncode.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYURLEncode)

/// url编码
- (nullable NSString *)xy_stringByURLEncode;

/// url解码
- (nullable NSString *)xy_stringByURLDecode;

@end

NS_ASSUME_NONNULL_END
