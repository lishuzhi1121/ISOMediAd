//
//  UINib+XYInit.m
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "UINib+XYInit.h"

@implementation UINib (XYInit)

+ (UINib *)xy_nibWithNibName:(NSString *)name bundleName:(NSString * __nullable)bundleName
{
    return [UINib nibWithNibName:name bundle:[self xy_bundleWithBundleName:bundleName]];
}

+ (id)xy_uniqueViewWithNibName:(NSString *)name bundleName:(NSString * __nullable)bundleName
{
    if (name.length <= 0) {
        return nil;
    }
    return [[[UINib xy_nibWithNibName:name bundleName:bundleName] instantiateWithOwner:nil options:nil] lastObject];
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
