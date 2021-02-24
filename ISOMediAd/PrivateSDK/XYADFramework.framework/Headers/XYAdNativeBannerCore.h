//
//  XYAdNativeBannerCore.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/6.
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class XYAdEngineConfiguration;
@protocol XYAdNativeBannerCallbackProtocol;

@interface XYAdNativeBannerCore : NSObject

@property (nonatomic, weak) XYAdEngineConfiguration *engineConfigutation;

- (instancetype)initWithCallback:(id <XYAdNativeBannerCallbackProtocol>)callback;

- (BOOL)fetchAdsByPlacement:(NSString *)placement
                  producers:(NSArray <NSString *>*)producers
                     adType:(XYAdType)type
            adFetchStrategy:(XYAdFetchStrategyType)fetchStrategy
                    adCount:(NSInteger)count
             viewController:(UIViewController *)viewController
                       from:(NSString *)from
                      block:(XYAdFetchResultBlock)block;

@end

NS_ASSUME_NONNULL_END
