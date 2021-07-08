//
//  NSFileManager+XYOperate.m
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import "NSFileManager+XYOperate.h"
#import "NSFileManager+XYProperty.h"
#import "NSString+XYEmpty.h"

@implementation NSFileManager (XYOperate)


+ (BOOL)xy_moveFromFile:(NSString *)fromFilePath toFile:(NSString *)toFilePath {
    if(![self xy_fileExist:fromFilePath] || [NSString xy_isEmpty:toFilePath]){
        return NO;
    }
    NSError * error;
    BOOL b = [[NSFileManager defaultManager] moveItemAtPath:fromFilePath toPath:toFilePath error:&error];
    return b;
}

+ (BOOL)xy_copyFromFile:(NSString *)fromFilePath toFile:(NSString *)toFilePath {
    if(![self xy_fileExist:fromFilePath] || [NSString xy_isEmpty:toFilePath]){
        return NO;
    }
    
    return [[NSFileManager defaultManager] copyItemAtPath:fromFilePath toPath:toFilePath error:nil];
}

+ (BOOL)xy_createFolderWithPath:(NSString *)folderPath {
    return [[NSFileManager defaultManager] createDirectoryAtPath:folderPath
                                     withIntermediateDirectories:YES
                                                      attributes:nil
                                                           error:nil];
}

+ (BOOL)xy_deleteFileWithPath:(NSString *)filePath {
    if ([NSString xy_isEmpty:filePath]) {
        return NO;
    }
    
    BOOL res = [[NSFileManager defaultManager] removeItemAtPath:filePath error:nil];
    
    return res;
}

@end
