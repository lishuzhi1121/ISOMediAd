//
//  NSBundle+XYInit.h
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (XYInit)

/// 根据名字获取NSBundle
/// @param bundleName 名字
/// @return NSBundle 实例
+ (nullable NSBundle *)xy_bundleWithBundleName:(NSString *)bundleName;

@end

NS_ASSUME_NONNULL_END
