//
//  XYAdNativeBannerFetcher.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import "XYAdFetcher.h"
#import "XYAdNativeBannerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdNativeBannerFetcher : XYAdFetcher <XYAdNativeBannerProtocol>

- (void)xy_nativeBannerAdDidLoad;

- (void)xy_nativeBannerAdDidFailWithError:(NSError *)error;

- (void)xy_nativeBannerAdWillShow;

- (void)xy_nativeBannerAdDidClick;

- (void)xy_nativeBannerAdDidFinishHandlingClick;

@end

NS_ASSUME_NONNULL_END
