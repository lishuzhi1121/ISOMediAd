//
//  UIDevice+XYInfo.h
//  XYCategory
//
//  Created by robbin on 2019/3/25.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (XYInfo)

@property (readonly, nonatomic) NSString * xy_macAddressString; /// mac地址
@property (readonly, nonatomic) NSString * xy_IDFAString; /// 实时获取系统真实IDFA, 获取不到或获取到的IDFA不合法则返回空字符串
@property (readonly, nonatomic) NSString * xy_IDFVString; /// idfv

@property (readonly, nonatomic) BOOL xy_isJailbroken; /// 是否越狱
@property (readonly, nonatomic, nullable) NSString * xy_machineModel; /// 设备型号 iPhone6,2
@property (readonly, nonatomic, nullable) NSString * xy_machineModelName; /// 设备名称 iPhone 5s
@property (readonly, nonatomic) NSString * xy_cellularProvicerName; /// 运营商名字
@property (readonly, nonatomic) BOOL xy_is64Bit; /// 设备是否是64位

//=============================== Disk Space ===========================================

/**
 Total disk space in byte. (-1 when error occurs)
 */
@property (nonatomic, readonly) int64_t xy_diskSpace;

/**
 Free disk space in byte. (-1 when error occurs)
 */
@property (nonatomic, readonly) int64_t xy_diskSpaceFree;

/**
 Used disk space in byte. (-1 when error occurs)
 */
@property (nonatomic, readonly) int64_t xy_diskSpaceUsed;

//=============================== Memory Information ===========================================

/// Total physical memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t xy_memoryTotal;

/// Used (active + inactive + wired) memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t xy_memoryUsed;

/// Free memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t xy_memoryFree;

/// 当前app使用内存
@property (nonatomic, readonly) int64_t xy_weUseMemory;

/// 当前设备型号是否比输入的型号新
/// @param modelName  设备型号，例如：iPhone10,1
/// @return 设备是否更新
- (BOOL)isEqualOrNewerThanModel:(NSString *)modelName;

@end

NS_ASSUME_NONNULL_END
