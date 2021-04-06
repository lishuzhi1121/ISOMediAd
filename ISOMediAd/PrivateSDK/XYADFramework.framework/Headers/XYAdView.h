//
//  XYAdView.h
//  XYAdSDK
//
//  Created by xuxinyuan on 11/28/15.
//  Copyright © 2015 QuVideo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XYAdModule.h"

@interface XYAdView : UIView

/// 广告数据对象
@property (nonatomic, strong) XYAdModule *xyAdsModule;

/// 展示广告的容器（列表中一般为cell的contentView）
@property (nonatomic, strong) UIView *adContainerView;

/// 展示广告的容器的大小（列表中一般为cell的contentView.bounds.size）
@property (nonatomic, assign) CGSize adContainerViewSize;

/// 广告的mediaView（图片/视频）的容器
@property (nonatomic, strong) UIView *adMediaViewContainer;

/// 广告的标语（headline、title）
@property (nonatomic, strong) UILabel *titleLabel;

/// 广告的描述(bodyText)
@property (nonatomic, strong) UILabel *subTitleLabel;

/// 广告的actionButton
@property (nonatomic, strong) UIButton *actionButton;

/// 广告的actionLabel
@property (nonatomic, strong) UILabel *actionLabel;

/// 广告素材视图背景颜色(仅作用于Admob)
@property (nonatomic, strong) UIColor *adMediaViewBackgroundColor;

@property (nonatomic, strong) UIImageView *adCoverImageView;
@property (nonatomic, strong) UIImageView *adLogoImageView;
@property (nonatomic, strong) UILabel *adLabel;

@property (nonatomic, assign) BOOL hasAddGesture;

- (void)loadAdModule:(XYAdModule *)module;
+ (CGFloat)calculateAdViewHeight:(CGFloat)width;

@end
