//
//  XYAdRewardCallbackProtocol.h
//  FirebaseCore
//
//  Created by Frenzy Feng on 2018/11/5.
//

#import <Foundation/Foundation.h>
#import "XYAdKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYAdRewardCallbackProtocol <NSObject>

- (void)onRewardValidationFailed:(XYAdModule *)response error:(NSError *)error;
- (void)onRewardValidationSuccess:(XYAdModule *)response;
- (void)onRewardAdClose:(NSString *)adsId;
- (void)onRewardVideoDidStartPlay:(NSString *)adsId;
- (void)onRewardVideoDidEndPlay:(NSString *)adsId;
- (void)onRewardAdShown:(NSString *)adsId;
- (void)onRewardAdResult:(NSString *)adsId producer:(NSString *)producer isRewarded:(BOOL)isRewarded;

@end

NS_ASSUME_NONNULL_END
