//
//  UIView+XYEasyGradient.h
//  XYCategory
//
//  Created by 徐新元 on 2020/9/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (XYEasyGradient)

@property(nullable, copy) NSArray *xy_colors;

@property(nullable, copy) NSArray<NSNumber *> *xy_locations;

@property CGPoint xy_startPoint;
@property CGPoint xy_endPoint;

+ (UIView *_Nullable)xy_gradientViewWithColors:(NSArray<UIColor *> *_Nullable)colors locations:(NSArray<NSNumber *> *_Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

- (void)xy_setGradientBackgroundWithColors:(NSArray<UIColor *> *_Nullable)colors locations:(NSArray<NSNumber *> *_Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

@end

NS_ASSUME_NONNULL_END
