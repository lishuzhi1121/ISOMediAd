//
//  NSString+XYMD5.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYMD5)

/// 获取当前文本的MD5
- (nullable NSString *)xy_MD5String;

/// 获取文件的MD5
/// @param filePath 文件路径
/// @return MD5
+ (nullable NSString *)xy_MD5ForFile:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END
