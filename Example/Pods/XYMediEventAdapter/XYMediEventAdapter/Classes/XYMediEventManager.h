//
//  XYMediEventManager.h
//  XYMediEventAdapter
//
//  Created by robbin on 2020/3/16.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYMediEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

#define XYMediAppEventSend(EventName, Attribute) [[XYMediEventManager sharedInstance] appEventWithName:EventName attribute:Attribute]

/// 埋点管理类，中台组件依赖并使用这个类发送埋点
@interface XYMediEventManager : NSObject<XYMediEventProtocol>

/// 代理，由外部设置
@property (nonatomic, weak, nullable) id<XYMediEventProtocol> eventAdapter;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
