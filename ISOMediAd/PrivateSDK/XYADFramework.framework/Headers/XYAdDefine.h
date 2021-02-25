//
//  XYAdDefine.h
//  Pods
//
//  Created by Frenzy-Mac on 2017/11/15.
//

#ifndef XYAdDefine_h
#define XYAdDefine_h

#ifdef DEBUG
#define XY_DEBUG_LOG_AD
#endif

#define kXYAdViewScale ([UIScreen mainScreen].bounds.size.width/375.0)

/* 兼容AdService */
#define  PREF_KEY_VIVAVIDEO_5_0_AD_CONFIG_LAST_FETCH_TIME      @"KeyVivaVideo5.0AdConfigLastFetchTime"
#define  PREF_KEY_VIVAVIDEO_5_0_AD_CONFIG_MD5                  @"KeyVivaVideo5.0AdConfigMd5"

#define PREF_XYAD_INTERSTITIAL_AD_SHOW_TIME  @"PREF_XYAD_INTERSTITIAL_AD_SHOW_TIME"
#define PREF_XYAD_INTERSTITIAL_AD_CLOSE_TIME @"PREF_XYAD_INTERSTITIAL_AD_CLOSE_TIME"
/* 运营位+开屏+闪屏 循环播放 */
#define PREF_KEY_SPLASH_NEED_LOAD_TYPE                  @"pref_splash_need_load_type"
#define PREF_KEY_SPLASH_AD_LOAD_RETRY_COUNT             @"pref_splash_ad_load_retry_count"

//Notifications def
#define NOTIFICATION_XYAD_FETCH_NATIVEAD_RESULT       @"NOTIFY_XYAD_FETCH_NATIVEAD_RESULT"
#define NOTIFICATION_XYAD_KEY_REQUESTDATE             @"NOTIFY_XYAD_KEY_REQUESTDATE"
#define NOTIFICATION_XYAD_KEY_FINISH_REQUESTDATE      @"NOTIFY_XYAD_KEY_FINISH_REQUESTDATE"
#define NOTIFICATION_XYAD_KEY_PRODUCER                @"NOTIFY_XYAD_KEY_PRODUCER"
#define NOTIFICATION_XYAD_KEY_PLACEMENT               @"NOTIFY_XYAD_KEY_PLACEMENT"
#define NOTIFICATION_XYAD_KEY_RESULT                  @"NOTIFY_XYAD_KEY_RESULT"
#define NOTIFICATION_XYAD_KEY_CACHEFLAG               @"NOTIFY_XYAD_KEY_CACHEFLAG"
#define NOTIFICATION_XYAD_VALUE_RESULT_FAILED         @"NOTIFY_XYAD_VALUE_RESULT_FAILED"
#define NOTIFICATION_XYAD_VALUE_RESULT_SUCCESS        @"NOTIFY_XYAD_VALUE_RESULT_SUCCESS"
#define NOTIFICATION_XYAD_VALUE_RESULT_ALL_FAILED     @"NOTIFY_XYAD_VALUE_RESULT_ALL_FAILED"

#define NOTIFICATION_XYAD_CACHE_IMAGE_CACHED          @"NOTIFY_XYAD_CACHE_IMAGE_CACHED"
#define NOTIFICATION_XYAD_CACHE_IMAGE_FAILED          @"NOTIFY_XYAD_CACHE_IMAGE_FAILED"
#define NOTIFICATION_XYAD_CACHE_VIDEO_CACHED          @"NOTIFY_XYAD_CACHE_VIDEO_CACHED"
#define NOTIFICATION_XYAD_CACHE_VIDEO_FAILED          @"NOTIFY_XYAD_CACHE_VIDEO_FAILED"
#define NOTIFICATION_XYAD_CACHE_ALL_CACHED            @"NOTIFY_XYAD_CACHE_ALL_CACHED"

#define NOTIFICATION_XYAD_VIDEO_AD_CLICK              @"NOTIFY_XYAD_VIDEO_AD_CLICK"
#define NOTIFICATION_XYAD_AD_CLICK                    @"NOTIFY_XYAD_AD_CLICK"

