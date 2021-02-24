//
//  XYAdCardProtocol.h
//  Adjust
//
//  Created by Frenzy-Mac on 2018/3/13.
//

#import <Foundation/Foundation.h>

@protocol XYAdCardProtocol <NSObject>

/* Card Ad 目前只有Into沃尔沃 */
- (UIView *)getCardAdView:(XYAdModule *)adModule;
- (void)preloadAdVideo:(NSString *)producer placementId:(NSString *)placementId;

/***  Card Ad  ***/
- (BOOL)fetchCardAdWithPlacementID:(NSString *)placementID andPlacement:(NSString *)placement andProducer:(NSString *)producer withTimeout:(BOOL)withTimeout;

- (BOOL)fetchCardAd:(XYAdModule *)adModule withTimeout:(BOOL)withTimeout;

- (void)cancelCardAd;

- (void)cardAdLoaded:(BOOL)success;
- (void)cardAdShown:(BOOL)success;
- (void)cardAdPlayStart;
- (void)cardAdPlayEnd;
- (void)cardAdClicked;

@end
