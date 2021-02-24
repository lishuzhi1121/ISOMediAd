//
//  XYAdFetcher.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"
#import "XYAdFetcherProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdFetcher : NSObject <XYAdFetcherProtocol>

@property (nonatomic, weak  ) id                   delegate;
@property (nonatomic, strong) XYAdModule           * adModule;
@property (nonatomic, strong) NSString            * fromTag;
@property (nonatomic, assign) XYAdFetchStatus      adFetchStatus;
@property (nonatomic, copy  ) XYAdCoreFetchResultBlock adResultBlock;

@property (nonatomic, assign) BOOL           isAuthorized;

+ (instancetype)fetcherWithType:(XYAdProducers)type;

@end

NS_ASSUME_NONNULL_END
