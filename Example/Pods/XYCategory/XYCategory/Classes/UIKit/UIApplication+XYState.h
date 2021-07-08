//
//  UIApplication+XYState.h
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (XYState)

/// 在AppDelegate的didFinishLaunchingWithOptions里运行该方法，
/// 启动监听系统ApplicationState变化，
/// 后续就可以在子线程访问[UIAplication sharedApplication].applicationState
+ (void)xyStartApplicationStateOberver;

@end

NS_ASSUME_NONNULL_END
