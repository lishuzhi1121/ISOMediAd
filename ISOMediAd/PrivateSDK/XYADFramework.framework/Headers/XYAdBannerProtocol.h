//
//  XYAdBannerProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol XYAdBannerCallbackProtocol <NSObject>

- (void)xy_onAdBannerDidLoadSuccess:(XYAdModule *)module;

- (void)xy_onAdBannerDidLoadFail:(XYAdModule *)module error:(NSError *)error;

- (void)xy_onAdBannerWillShow:(XYAdModule *)module;

- (void)xy_onAdBannerDidClick:(XYAdModule *)module;

- (void)xy_onAdBannerDidFinishHandlingClick:(XYAdModule *)module;

- (void)xy_onAdBannerDidClose:(XYAdModule *)module;

@end

@protocol XYAdBannerProtocol <NSObject>

- (BOOL)fetchBannerAd:(XYAdModule *)adModule
               adSize:(CGSize)adSize
           controller:(UIViewController *)controller
                 from:(NSString *)from
             callback:(id<XYAdBannerCallbackProtocol>)callback
               result:(XYAdCoreFetchResultBlock)result;
@end

NS_ASSUME_NONNULL_END
