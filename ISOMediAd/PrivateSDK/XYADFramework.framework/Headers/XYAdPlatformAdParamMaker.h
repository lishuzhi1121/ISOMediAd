//
//  XYAdPlatformAdParamMaker.h
//
//  Created by 徐新元 on 2020/3/18.
//  
//

////链式参数传递工具类
///使用示例：
////如何使用传进来的参数
//- (void)doSomething:(void(^)(XYChainParamMaker *maker))block {
//    XYChainParamMaker *maker = [[XYChainParamMaker alloc] init];
//    if (block) {
//        block(maker);
//    }
//    NSString *demoStringParam = maker.param.demoStringParam;
//    NSInteger demoIntegerParam = maker.param.demoIntegerParam;
//    BOOL demoBOOLParam = maker.param.demoBOOLParam;
//    NSLog(@"demoStringParam = %@,demoIntegerParam = %@, demoBOOLParam=%@",demoStringParam,@(demoIntegerParam),@(demoBOOLParam));
//}
//
////如何传参数
//[self doSomething:^(XYChainParamMaker *maker) {
//    maker.demoIntegerParam(0).demoStringParam(@"ccc").demoBOOLParam(YES);
//}];

#import "XYAdKitConfigDef.h"
@class XYAdPlatformAdParamMakerParam;

@interface XYAdPlatformAdParamMaker : NSObject

@property (nonatomic, strong, readonly) XYAdPlatformAdParamMakerParam *param;

@property (nonatomic, copy, readonly) XYAdPlatformAdParamMaker *(^ placement)(NSString *placement);

@property (nonatomic, copy, readonly) XYAdPlatformAdParamMaker *(^ from)(NSString *from);

@property (nonatomic, copy, readonly) XYAdPlatformAdParamMaker *(^ viewController)(UIViewController *viewController);

@property (nonatomic, copy, readonly) XYAdPlatformAdParamMaker *(^ customView)(UIView *customView);

@property (nonatomic, assign, readonly) XYAdPlatformAdParamMaker *(^ fetchStrategyType)(XYAdFetchStrategyType fetchStrategyType);

@property (nonatomic, assign, readonly) XYAdPlatformAdParamMaker *(^ adSize)(CGSize adSize);

@property (nonatomic, assign, readonly) XYAdPlatformAdParamMaker *(^ adFrame)(CGRect adFrame);

@end


@interface XYAdPlatformAdParamMakerParam : NSObject

@property (nonatomic, copy) NSString *placement;

@property (nonatomic, copy) NSString *from;

@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, weak) UIView *customView;

@property (nonatomic, assign) XYAdFetchStrategyType fetchStrategyType;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, assign) CGRect adFrame;

@end
