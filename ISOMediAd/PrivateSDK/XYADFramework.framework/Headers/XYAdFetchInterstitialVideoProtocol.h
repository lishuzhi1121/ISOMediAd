//
//  XYAdInterstitialProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdFetchInterstitialVideoProtocol <NSObject>

- (BOOL)fetchInterstitialVideoAd:(XYAdModule *)adModule
                      controller:(UIViewController *)controller
                          result:(XYAdCoreFetchResultBlock)result;


- (BOOL)showInterstitialVideoAd:(XYAdModule *)adModule
                     controller:(UIViewController *)controller;

- (void) adInterstitialDidLoadSuccess:(XYAdModule *)module;
- (void) adInterstitialVideoLoadSuccess:(XYAdModule *)module;
- (void) adInterstitialVideoLoadFail:(XYAdModule *)module error:(NSError *)error;
- (void) adInterstitialVideoShowSuccess:(XYAdModule *)module;
- (void) adInterstitialVideoShowFail:(XYAdModule *)module error:(NSError *)error;
- (void) adInterstitialVideoPlayCompleted:(XYAdModule *)module;
- (void) adInterstitialVideoEndCardShowSuccess:(XYAdModule *)module;
- (void) adInterstitialVideoAdClick:(XYAdModule *)module;
- (void) adInterstitialVideoAdDismissed:(XYAdModule *)module converted:(BOOL)converted;
- (void) adInterstitialVideoAdDidClosed:(XYAdModule *)module;

@end

NS_ASSUME_NONNULL_END
