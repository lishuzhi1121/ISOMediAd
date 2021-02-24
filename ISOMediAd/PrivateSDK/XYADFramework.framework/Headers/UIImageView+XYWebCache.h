//
//  UIImageView+XYWebCache.h
//  Pods
//
//  Created by hongru qi on 2017/5/5.
//
//

#import <UIKit/UIKit.h>
#import "XYWebImageDownloader.h"

#define kXYWebImageNotificationLoadError @"kXYWebImageNotificationLoadError"

@interface UIImageView (XYWebCache)

- (void)xy_setImageWithURL:(NSURL *)url;

- (void)xy_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder;

- (void)xy_setImageWithURL:(NSURL *)url completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_setImageWithURL:(NSURL *)url
          placeholderImage:(UIImage *)placeholder
                 completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_setImageWithURL:(NSURL *)url
          placeholderImage:(UIImage *)placeholder
                 transform:(XYWebImageTransformBlock)transform
                 completed:(XYWebImageCompletionBlock)completedBlock;
@end
