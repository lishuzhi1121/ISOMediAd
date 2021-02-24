//
//  XYDataService.h
//  
//
//  Created by SandsLee on 2020/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYDataService : NSObject

/// 设置安全数据(保存到KeyChain中)
/// @param data 数据
/// @param key 标识
+ (void)setSecureData:(id)data forKey:(NSString *)key;

/// 获取安全数据(从KeyChain中获取)
/// @param key 标识
+ (id)secureDataForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
