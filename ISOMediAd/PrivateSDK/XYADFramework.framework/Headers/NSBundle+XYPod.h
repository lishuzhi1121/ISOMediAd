//
//  NSBundle+XYPod.h
//  Pods
//
//  Created by terry on 2018/3/7.
//
//

#import <Foundation/Foundation.h>


/**
 获取pod 中的 bundle 抽成pod 库 
 */
@interface NSBundle (XYPod)

+ (NSBundle *)xy_bundleWithName:(NSString *)bundleName;

@end
