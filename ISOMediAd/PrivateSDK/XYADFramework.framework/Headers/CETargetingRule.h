//
//  CETargetingRule.h
//  crystalsdk
//
//  Created by 鄭岳弘 on 2018/3/14.
//  Copyright © 2018年 intowow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CETargetingRule : NSObject
- (void)equalObject:(NSObject *)object;
- (void)equalObjects:(NSObject *)firstObject, ... NS_REQUIRES_NIL_TERMINATION;
- (NSSet<NSString *> *)compileToTagWithKey:(NSString *)key;
@end
