//
//  XYMediEventManager.m
//  XYMediEventAdapter
//
//  Created by robbin on 2020/3/16.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "XYMediEventManager.h"

@implementation XYMediEventManager

+ (instancetype)sharedInstance {
    static dispatch_once_t pred;
    static XYMediEventManager *sharedInstance;
    
    dispatch_once(&pred, ^{
        sharedInstance = [[XYMediEventManager alloc] init];
    });
    
    return sharedInstance;
}

- (void)appEventWithName:(NSString *)name attribute:(NSDictionary *)attribute {
    NSAssert(self.eventAdapter, @"必须要设置中台埋点发送代理");
    [self.eventAdapter appEventWithName:name attribute:attribute];
}

@end
