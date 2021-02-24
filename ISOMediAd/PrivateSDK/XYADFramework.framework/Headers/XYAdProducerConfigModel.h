//
//  XYAdProducerConfigModel.h
//  GoogleUtilities
//
//  Created by 徐新元 on 2020/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYAdProducerConfigModel : NSObject

#if __has_include("XYAdMobvista.h")
/// Mobvista广告的AppKey
@property (nonatomic, copy) NSString *mobVistaAppKey;
/// Mobvista广告的AppId
@property (nonatomic, copy) NSString *mobVistaAppId;
#endif

#if __has_include("XYAdWM.h")
/// 头条广告的AppId
@property (nonatomic, copy) NSString *wmAppId;
#endif

#if __has_include("XYAdJR.h")
/// JumpRaw无感广告的token
@property (nonatomic, copy) NSString *jRtoken;
#endif

#if __has_include("XYVungle.h")
/// Vungle 广告商AppId
@property (nonatomic, copy) NSString *vungleAppId;
#endif


#if __has_include("XYMoPub.h")
/// MoPub 广告商AdUnitId
@property (nonatomic, copy) NSString *mopubAdUnitId;
#endif

@end

NS_ASSUME_NONNULL_END
