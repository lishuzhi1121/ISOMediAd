//
//  NSArray+XYDataSafeTransform.h
//  XYCategory
//
//  Created by 林冰杰 on 2019/7/18.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (XYDataSafeTransform)

/// 获取字符串
/// @param index 下标
/// @return 字符串
- (nullable NSString *)xyStringAtIndex:(NSInteger)index;

/// 获取包装类
/// @param index 下标
/// @return 包装类
- (nullable NSNumber *)xyNumberAtIndex:(NSInteger)index;

/// 获取字典
/// @param index 下标
/// @return 字典
- (nullable NSDictionary *)xyDictionaryAtIndex:(NSInteger)index;

/// 获取数组
/// @param index 下标
/// @return 数组
- (nullable NSArray *)xyArrayAtIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
