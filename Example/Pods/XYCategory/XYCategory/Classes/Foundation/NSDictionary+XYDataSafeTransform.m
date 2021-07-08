//
//  NSDictionary+XYContainerConvertor.m
//  XYCategory
//
//  Created by 林冰杰 on 2019/7/18.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSDictionary+XYDataSafeTransform.h"

id XYContainerConvertorCheckType(id INSTANCE, Class classType) {
    if (!INSTANCE) {
        return nil;
    }
    if(![INSTANCE isKindOfClass:classType]) {
        return nil;
    }
    return INSTANCE;
}

@implementation NSDictionary (XYDataSafeTransform)

- (NSString *)xyStringForKey:(id)key {
    return [self.class xyStringWithDictionary:self forKey:key];
}

- (NSNumber *)xyNumberForKey:(id)key {
    return [self.class xyNumberWithDictionary:self forKey:key];
}

- (NSDictionary *)xyDictionaryForKey:(id)key {
    return [self.class xyDictWithDictionary:self forkey:key];
}

- (NSArray *)xyArrayForKey:(id)key {
    return  [self.class xyArrayWithDictionary:self forkey:key];
}

#pragma mark - Dictionary
+ (NSString *)xyStringWithDictionary:(NSDictionary *)dict forKey:(id)key {
    NSString *string = XYContainerConvertorCheckType(dict[key], NSString.class);
    if (string) return string;
    NSNumber *number = XYContainerConvertorCheckType(dict[key], NSNumber.class);
    if (number) return [NSString stringWithFormat:@"%@", number];
    return nil;
}

+ (NSString *)xyNonnullStringWithDictionary:(NSDictionary *)dict forKey:(id)key {
    NSString *string = [self xyStringWithDictionary:dict forKey:key];
    return string? string:@"";
}

+ (NSNumber *)xyNumberWithDictionary:(NSDictionary *)dict forKey:(id)key {
    NSNumber *number = XYContainerConvertorCheckType(dict[key], NSNumber.class);
    if (number) return number;
    NSString *string = XYContainerConvertorCheckType(dict[key], NSString.class);
    if (string) return @([string intValue]);
    return nil;
}

+ (NSDictionary *)xyDictWithDictionary:(NSDictionary *)dict forkey:(id)key {
    return XYContainerConvertorCheckType(dict[key], NSDictionary.class);
}

+ (NSArray *)xyArrayWithDictionary:(NSDictionary *)dict forkey:(id)key {
    return XYContainerConvertorCheckType(dict[key], NSArray.class);
}

@end
