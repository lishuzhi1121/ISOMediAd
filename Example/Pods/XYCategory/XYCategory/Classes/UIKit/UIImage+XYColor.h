//
//  UIImage+XYColor.h
//  XYCategory
//
//  Created by robbin on 2019/3/21.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (XYColor)

/**
 Create and return a pure color image with the given color and size.
 
 @param color  The color.
 @param size   New image's type.
 */
+ (nullable UIImage *)xy_imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 Tint the image in alpha channel with the given color.
 
 @param color  The color.
 */
- (nullable UIImage *)xy_imageByTintColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
