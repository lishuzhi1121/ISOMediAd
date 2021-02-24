//
//  XYCommonParamsModel.h
//  XYCommonAPIManager
//
//  Created by lizitao on 2019/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYCommonParamsModel : NSObject
//appkey
@property (nonatomic, copy) NSString *appKey;
//产品ID
@property (nonatomic, assign) NSUInteger productId;
//设备唯一识别码
@property (nonatomic, copy) NSString *device;
//用户唯一标识码
@property (nonatomic, copy) NSString *user;

@end

NS_ASSUME_NONNULL_END
