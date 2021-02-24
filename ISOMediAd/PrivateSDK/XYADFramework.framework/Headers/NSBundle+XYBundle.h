//
//  NSBundle+XYBundle.h
//  XYBundle
//
//  Created by walter on 30/08/2017.
//

#import <Foundation/Foundation.h>

@interface NSBundle (XYBundle)
+ (NSBundle *)bundleWithPodName:(NSString *)name class:(Class)bundleClass;
@end
