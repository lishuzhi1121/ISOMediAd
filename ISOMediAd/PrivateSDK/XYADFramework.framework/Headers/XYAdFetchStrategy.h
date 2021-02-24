//
//  XYAdFetchStrategy.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/11/8.
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"
NS_ASSUME_NONNULL_BEGIN

@class XYAdCache;
@class XYAdFetchCache;
@class XYAdEngineConfiguration;
@protocol XYAdsFetchProtocol;

typedef BOOL (^XYAdStrategyInnerBlock)(XYAdFetchStatus status);
typedef void (^XYAdStrategyBlock)(NSString *suitableAdsId,
                                  NSString *producerName,
                                  id <XYAdsFetchProtocol> producer,
                                  XYAdStrategyInnerBlock nextBlock);
typedef void (^XYAdStrategyFinishBlock)(void);

@interface XYAdFetchStrategy : NSObject

@property (nonatomic, strong) NSString * placement;
@property (nonatomic, strong) NSString * adType;
@property (nonatomic, strong) NSMutableArray <NSString *>* producerNames;
@property (nonatomic, weak) NSArray <id <XYAdsFetchProtocol>>* producers;
@property (nonatomic, weak) XYAdEngineConfiguration *engineConfigutation;
@property (nonatomic, weak) XYAdCache *adEngineCache;
@property (nonatomic, weak) XYAdFetchCache *adFetchCache;


+ (instancetype)fetchStrategy:(XYAdFetchStrategyType)type
                       adType:(NSString *)adType
                    placement:(NSString *)placement
                producerNames:(NSArray <NSString *>*)producerNames
                    producers:(NSArray <id <XYAdsFetchProtocol>>*)producers
          engineConfigutation:(XYAdEngineConfiguration *)engineConfigutation;

- (instancetype)initFetchStrategy:(NSString *)placement
                           adType:(NSString *)adType
                    producerNames:(NSArray <NSString *>*)producerNames
                        producers:(NSArray <id <XYAdsFetchProtocol>>*)producers
              engineConfigutation:(XYAdEngineConfiguration *)engineConfigutation;

- (void)doFetchStrategy:(XYAdStrategyBlock)block;
- (void)doFetchStrategy:(XYAdStrategyBlock)block finish:(XYAdStrategyFinishBlock)finishBlock;

- (BOOL)needNext;

@end

NS_ASSUME_NONNULL_END
