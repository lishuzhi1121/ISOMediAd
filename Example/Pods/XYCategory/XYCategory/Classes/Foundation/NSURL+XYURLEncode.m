//
//  NSURL+XYURLEncode.m
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSURL+XYURLEncode.h"
#import "NSString+XYURLEncode.h"

@implementation NSURL (XYURLEncode)

- (NSURL *)xy_encode {
    NSString * encodeString = [self.absoluteString xy_stringByURLEncode];
    return [NSURL URLWithString:encodeString];
}

- (NSURL *)xy_decode {
    NSString * encodeString = [self.absoluteString xy_stringByURLDecode];
    return [NSURL URLWithString:encodeString];
}

@end
