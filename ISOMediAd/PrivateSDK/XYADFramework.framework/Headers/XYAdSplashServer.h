//
//  XYAdSplashServer.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/9/19.
//

#import "XYAdBaseServer.h"
#import "XYAdSplashProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdSplashServerDelegate <NSObject>

- (void)onSplashAdDidLoadSuccess:(XYAdModule *)module;
- (void)onSplashAdDidLoadFailed:(XYAdModule *)module;
- (void)onSplashAdClick:(XYAdModule *)module;
- (void)onSplashAdWillShow:(XYAdModule *)module;
- (void)onSplashAdDidClose:(XYAdModule *)module;
- (void)onSplashAdWillClose:(XYAdModule *)module;

@end

@interface XYAdSplashServer : XYAdBaseServer <XYAdSplashProtocol>

@property (nonatomic, weak) id<XYAdSplashServerDelegate> delegate;

- (void)xySplashAdDidGetView:(XYAdModule *)module;
- (void)xySplashAdDidLoadSuccess:(XYAdModule *)module;
- (void)xySplashAdDidLoadFailed:(XYAdModule *)module error:(NSError *)error;
- (void)xySplashAdClick:(XYAdModule *)module;
- (void)xySplashAdWillShow:(XYAdModule *)module;
- (void)xySplashAdDidClose:(XYAdModule *)module;
- (void)xySplashAdWillClose:(XYAdModule *)module;

@end

NS_ASSUME_NONNULL_END
