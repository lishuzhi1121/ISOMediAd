//
//  XYAdPlatformConfigResponseModel.h
//  XYCommonAPIManager
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>
#import "XYAdPlatformConfigDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdPlatformConfigResponseModel : NSObject

@property (nonatomic, assign) NSInteger count;

@property (nonatomic, copy) NSArray<XYAdPlatformConfigDataModel *> *data;

@end

NS_ASSUME_NONNULL_END
