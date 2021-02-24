//
//  XYMediEventManager.h
//  XYMediEventAdapter
//
//  Created by robbin on 2020/3/16.
//

#import <Foundation/Foundation.h>
#import "XYMediEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

#define XYMediAppEventSend(EventName, Attribute) [[XYMediEventManager sharedInstance] appEventWithName:EventName attribute:Attribute]

@interface XYMediEventManager : NSObject<XYMediEventProtocol>

@property (nonatomic, weak) id<XYMediEventProtocol> eventAdapter;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
