//
//  NSData+XYMD5.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (XYMD5)

/// 获取对应的MD5
/// @return MD5字符串
- (nullable NSString *)xy_MD5String;

@end

NS_ASSUME_NONNULL_END
