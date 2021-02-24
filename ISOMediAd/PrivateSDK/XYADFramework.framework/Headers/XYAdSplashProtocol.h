//
//  XYAdSplashProtocol.h
//  AFNetworking
//
//  Created by Frenzy Feng on 2018/8/17.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdSplashProtocol <NSObject>

@optional

- (UIView *)fetchSplashAdView:(XYAdModule *)adModule
                        frame:(CGRect)frame
               viewController:(UIViewController *)controller
                         from:(NSString *)from
                       result:(XYAdRequestResult)result;
    
- (UIView *)fetchSplashAdView:(XYAdModule *)adsModule
                        frame:(CGRect)frame
               viewController:(UIViewController *)viewController
                         from:(NSString *)from;

- (UIView *)getSplashAdView:(XYAdModule *)adsModule viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
