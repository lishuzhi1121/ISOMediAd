//
//  UIButton+XYWebCache.h
//  Pods
//
//  Created by hongru qi on 2017/5/5.
//
//

#import <UIKit/UIKit.h>
#import "XYWebImageDownloader.h"

@interface UIButton (XYWebCache)

- (void)xy_setImageWithURL:(NSURL *)url forState:(UIControlState)state;

- (void)xy_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder;

- (void)xy_setImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state;

- (void)xy_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder;


- (void)xy_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(XYWebImageCompletionBlock)completedBlock;

@end
