//
//  UIApplication+XYState.m
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "UIApplication+XYState.h"
#import "pthread.h"
#import <objc/runtime.h>

@implementation UIApplication (XYState)

#pragma mark - 关联xyApplicationState对象
- (UIApplicationState)xyApplicationState {
    NSNumber *stateNumber = objc_getAssociatedObject(self, @"xyApplicationState");
    if (!stateNumber) {//刚启动的时候是Inactive的
        return UIApplicationStateInactive;
    }
    return [stateNumber intValue];
}

- (void)setXyApplicationState:(UIApplicationState)state {
    objc_setAssociatedObject(self, @"xyApplicationState", @(state), OBJC_ASSOCIATION_COPY_NONATOMIC);
}

#pragma mark - 监听ApplicationState切换
+ (void)xyStartApplicationStateOberver {
    //启动监听后才会去hook系统的applicationState方法
    Method originalMethod = class_getInstanceMethod([self class], @selector(applicationState));
    Method swizzledMethod = class_getInstanceMethod([self class], @selector(xySwizzledApplicationState));
    method_exchangeImplementations(originalMethod, swizzledMethod);
    
    //监听以下5种状态
    NSArray <NSNotificationName> * notificationNames = @[
        UIApplicationDidEnterBackgroundNotification,
        UIApplicationWillEnterForegroundNotification,
        UIApplicationDidBecomeActiveNotification,
        UIApplicationWillResignActiveNotification,
        UIApplicationWillTerminateNotification
    ];
    
    [notificationNames enumerateObjectsUsingBlock:^(NSNotificationName  _Nonnull name, NSUInteger idx, BOOL * _Nonnull stop) {
        [[NSNotificationCenter defaultCenter] addObserver:[UIApplication sharedApplication]
        selector:@selector(xyOnUpdateApplicationState)
            name:name
          object:nil];
    }];
}

//更新自己另外保存的ApplicationState
- (void)xyOnUpdateApplicationState {
    [self setXyApplicationState:[UIApplication sharedApplication].applicationState];
}

//Hook系统的applicationState方法,返回自己另外保存的可以在子线程访问的xyApplicationState
- (UIApplicationState)xySwizzledApplicationState {
    UIApplicationState realState = [self xySwizzledApplicationState];
    if (pthread_main_np()) {//主线程的话直接走系统原来的方法
        return realState;
    }
    
    UIApplicationState hackState = self.xyApplicationState;
    if (realState != hackState) {
        NSLog(@"不一致");
    }
    
    return hackState;
}

@end
