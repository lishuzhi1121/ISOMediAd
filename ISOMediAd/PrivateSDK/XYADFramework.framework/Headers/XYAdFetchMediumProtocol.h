//
//  XYAdFetchMediumProtocol.h
//  Pods
//
//  Created by SandsLee on 2020/12/4.
//

#ifndef XYAdFetchMediumProtocol_h
#define XYAdFetchMediumProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdFetchMediumProtocol <NSObject>

- (BOOL)fetchMediumAd:(XYAdModule *)adModule
               adSize:(CGSize)adSize
           controller:(UIViewController *)controller
               result:(XYAdCoreFetchResultBlock)result;

- (void)adMediumDidLoadSuccess:(XYAdModule *)module;
- (void)adMediumDidLoadFail:(XYAdModule *)module error:(NSError *)error;
- (void)adMediumWillShow:(XYAdModule *)module;
- (void)adMediumDidClick:(XYAdModule *)module;
- (void)adMediumDidFinishHandlingClick:(XYAdModule *)module;
- (void)adMediumDidClose:(XYAdModule *)module;
    
@end

NS_ASSUME_NONNULL_END

#endif /* XYAdFetchMediumProtocol_h */
