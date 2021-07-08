//
//  UIApplication+XYAppInfo.h
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (XYAppInfo)

@property (readonly, copy) NSString * xy_appName; /// App名字
@property (readonly, copy) NSString * xy_appVersion; /// App版本
@property (readonly, copy) NSString * xy_appBuildVersion; /// build版本号

@end

NS_ASSUME_NONNULL_END
