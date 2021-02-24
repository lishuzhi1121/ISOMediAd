//
//  XYAdFetcherProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2019/7/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdFetcherProtocol <NSObject>

- (void)fetchAd:(XYAdModule *)adModule
         result:(XYAdCoreFetchResultBlock)result;

@end

NS_ASSUME_NONNULL_END
