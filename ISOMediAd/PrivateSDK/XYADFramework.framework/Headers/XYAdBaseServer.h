//
//  XYAdBaseServer.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/9/19.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdBaseServer : NSObject

@property (nonatomic, strong) XYAdModule        *adModule;
@property (nonatomic, copy  ) XYAdRequestResult resultBlock;

@property (nonatomic, strong) NSString *strLogPrefix;

@end

NS_ASSUME_NONNULL_END
