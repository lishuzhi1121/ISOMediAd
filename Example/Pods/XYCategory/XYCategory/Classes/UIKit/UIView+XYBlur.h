//
//  UIView+XYBlur.h
//  XYCategory
//
//  Created by robbin on 2019/3/21.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (XYBlur)

/// 获取一个毛玻璃UI
/// @param style 风格
/// @param backgroundColor 背景色
/// @param alpha 透明度
/// @return 毛玻璃UI实例
+ (UIVisualEffectView *)xy_blurViewWithStyle:(UIBlurEffectStyle)style
                             backgroundColor:(UIColor *)backgroundColor
                                       alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
