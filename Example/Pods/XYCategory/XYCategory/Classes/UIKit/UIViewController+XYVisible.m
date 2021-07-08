//
//  UIViewController+XYVisible.m
//  XYCategory
//
//  Created by robbin on 2019/8/6.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "UIViewController+XYVisible.h"

@implementation UIViewController (XYVisible)

+ (UIViewController *)xy_topVisibleViewControllerOnKeyWindow {
    return [self getTopVisibleViewControllerFromViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

+ (UIViewController *)xy_topVisibleViewControllerOnWindow:(UIWindow *)window {
    return [self getTopVisibleViewControllerFromViewController:window.rootViewController];
}

+ (UIViewController *)getTopVisibleViewControllerFromViewController:(UIViewController *)vc {
    if ([vc isKindOfClass:[UINavigationController class]]) {
        return [self getTopVisibleViewControllerFromViewController:[((UINavigationController *) vc) visibleViewController]];
    } else if ([vc isKindOfClass:[UITabBarController class]]) {
        return [self getTopVisibleViewControllerFromViewController:[((UITabBarController *) vc) selectedViewController]];
    } else {
        if (vc.presentedViewController) {
            return [self getTopVisibleViewControllerFromViewController:vc.presentedViewController];
        } else {
            return vc;
        }
    }
}

+ (UIWindow *)xy_topFullScreenVisibleWindow{
    NSArray *windows = [UIApplication sharedApplication].windows;
    for (UIWindow *window in [windows reverseObjectEnumerator]) {
        if ([window isKindOfClass:[UIWindow class]]
            && CGRectEqualToRect(window.bounds, [UIScreen mainScreen].bounds)
            && !window.hidden) {
            return window;
        }
    }
    return [UIApplication sharedApplication].keyWindow;
}

+ (UIViewController *)xy_topViewControllerOnTopFullScreenVisibleWindow {
    UIWindow *window = [UIViewController xy_topFullScreenVisibleWindow];
    return [UIViewController xy_topVisibleViewControllerOnWindow:window];
}


@end
