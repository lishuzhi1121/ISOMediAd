//
//  NSDictionary+XYDataSafeTransform.h
//  XYCategory
//
//  Created by 林冰杰 on 2019/7/18.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (XYDataSafeTransform)

/// 获取字符串
/// @param key key
/// @return 字符串
- (nullable NSString *)xyStringForKey:(id)key;

/// 获取包装类
/// @param key key
/// @return 包装类
- (nullable NSNumber *)xyNumberForKey:(id)key;

/// 获取字典
/// @param key key
/// @return 字典
- (nullable NSDictionary *)xyDictionaryForKey:(id)key;

/// 获取数组
/// @param key key
/// @return 数组
- (nullable NSArray *)xyArrayForKey:(id)key;

@end

NS_ASSUME_NONNULL_END
