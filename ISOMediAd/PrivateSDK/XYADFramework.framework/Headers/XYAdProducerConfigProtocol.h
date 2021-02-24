//
//  XYAdProducerConfigProtocol.h
//  XYAdCore
//
//  Created by 徐新元 on 2020/3/26.
//

#import <Foundation/Foundation.h>

@class XYAdProducerConfigModel;

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdProducerConfigProtocol <NSObject>

- (XYAdProducerConfigModel *)xyAdProducerConfigModel;

@end

NS_ASSUME_NONNULL_END
