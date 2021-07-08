//
//  UIImage+XYInit.m
//  XYCategory
//
//  Created by robbin on 2019/6/20.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "UIImage+XYInit.h"

@implementation UIImage (XYInit)

+ (UIImage *)xy_imageWithName:(NSString *)imageName bundleName:(NSString *)bundleName {
    UIImage *image = [UIImage imageNamed:imageName inBundle:[self xy_bundleWithBundleName:bundleName] compatibleWithTraitCollection:nil];
    if (!image) { // podBundle中无图片 去mainBundle中获取一份
        image = [UIImage imageNamed:imageName];
    }
    return image;
}

+ (NSBundle *)xy_bundleWithBundleName:(NSString * )bundleName
{
    NSBundle *bundle = [NSBundle mainBundle];
    NSString *path = [bundle pathForResource:@"Frameworks" ofType:nil];
    NSString *bundlePath = @"";
    NSBundle *tt_bundle = nil;
    if (!tt_bundle) { // 静态库不会把资源文件达到对应的framework中 寻找的路径需要修改
        bundlePath = [NSString stringWithFormat:@"%@/%@.bundle", [bundle bundlePath], bundleName];
        tt_bundle = [NSBundle bundleWithPath:bundlePath];
    }
    if (!tt_bundle) { // 静态库不会把资源文件达到对应的framework中 寻找的路径需要修改
        bundlePath = [NSString stringWithFormat:@"%@/%@.framework/%@.bundle",path, bundleName, bundleName];
        tt_bundle = [NSBundle bundleWithPath:bundlePath];
    }

    return tt_bundle;
}

@end
