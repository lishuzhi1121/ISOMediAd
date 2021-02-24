//
//  XYAdCore+CardAds.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/8/23.
//

#import "XYAdCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdCore (CardAds)

- (UIView *)getCardAdView:(XYAdModule *)adModule;
- (void)cancelCardAd:(NSString *)placement
           producers:(NSArray <NSString *>*)producers;

@end

NS_ASSUME_NONNULL_END
