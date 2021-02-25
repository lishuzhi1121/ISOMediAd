//
//  XYAdsCommonDefine.h
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/24.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#ifndef XYAdsCommonDefine_h
#define XYAdsCommonDefine_h

/// 广告形式枚举
typedef NS_ENUM(NSUInteger, XYAdsDemoAdType) {
    XYAdsDemoAdTypeSplash = 0,
    XYAdsDemoAdTypeBanner,
    XYAdsDemoAdTypeInterstital,
    XYAdsDemoAdTypeReward,
    XYAdsDemoAdTypeNative,
    XYAdsDemoAdTypeInterstitalVideo,
    XYAdsDemoAdTypeVungleMREC,
};

/// 会员状态存储key
static NSString *const VIP_IS_ON_KEY = @"VIP_IS_ON_KEY";


#endif /* XYAdsCommonDefine_h */
