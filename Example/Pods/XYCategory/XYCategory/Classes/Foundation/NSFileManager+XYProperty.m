//
//  NSFileManager+XYProperty.m
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSFileManager+XYProperty.h"

@implementation NSFileManager (XYProperty)

+ (NSString *)xy_getFileNameFromPath:(NSString *)filePath {
    NSString *fileName = [filePath lastPathComponent];
    return fileName;
}

+ (NSString *)xy_getFileNameNoExtension:(NSString *)filePath {
    NSString *fileName = [[filePath lastPathComponent] stringByDeletingPathExtension];
    return fileName;
}

+ (NSString *)xy_getFileExtensionWithPath:(NSString *)filePath {
    NSString *ext = [filePath pathExtension];
    return ext;
}

+ (unsigned long long)xy_getFileSizeWithPath:(NSString *)filePath {
    NSError * error;
    NSDictionary *fileAttributes =[[NSFileManager defaultManager] attributesOfItemAtPath:filePath error:&error];
    return [fileAttributes fileSize];
}

+ (BOOL)xy_fileExist:(NSString *)filePath {
    NSDictionary *fileDictionary = [[NSFileManager defaultManager] attributesOfItemAtPath:filePath error:nil];
    return [[NSFileManager defaultManager] fileExistsAtPath:filePath] && ([fileDictionary fileSize] != 0);
}

@end
