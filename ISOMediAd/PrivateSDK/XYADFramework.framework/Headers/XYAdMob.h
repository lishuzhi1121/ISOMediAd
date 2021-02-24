//
//  XYAdMob.h
//  XYAdSDK
//
//  Created by 徐新元 on 27/10/2016.
//  Copyright © 2016 QuVideo. All rights reserved.
//

#import "XYAdBase.h"
#import "XYAdProtocol.h"
#import "XYAdsFetchProtocol.h"

@class XYAdMobSplashServer;

@interface XYAdMob : XYAdBase <XYAdProtocol, XYAdsFetchProtocol>

@property(nonatomic ,assign) CGSize adSize;

@property (nonatomic, strong) XYAdMobSplashServer *mobSplashServer;

@end
