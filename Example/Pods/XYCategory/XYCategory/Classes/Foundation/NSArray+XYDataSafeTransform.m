//
//  NSArray+XYDataSafeTransform.m
//  XYCategory
//
//  Created by 林冰杰 on 2019/7/18.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSArray+XYDataSafeTransform.h"

extern id XYContainerConvertorCheckType(id INSTANCE, Class classType);

@implementation NSArray (XYDataSafeTransform)

- (NSString *)xyStringAtIndex:(NSInteger)index {
    return [self.class xyStringWithArray:self atIndex:index];
}

- (NSNumber *)xyNumberAtIndex:(NSInteger)index {
    return [self.class xyNumberWithArray:self atIndex:index];
}

- (NSDictionary *)xyDictionaryAtIndex:(NSInteger)index {
    return [self.class xyDictWithArray:self atIndex:index];
}

- (NSArray *)xyArrayAtIndex:(NSInteger)index {
    return [self.class xyArrayWithArray:self atIndex:index];
}

+ (NSString *)xyStringWithArray:(NSArray *)array atIndex:(NSInteger)index {
    if (index >= [array count]) {
        return nil;
    }
    
    NSString *string = XYContainerConvertorCheckType(array[index], NSString.class);
    if (string) return string;
    NSNumber *number = XYContainerConvertorCheckType(array[index], NSNumber.class);
    if (number) return [NSString stringWithFormat:@"%@", number];
    return nil;
}

+ (NSNumber *)xyNumberWithArray:(NSArray *)array atIndex:(NSInteger)index {
    if (index >= [array count]) {
        return nil;
    }
    
    NSNumber *number = XYContainerConvertorCheckType(array[index], NSNumber.class);
    if (number) return number;
    NSString *string = XYContainerConvertorCheckType(array[index], NSString.class);
    if (string) return @([string intValue]);
    return nil;
}

+ (NSDictionary *)xyDictWithArray:(NSArray *)array atIndex:(NSInteger)index {
    if (index >= [array count]) {
        return nil;
    }
    return XYContainerConvertorCheckType(array[index], NSDictionary.class);
}

+ (NSArray *)xyArrayWithArray:(NSArray *)array atIndex:(NSInteger)index {
    if (index >= [array count]) {
        return nil;
    }
    return XYContainerConvertorCheckType(array[index], NSArray.class);
}

@end
