//
//  NSURL+XYURLEncode.h
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (XYURLEncode)

/// url编码
/// @return 编码后的url对象
- (nullable NSURL *)xy_encode;

/// url解码
/// @return 解码后的url对象
- (nullable NSURL *)xy_decode;

@end

NS_ASSUME_NONNULL_END
