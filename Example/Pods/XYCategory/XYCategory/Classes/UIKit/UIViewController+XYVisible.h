//
//  UIViewController+XYVisible.h
//  XYCategory
//
//  Created by robbin on 2019/8/6.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (XYVisible)

/// 返回当前KeyWindow最顶层的可见ViewController
+ (UIViewController *)xy_topVisibleViewControllerOnKeyWindow;

/// 返回指定Window
/// @param window 最顶层的可见ViewController
+ (UIViewController *)xy_topVisibleViewControllerOnWindow:(UIWindow *)window;

/// 返回最顶层的可见Window
+ (UIWindow *)xy_topFullScreenVisibleWindow;

/// 返回最顶层的可见Window中的最顶层可见ViewController
+ (UIViewController *)xy_topViewControllerOnTopFullScreenVisibleWindow;

@end

NS_ASSUME_NONNULL_END
