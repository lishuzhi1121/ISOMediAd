//
//  XYAdNativeBannerCallbackProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdNativeBannerCallbackProtocol <NSObject>

- (void)xy_onNativeBannerAdDidLoad:(XYAdModule *)module;

- (void)xy_onNativeBannerAdDidFail:(XYAdModule *)module error:(NSError *)error;

- (void)xy_onNativeBannerAdWillShow:(XYAdModule *)module;

- (void)xy_onNativeBannerAdDidClick:(XYAdModule *)module;

- (void)xy_onNativeBannerAdDidFinishHandlingClick:(XYAdModule *)module;

@end

NS_ASSUME_NONNULL_END
