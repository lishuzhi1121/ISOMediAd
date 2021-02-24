//
//  XYAdVungleBannerContainer.h
//  XYAdCore
//
//  Created by SandsLee on 2020/12/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYAdVungleBannerContainer : UIView

/// 根据Vungle banner 尺寸大小创建容器视图
/// @param vungleAdSize banner尺寸大小枚举值
- (instancetype)initWithVungleAdSize:(NSInteger)vungleAdSize;

@end

NS_ASSUME_NONNULL_END
