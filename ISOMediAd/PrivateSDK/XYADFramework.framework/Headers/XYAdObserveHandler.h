//
//  XYAdObserveHandler.h
//  XYAdSDK
//
//  Created by Frenzy on 9/19/17.
//  Copyright © 2017 QuVideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYAdObserveProtocol.h"

@interface XYAdObserveHandler : NSObject

- (void)registerObserver:(id)observer;
- (void)unregisterObserver:(id)observer;

- (void)notifyObserve:(XYAdObserve)status withAdModule:(XYAdModule *)adModule;

@end
