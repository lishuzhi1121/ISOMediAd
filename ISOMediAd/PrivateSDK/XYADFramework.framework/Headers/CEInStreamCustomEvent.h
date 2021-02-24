/*!
 * @header CEInStreamCustomEvent.h
 *
 * @brief CE In-Stream Custom Event interface
 *
 * @author Intowow
 * @copyright 2018 intowow. All rights reserved.
 */

#import "I2WAPI.h"
@import UIKit;

@protocol CEInStreamCustomEventDelegate;

@interface CEInStreamCustomEvent : NSObject
@property (weak, nonatomic, readonly) id<CEInStreamCustomEventDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

// If you want to setup your custom event's property while initializing, please overwrite this selector instead of `init`,
// or your code won't be triggered properly.
- (instancetype)initWithDelegate:(id<CEInStreamCustomEventDelegate>)delegate NS_DESIGNATED_INITIALIZER;

// Please implement this selector to request ad from 3rd party SDK.
- (void)requestAdWithLocalExtras:(NSDictionary *)localExtras
                    serverExtras:(NSDictionary *)serverExtras;

// Please implement this selector to show in stream ad.
- (void)show;
@end

@protocol CEInStreamCustomEventDelegate <NSObject>
- (void)inStreamCustomEventDidLoadAd:(UIView *)ad withExtra:(NSDictionary *)extra;
- (void)inStreamCustomEventDidFailWithError:(NSError *)error;
- (void)inStreamCustomEventDidClicked;
- (void)inStreamCustomEventDidImpression;
- (void)inStreamCustomEventDidVideoStart;
- (void)inStreamCustomEventDidVideoEnd;
- (void)instreamCustomEventDidMute;
- (void)instreamCustomEventDidUnmute;
- (void)inStreamCustomEventProgressWithDuration:(CEMilliSec)totalDuration
                                       position:(CEMilliSec)currentPosition;
@end
