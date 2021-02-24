/*!
 * @header CECardCustomEvent.h
 *
 * @brief CE Card Custom Event interface
 *
 * @author Intowow
 * @copyright 2018 intowow. All rights reserved.
 */

@import UIKit;

@protocol CECardCustomEventDelegate;

@interface CECardCustomEvent : NSObject
@property (weak, nonatomic, readonly) id<CECardCustomEventDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

// If you want to setup your custom event's property while initializing, please overwrite this selector instead of `init`,
// or your code won't be triggered properly.
- (instancetype)initWithDelegate:(id<CECardCustomEventDelegate>)delegate NS_DESIGNATED_INITIALIZER;

// Please implement this selector to request ad from 3rd party SDK.
- (void)requestAdWithLocalExtras:(NSDictionary *)localExtras
                    serverExtras:(NSDictionary *)serverExtras;
@end

@protocol CECardCustomEventDelegate <NSObject>

//If the third-party SDK can't provide real aspect ratio of content, please set ad frame to (0, 0, 0, 0).
//Our SDK will handle this situation.
- (void)cardCustomEventDidLoadAd:(UIView *)ad withExtra:(NSDictionary *)extra;

- (void)cardCustomEventDidFailWithError:(NSError *)error;
- (void)cardCustomEventDidClicked;
- (void)cardCustomEventDidImpression;
- (void)cardCustomEventDidMute;
- (void)cardCustomEventDidUnmute;
- (void)cardCustomEventDidVideoStart;
- (void)cardCustomEventDidVideoEnd;
- (void)cardCustomEventDidVideoProgressWithDuration:(int)totalDuration
                                           position:(int)currentPosition;
@end
