//
//  NSFileManager+XYOperate.h
//  XYCategory
//
//  Created by robbin on 2019/4/10.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (XYOperate)

/// 移动一个文件
/// @param fromFilePath 原始文件路径
/// @param toFilePath 目标文件路径
/// @return 操作是否成功
+ (BOOL)xy_moveFromFile:(NSString *)fromFilePath toFile:(NSString *)toFilePath;

/// 复制一个文件
/// @param fromFilePath 原始文件路径
/// @param toFilePath 目标文件路径
/// @return 操作是否成功
+ (BOOL)xy_copyFromFile:(NSString *)fromFilePath toFile:(NSString *)toFilePath;

/// 创建目录
/// @param folderPath 目录路径
/// @return 操作是否成功
+ (BOOL)xy_createFolderWithPath:(NSString *)folderPath;

/// 删除文件
/// @param filePath 文件路径
/// @return 操作是否成功
+ (BOOL)xy_deleteFileWithPath:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END
