//
//  NSObject+XYParameter.m
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSObject+XYParameter.h"
#import <objc/runtime.h>

@implementation NSObject (XYParameter)

- (void)setXy_parameter:(id)object {
    [self willChangeValueForKey:@"xy_parameter"];
    objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_RETAIN);
    [self didChangeValueForKey:@"xy_parameter"];
}
- (id)xy_parameter {
    return objc_getAssociatedObject(self, @selector(setXy_parameter:));
}

@end
