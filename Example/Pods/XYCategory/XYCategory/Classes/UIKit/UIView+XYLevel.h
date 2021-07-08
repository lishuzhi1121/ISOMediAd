//
//  UIView+XYLevel.h
//  XYCategory
//
//  Created by robbin on 2019/3/21.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (XYLevel)

@property (nullable, readonly) UIViewController * xy_viewController; /// 当前所属的ViewController
@property (readonly) NSUInteger xy_viewIndex; /// 当前view的次序
@property (readonly) BOOL xy_isInFront; /// 是否是在最前面
@property (readonly) BOOL xy_isAtBack; /// 是否实在最后面


/// 移动到最前面
- (void)xy_bringToFront;

/// 移动到最后面
- (void)xy_sendToBack;

/// 提升一个层级
- (void)xy_bringOneLevelUp;

/// 下降一个层级
- (void)xy_sendOneLevelDown;

/// 是否在某个view前面
/// @param view view
/// @return 是否在某个view前面
- (BOOL)xy_isInFrontOfView:(UIView *)view;

/// 是否在某个view后面
/// @param view view
/// @return 是否在某个view后面
- (BOOL)xy_isAtBackOfView:(UIView *)view;

/// 和某个view交换次序
/// @param swapView view
- (void)xy_swapDepthsWithView:(UIView*)swapView;

/// 移动到某个view前面
/// @param bottomView view
- (void)xy_bringSelfUpToView:(UIView *)bottomView;

/// 移动到某个view后面
/// @param upView view
- (void)xy_sendSelfDownToView:(UIView *)upView;

/// 移除所有的子视图
- (void)xy_removeAllSubviews;

@end

NS_ASSUME_NONNULL_END
