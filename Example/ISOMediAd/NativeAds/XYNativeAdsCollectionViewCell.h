//
//  XYNativeAdsCollectionViewCell.h
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/23.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class XYAdModule;
typedef void(^XYNativeAdRenderBlock)(BOOL success);

@interface XYNativeAdsCollectionViewCell : UICollectionViewCell

- (void)renderWithNativeAd:(XYAdModule *)adModule
                    rootVC:(UIViewController *)rootVC
                completion:(XYNativeAdRenderBlock)completion;

@end

NS_ASSUME_NONNULL_END
