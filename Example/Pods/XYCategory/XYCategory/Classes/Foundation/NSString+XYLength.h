//
//  NSString+XYLength.h
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYLength)

/// 字符个数
@property (readonly) NSUInteger xy_unicodeLength;

@end

NS_ASSUME_NONNULL_END
