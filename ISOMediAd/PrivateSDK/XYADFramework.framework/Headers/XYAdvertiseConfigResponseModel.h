//
//  XYAdvertiseConfigResponseModel.h
//  XYCommonAPIManager
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>
#import "XYCommonModel.h"
#import "XYAdvertiseConfigDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdvertiseConfigResponseModel : XYCommonModel

@property (nonatomic, assign) NSInteger count;

@property (nonatomic, copy) NSArray<XYAdvertiseConfigDataModel *> *data;

@end

NS_ASSUME_NONNULL_END
