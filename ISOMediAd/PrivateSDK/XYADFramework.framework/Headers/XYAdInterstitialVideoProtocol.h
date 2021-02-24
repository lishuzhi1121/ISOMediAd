//
//  XYAdInterstitialVideoProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/7/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol XYAdInterstitialVideoCallbackProtocol <NSObject>

- (void) onAdInterstitialDidLoadSuccess:(XYAdModule *)module;
- (void) onAdInterstitialVideoLoadSuccess:(XYAdModule *)module;
- (void) onAdInterstitialVideoLoadFail:(XYAdModule *)module error:(NSError *)error;
- (void) onAdInterstitialVideoShowSuccess:(XYAdModule *)module;
- (void) onAdInterstitialVideoShowFail:(XYAdModule *)module error:(NSError *)error;
- (void) onAdInterstitialVideoPlayCompleted:(XYAdModule *)module;
- (void) onAdInterstitialVideoEndCardShowSuccess:(XYAdModule *)module;
- (void) onAdInterstitialVideoAdClick:(XYAdModule *)module;
- (void) onAdInterstitialVideoAdDismissed:(XYAdModule *)module converted:(BOOL)converted;
- (void) onAdInterstitialVideoAdDidClosed:(XYAdModule *)module;

@end

@protocol XYAdInterstitialVideoProtocol <NSObject>

@optional

- (void)fetchInterstitialVideoAd:(XYAdModule *)adModule
                      controller:(UIViewController *)controller
                            from:(NSString *)from
                        callback:(id<XYAdInterstitialVideoCallbackProtocol>)callback
                          result:(XYAdCoreFetchResultBlock)result;

- (BOOL)showInterstitialVideoAd:(XYAdModule *)adModule
                     controller:(UIViewController *)controller
                           from:(NSString *)from
                         result:(XYAdCoreFetchResultBlock)result;

@end

NS_ASSUME_NONNULL_END
