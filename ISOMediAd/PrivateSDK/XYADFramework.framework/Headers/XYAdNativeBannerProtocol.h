//
//  XYAdNativeBannerProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"
#import "XYAdNativeBannerCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdNativeBannerProtocol <NSObject>

- (BOOL)fetchNativeBannerAd:(XYAdModule *)adModule
                 controller:(UIViewController *)controller
                       from:(NSString *)from
                   callback:(id<XYAdNativeBannerCallbackProtocol>)callback
                     result:(XYAdCoreFetchResultBlock)result;

- (void)registerNativeBannerAd:(XYAdModule *)adModule
                        adView:(UIView *)adView
                    controller:(UIViewController *)controller
                          from:(NSString *)from;

@end

NS_ASSUME_NONNULL_END
