//
//  XYAdFetchBannerProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdFetchBannerProtocol <NSObject>

- (BOOL)fetchBannerAd:(XYAdModule *)adModule
               adSize:(CGSize)adSize
           controller:(UIViewController *)controller
               result:(XYAdCoreFetchResultBlock)result;



- (void)adBannerDidLoadSuccess:(XYAdModule *)module;
- (void)adBannerDidLoadFail:(XYAdModule *)module error:(NSError *)error;
- (void)adBannerWillShow:(XYAdModule *)module;
- (void)adBannerDidClick:(XYAdModule *)module;
- (void)adBannerDidFinishHandlingClick:(XYAdModule *)module;
- (void)adBannerDidClose:(XYAdModule *)module;
    
@end

NS_ASSUME_NONNULL_END
