//
//  NSFileManager+XYProperty.h
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (XYProperty)

/// 根据文件路径获取文件名字
/// @param filePath 文件路径
/// @return 文件名
+ (NSString *)xy_getFileNameFromPath:(NSString *)filePath;

/// 根据文件路径获取不带扩展的文件名字
/// @param filePath 文件路径
/// @return 不带扩展的文件名
+ (NSString *)xy_getFileNameNoExtension:(NSString *)filePath;

/// 根据文件路径获取扩展
/// @param filePath 文件路径
/// @return 扩展名
+ (NSString *)xy_getFileExtensionWithPath:(NSString *)filePath;

/// 获取文件大小
/// @param filePath 文件路径
/// @return 文件大小
+ (unsigned long long)xy_getFileSizeWithPath:(NSString *)filePath;

/// 判断文件是否存在
/// @param filePath 文件路径
/// @return 文件是否存在
+ (BOOL)xy_fileExist:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END
