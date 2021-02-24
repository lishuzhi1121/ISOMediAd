//
//  XYAdModule.h
//  XYAdSDK
//
//  Created by xuxinyuan on 11/27/15.
//  Copyright © 2015 QuVideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XYAdDefine.h"
#import "XYAdKitConfigDef.h"


@interface XYAdMediaAsset : NSObject

@property (nonatomic, copy, nullable) NSURL *url;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat mediaAssetRatio;
@property (nonatomic) BOOL isCached;

@end

@interface XYAdModule : NSObject

@property (nonatomic, assign) XYAdType adType;
@property (nonatomic, copy, nullable) NSString *adsPlacement;
@property (nonatomic, copy, nullable) NSString *adsProducer;
@property (nonatomic, copy, nullable) NSString *adsId;
@property (nonatomic, strong, nullable) NSObject *userData;
@property (nonatomic) NSInteger cacheFlag;
@property (nonatomic) NSInteger numberOfAdsToFetch;
@property (nonatomic) XYADState adState;

//- (BOOL)xy_adModuleIsCached;

@property (nonatomic, copy, nullable) NSDate *adsRequestDate;
@property (nonatomic, copy, nullable) NSDate *adsFinishRequestDate;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *subtitle;
@property (nonatomic, copy, nullable) NSString *body;
@property (nonatomic, copy, nullable) NSString *socialContext;
@property (nonatomic, copy, nullable) NSString *callToAction;
@property (nonatomic, copy, nullable) NSString *adChoicesText;
@property (nonatomic, strong, nullable) XYAdMediaAsset *icon;
@property (nonatomic, strong, nullable) XYAdMediaAsset *coverImage;
@property (nonatomic, strong, nullable) XYAdMediaAsset *video;
@property (nonatomic) NSInteger retryCount;
@property (nonatomic) BOOL isAdShowing;
@property (nonatomic) BOOL isAllCached;
@property (nonatomic) BOOL isCEMediaViewPlaying;
@property (nonatomic, assign) CGFloat adNativeFetchCost;
@property (nonatomic, strong, nullable) NSError *error;
//For Facebook
@property (nonatomic, weak, nullable) UIView *mediaView;
@property (nonatomic, strong, nullable) UIView *iconView;
//For Facebook
@property (nonatomic, strong, nullable) UIView *adChoicesViewForFB;
//For Admob
@property (nonatomic, strong, nullable) UIView *contentAdView;
//For AppLovin
@property (nonatomic, copy, nullable) NSString *s2sImpression;
@property (nonatomic, copy, nullable) NSString *s2sCompletion;
@property (nonatomic, copy, nullable) NSString *s2sAction;
@property (nonatomic, strong, nullable) NSMutableArray *adArray;
@property (nonatomic, copy, nullable) NSString *landingPage;

//For Into沃尔沃
@property (nonatomic, assign) BOOL isAdRefetching;

@end
