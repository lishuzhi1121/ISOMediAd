//
//  XYAdObserveProtocol.h
//  XYAdSDK
//
//  Created by Frenzy on 9/19/17.
//  Copyright © 2016 QuVideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYAdModule.h"

typedef enum : NSUInteger {
    XYAdObserveLogAdShow,
    XYAdObserveLogAdClick,
    
    XYAdObserveNativeFetch,
    XYAdObserveNativeFetchSuccess,
    XYAdObserveNativeFetchFailed,
    XYAdObserveNativeFetchImpression,
    
    XYAdObserveBannerFetch,
    XYAdObserveBannerFetchSuccess,
    XYAdObserveBannerFetchFailed,
    XYAdObserveBannerWillShow,
    XYAdObserveBannerDidClick,
    
    XYAdObserveNativeBannerFetch,
    XYAdObserveNativeBannerFetchSuccess,
    XYAdObserveNativeBannerFetchFailed,
    XYAdObserveNativeBannerWillShow,
    XYAdObserveNativeBannerDidClick,
    
    XYAdObserveIntertitialFetch,
    XYAdObserveIntertitialFetchSuccess,
    XYAdObserveIntertitialFetchFailed,
    XYAdObserveIntertitialShown,
    XYAdObserveIntertitialClick,
    XYAdObserveIntertitialClickClose, //用户主动关闭，且没有点击广告
    
    XYAdObserveRewardFetch,
    XYAdObserveRewardFetchSuccess,
    XYAdObserveRewardFetchFailed,
    
    XYAdObserveCardFetch,
    XYAdObserveCardFetchSuccess,
    XYAdObserveCardFetchFailed,
    XYAdObserveCardShow,
    XYAdObserveCardShown,
    XYAdObserveCardClick,
    XYAdObserveCardStartPlay,
    XYAdObserveCardStopPlay,
    
    XYAdObserveIntertitialVideoFetch,
    XYAdObserveIntertitialVideoFetchSuccess,
    XYAdObserveIntertitialVideoLoadSuccess,
    XYAdObserveIntertitialVideoLoadFailed,
    XYAdObserveIntertitialVideoPlayComplete,
    XYAdObserveIntertitialVideoClick,
    XYAdObserveIntertitialVideoDidClose,
    
    XYAdObserveMediumFetch,
    XYAdObserveMediumFetchSuccess,
    XYAdObserveMediumFetchFailed,
    XYAdObserveMediumWillShow,
    XYAdObserveMediumDidClick,
} XYAdObserve;

@protocol XYAdObserveProtocol <NSObject>

@required

@optional

- (void)observeAdStatus:(XYAdObserve)status withAdModule:(XYAdModule *)adModule;

@end
