//
//  UIImage+XYInit.h
//  XYCategory
//
//  Created by robbin on 2019/6/20.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (XYInit)

/// 从bundle中获取指定图片
/// @param imageName 图片名字
/// @param bundleName bundle名字
/// @return 图片
+ (nullable UIImage *)xy_imageWithName:(NSString *)imageName bundleName:(NSString *)bundleName;

@end

NS_ASSUME_NONNULL_END
