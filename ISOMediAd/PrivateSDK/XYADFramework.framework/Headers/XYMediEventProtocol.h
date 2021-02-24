//
//  XYMediEventProtocol.h
//  XYMediEventAdapter
//
//  Created by robbin on 2020/3/16.
//

#ifndef XYMediEventProtocol_h
#define XYMediEventProtocol_h

@import Foundation;

@protocol XYMediEventProtocol <NSObject>

/// 发送业务埋点
/// @param name 埋点名字
/// @param attribute 埋点参数
- (void)appEventWithName:(NSString *)name attribute:(NSDictionary *)attribute;

@end

#endif /* XYMediEventProtocol_h */