#define NOTIFICATION_XYAD_REWARD_VALIDATE_RESULT      @"NOTIFY_XYAD_REWARD_VALIDATE_RESULT"
#define NOTIFICATION_XYAD_REWARD_AD_CLOSE             @"NOTIFICATION_XYAD_REWARD_AD_CLOSE"
#define NOTIFICATION_XYAD_REWARD_VIDEO_DID_START_PLAY @"NOTIFICATION_XYAD_REWARD_VIDEO_DID_START_PLAY"
#define NOTIFICATION_XYAD_REWARD_VIDEO_DID_END_PLAY   @"NOTIFICATION_XYAD_REWARD_VIDEO_DID_END_PLAY"
#define NOTIFICATION_XYAD_REWARD_DID_REWARD           @"NOTIFICATION_XYAD_REWARD_DID_REWARD"
#define NOTIFICATION_XYAD_REWARD_DID_REWARD_FAILED    @"NOTIFICATION_XYAD_REWARD_DID_REWARD_FAILED"

#define NOTIFICATION_XYAD_BANNER_AD_READY             @"NOTIFICATION_XYAD_BANNER_AD_READY"
#define NOTIFICATION_XYAD_BANNER_AD_CLICK             @"NOTIFICATION_XYAD_BANNER_AD_CLICK"

#define NOTIFICATION_XYAD_MEDIUM_AD_READY             @"NOTIFICATION_XYAD_MEDIUM_AD_READY"
#define NOTIFICATION_XYAD_MEDIUM_AD_CLICK             @"NOTIFICATION_XYAD_MEDIUM_AD_CLICK"

#define NOTIFICATION_XYAD_CARD_AD_READY               @"NOTIFICATION_XYAD_CARD_AD_READY"
#define NOTIFICATION_XYAD_CARD_AD_FAILED              @"NOTIFICATION_XYAD_CARD_AD_FAILED"
#define NOTIFICATION_XYAD_CARD_AD_CLICK               @"NOTIFICATION_XYAD_CARD_AD_CLICK"
#define NOTIFICATION_XYAD_CARD_AD_PLAY_START          @"NOTIFICATION_XYAD_CARD_AD_PLAY_START"
#define NOTIFICATION_XYAD_CARD_AD_PLAY_END            @"NOTIFICATION_XYAD_CARD_AD_PLAY_END"

#define NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_AD_READY       @"NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_AD_READY"
#define NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_AD_VIDEO_READY @"NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_AD_VIDEO_READY"
#define NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_CLICK          @"NOTIFICATION_XYAD_INTERSTITIAL_VIDEO_CLICK"

#define NOTIFICATION_XYAD_SPLASH_AD_DISMISS  @"NOTIFICATION_XYAD_SPLASH_AD_DISMISS"

#define XYAD_FACEBOOK_ADCHOICES_VIEW_TAG              1017

#define XY_DEFAULTS_KEY_DURATION_LIMIT_AD_UNLOCK      @"XY_DEFAULTS_KEY_DURATION_LIMIT_AD_UNLOCK"


//Cache flag def
#define XYAdCacheFlag                                 @"XYAdCacheFlag"

#define XYAdImpressionInterval                        @"XYAdImpressionInterval"

#define XY_AD_ASSETS_CACHEFLAG_IMAGE_ICON             1                                               //Need to cache the ad icon
#define XY_AD_ASSETS_CACHEFLAG_IMAGE_BG               1<<1                                            //Need to cache the ad cover image
#define XY_AD_ASSETS_CACHEFLAG_VIDEO                  1<<2                                            //Need to cache the ad video
#define XY_AD_ASSETS_CACHEFLAG_REALTIME               1<<3                                            //Request the ad only when we enter the view that need to display the ad

#define XY_AD_EXPIRE_TIME                             1800                                            //(seconds)
#define XY_AD_RECHECK_INTERVAL                        60                                              //(seconds)

#define XY_AD_MAX_RETRY_COUNT                         3
#define XY_AD_RETRY_COUNT_MILESTONE                   10


//The Viva Ad Placement
#define XYAdVivaPlacementSplash                       @"XYAdVivaPlacementSplash"
#define XYAdVivaPlacementHomeRecommend                @"XYAdVivaPlacementHomeRecommend"
#define XYAdVivaPlacementHomePopup                    @"XYAdVivaPlacementHomePopup"
#define XYAdVivaPlacementExportDone                   @"XYAdVivaPlacementExportDone"


typedef NS_ENUM(NSUInteger, XYADState)                {
     XYADStateNone,
     XYADStateLoadingData,
     XYADStateCaching,
     XYADStateAllCached,
     XYADStateShowing,
     XYADStateShown
};

#endif /* XYAdDefine_h */
