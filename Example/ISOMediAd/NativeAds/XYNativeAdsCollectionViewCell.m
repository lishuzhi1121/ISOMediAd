//
//  XYNativeAdsCollectionViewCell.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/23.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYNativeAdsCollectionViewCell.h"
#import "UIColor+XYRandom.h"
#import <XYADFramework/XYAdPlatform.h>

@interface XYNativeAdsCollectionViewCell ()

@property (weak, nonatomic) IBOutlet UIView *mediaView;
@property (weak, nonatomic) IBOutlet UILabel *headlineLabel;
@property (weak, nonatomic) IBOutlet UILabel *bodyLabel;
@property (weak, nonatomic) IBOutlet UIButton *actionButton;

@end

@implementation XYNativeAdsCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    self.backgroundColor = [UIColor _randomColor];
    
    // mediaView
    UIView *mediaView = [[UIView alloc] init];
    mediaView.backgroundColor = [UIColor lightGrayColor];
    self.mediaView = mediaView;
    [self addSubview:mediaView];
}

- (void)layoutSubviews {
    [super layoutSubviews];
    
    CGFloat mediaWidth = self.bounds.size.width;
    CGFloat mediaHeight = (self.bounds.size.height - (self.bounds.size.height - CGRectGetMinY(self.headlineLabel.frame))) - 5.0 - 10.0;
    self.mediaView.frame = CGRectMake(0, 16.0, mediaWidth, mediaHeight);
}


- (void)renderWithNativeAd:(XYAdModule *)adModule rootVC:(UIViewController *)rootVC completion:(nonnull XYNativeAdRenderBlock)completion {
    if (self.mediaView.subviews.count > 0) {
        [self.mediaView.subviews enumerateObjectsUsingBlock:^(__kindof UIView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [obj removeFromSuperview];
            obj = nil;
        }];
    }
    
    XYAdView *adView = [[XYAdView alloc] init];
    adView.xyAdsModule = adModule;
    adView.adContainerView = self.contentView;
    adView.adContainerViewSize = self.contentView.bounds.size;
    adView.adMediaViewContainer = self.mediaView;
    adView.titleLabel = self.headlineLabel;
    adView.subTitleLabel = self.bodyLabel;
    adView.actionButton = self.actionButton;

    [[XYAdPlatform sharedInstance] registerNativeAdView:adView viewController:rootVC];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (completion) {
            completion(YES);
        }
    });
    
    /**
     以下是测试代码, 不用关心
     Class _fbMediaViewCls = NSClassFromString(@"FBMediaView");
     SEL _allocSEL = NSSelectorFromString(@"alloc");
     SEL _initWithFrameSEL = NSSelectorFromString(@"initWithFrame:");
     // alloc
     id fbMediaViewAlloc = ((id (*) (id, SEL)) objc_msgSend)(_fbMediaViewCls, _allocSEL);
     // initWithFrame
     id fbMediaView = ((id (*)(id, SEL, CGRect)) objc_msgSend)(fbMediaViewAlloc, _initWithFrameSEL, self.mediaView.bounds);
     [self.mediaView addSubview:fbMediaView];
     
     id nativeAd = adModule.userData;
     SEL _registerSEL = NSSelectorFromString(@"registerViewForInteraction:mediaView:iconView:viewController:");
     ((void (*)(id, SEL, UIView *, UIView *, id, UIViewController *)) objc_msgSend)(nativeAd, _registerSEL, self.contentView, fbMediaView, nil, rootVC);
     
     SEL _headlineSEL = NSSelectorFromString(@"headline");
     id headlineStr = ((id (*)(id, SEL)) objc_msgSend)(nativeAd, _headlineSEL);
     if ([headlineStr isKindOfClass:[NSString class]]) {
         self.headlineLabel.text = headlineStr;
     }
     
     SEL _bodyTextSEL = NSSelectorFromString(@"bodyText");
     id bodyTextStr = ((id (*)(id, SEL)) objc_msgSend)(nativeAd, _bodyTextSEL);
     if ([bodyTextStr isKindOfClass:[NSString class]]) {
         self.bodyLabel.text = bodyTextStr;
     }
     
     SEL _callToActionSEL = NSSelectorFromString(@"callToAction");
     id callToActionStr = ((id (*)(id, SEL)) objc_msgSend)(nativeAd, _callToActionSEL);
     if ([callToActionStr isKindOfClass:[NSString class]]) {
         [self.actionButton setTitle:callToActionStr forState:UIControlStateNormal];
     }
     */
    
}

@end
