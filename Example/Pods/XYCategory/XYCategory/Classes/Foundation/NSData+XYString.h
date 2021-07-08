//
//  NSData+XYString.h
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (XYString)

/// Returns string decoded in UTF8.
/// @return utf8字符串
- (nullable NSString *)xy_UTF8String;

@end

NS_ASSUME_NONNULL_END
