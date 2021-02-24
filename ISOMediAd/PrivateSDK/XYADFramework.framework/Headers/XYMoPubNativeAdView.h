//
//  XYMoPubNativeAdView.h
//  XYAdCore
//
//  Created by SandsLee on 2021/1/5.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class XYAdView;

@interface XYMoPubNativeAdView : UIView

- (instancetype)initWithXYAdView:(XYAdView *)adView;

- (void)refreshSubviewsWithXYAdView:(XYAdView *)adView;

@end

NS_ASSUME_NONNULL_END
