//
//  UIApplication+XYAppInfo.m
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "UIApplication+XYAppInfo.h"

@implementation UIApplication (XYAppInfo)

- (NSString *)xy_appName {
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"] copy];
}

- (NSString *)xy_appVersion {
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"] copy];
}

- (NSString *)xy_appBuildVersion {
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"] copy];
}

@end
