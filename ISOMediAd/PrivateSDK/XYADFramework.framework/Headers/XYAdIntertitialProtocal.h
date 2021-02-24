//
//  XYAdIntertitialProtocal.h
//  Adjust
//
//  Created by Frenzy-Mac on 2017/11/20.
//

#import <Foundation/Foundation.h>

@protocol XYAdIntertitialProtocol <NSObject>

- (void)intertitialAdLoaded:(BOOL)success;
- (void)intertitialAdShown:(BOOL)success;
- (void)intertitialAdClicked:(NSString *)name;
- (void)intertitialAdClosed;

@end
