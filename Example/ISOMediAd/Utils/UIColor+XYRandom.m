//
//  UIColor+XYRandom.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/22.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "UIColor+XYRandom.h"

@implementation UIColor (XYRandom)

+ (instancetype)_randomColor {
    CGFloat r = arc4random_uniform(255) / 255.0;
    CGFloat g = arc4random_uniform(255) / 255.0;
    CGFloat b = arc4random_uniform(255) / 255.0;
    return [UIColor colorWithRed:r green:g blue:b alpha:1.0];
}

@end
