//
//  XYMediEventProtocol.h
//  XYMediEventAdapter
//
//  Created by robbin on 2020/3/16.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#ifndef XYMediEventProtocol_h
#define XYMediEventProtocol_h

NS_ASSUME_NONNULL_BEGIN

@import Foundation;

@protocol XYMediEventProtocol <NSObject>

/// 发送业务埋点
/// @param name 埋点名字
/// @param attribute 埋点参数
- (void)appEventWithName:(NSString *)name attribute:(nullable NSDictionary *)attribute;

@end

NS_ASSUME_NONNULL_END

#endif /* XYMediEventProtocol_h */
