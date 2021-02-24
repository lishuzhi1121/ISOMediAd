//
//  XYAdMediumProtocol.h
//  Pods
//
//  Created by SandsLee on 2020/12/3.
//

#ifndef XYAdMediumProtocol_h
#define XYAdMediumProtocol_h

#import <Foundation/Foundation.h>

@protocol XYAdMediumCallbackProtocol <NSObject>
@optional

- (void)xy_onAdMediumDidLoadSuccess:(XYAdModule *)module;

- (void)xy_onAdMediumDidLoadFail:(XYAdModule *)module error:(NSError *)error;

- (void)xy_onAdMediumWillShow:(XYAdModule *)module;

- (void)xy_onAdMediumDidClick:(XYAdModule *)module;

- (void)xy_onAdMediumDidFinishHandlingClick:(XYAdModule *)module;

- (void)xy_onAdMediumDidClose:(XYAdModule *)module;

@end


@protocol XYAdMediumProtocol <NSObject>

- (BOOL)fetchMediumAd:(XYAdModule *)adModule
               adSize:(CGSize)adSize
           controller:(UIViewController *)controller
                 from:(NSString *)from
             callback:(id<XYAdMediumCallbackProtocol>)callback
               result:(XYAdCoreFetchResultBlock)result;
@end

#endif /* XYAdMediumProtocol_h */
