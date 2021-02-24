//
//  XYAdMobvista.h
//  Pods
//
//  Created by hongru qi on 2017/1/3.
//
//

#import "XYAdBase.h"
#import "XYAdsFetchProtocol.h"
#import "XYAdSplashProtocol.h"

@class XYMobvSplashServer;

@interface XYAdMobvista : XYAdBase<XYAdsFetchProtocol, XYAdSplashProtocol>

@property (nonatomic, strong) XYMobvSplashServer *mobvSplashServer;

@end
