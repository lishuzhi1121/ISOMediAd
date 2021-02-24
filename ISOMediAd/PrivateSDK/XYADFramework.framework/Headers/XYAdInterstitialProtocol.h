//
//  XYAdInterstitialProtocol.h
//  AliyunOSSiOS
//
//  Created by Frenzy Feng on 2018/10/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdInterstitialProtocol <NSObject>

@optional

- (void)fetchInterstitialAd:(XYAdModule *)adModule
                 controller:(UIViewController *)controller
                       from:(NSString *)from
                   delegate:(id)delegate
                     result:(XYAdRequestResult)result;

- (BOOL)showInterstitialAd:(XYAdModule *)adModule
                controller:(UIViewController *)controller
                      from:(NSString *)from
                    result:(XYAdRequestResult)result;

@end

NS_ASSUME_NONNULL_END
