//
//  NSData+XYString.m
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSData+XYString.h"

@implementation NSData (XYString)

- (NSString *)xy_UTF8String {
    if (self.length > 0) {
        return [[NSString alloc] initWithData:self encoding:NSUTF8StringEncoding];
    }
    return @"";
}


@end
