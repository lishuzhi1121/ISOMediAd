//
//  NSObject+XYJSON.h
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (XYJSON)

/// 获取json字符串
/// @return json字符串
- (NSString * _Nullable)xy_getJSONString;

/// 获取Foundation对象，例如NSArray和NSDictionary
/// @return NSArray或者NSDictionary
- (id _Nullable)xy_getObjectFromJSONString;

@end

NS_ASSUME_NONNULL_END
