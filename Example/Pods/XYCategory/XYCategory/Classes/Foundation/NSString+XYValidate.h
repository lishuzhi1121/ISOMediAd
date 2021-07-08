//
//  NSString+XYValidate.h
//  XYCategory
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (XYValidate)

/// 是否是email格式（"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}"）
/// @return 是否是email格式
- (BOOL)xy_isEmailFormat;

/// 是否是手机号格式（"^1+[3578]+\\d{9}"）
/// @return 是否是手机号格式
- (BOOL)xy_isMobileFormat;

/// 是否是qq号格式（"[1-9][0-9]{4,}"）
/// @return 是否是qq号格式
- (BOOL)xy_isQQFormat;

@end

NS_ASSUME_NONNULL_END
