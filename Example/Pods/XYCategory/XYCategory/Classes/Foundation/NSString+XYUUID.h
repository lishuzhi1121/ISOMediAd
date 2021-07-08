//
//  NSString+XYUUID.h
//  XYCategory
//
//  Created by robbin on 2019/6/24.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYUUID)

/// 获取一个新的UUID
+ (NSString *)xy_UUIDString;

@end

NS_ASSUME_NONNULL_END
