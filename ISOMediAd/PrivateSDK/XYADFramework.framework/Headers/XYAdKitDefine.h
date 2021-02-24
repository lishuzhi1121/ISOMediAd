//
//  XYAdKitDefine.h
//  Pods
//
//  Created by Frenzy Feng on 2018/8/6.
//

#ifndef XYAdKitDefine_h
#define XYAdKitDefine_h

#import "XYAdModule.h"

#define XYAD_VALUE_YES @"yes"
#define XYAD_VALUE_NO  @"no"

typedef enum : NSUInteger {
    XYAdRequestStateStart,
    XYAdRequestStateDidGetView,
    XYAdRequestStateDidLoad,
    XYAdRequestStateDidLoadFailed,
    XYAdRequestStateShow,
    XYAdRequestStateClick,
    XYAdRequestStateClose,
} XYAdRequestState;


typedef void (^XYAdRequestResult)(XYAdModule *adModule, XYAdRequestState state);


/* 单个获取, 目前支持:NativeBanner */

typedef enum : NSUInteger {
    XYAdFetchStatusInit,
    XYAdFetchStatusReturn,
    XYAdFetchStatusLoading,
    XYAdFetchStatusFailed,
    XYAdFetchStatusSuccess,
} XYAdFetchStatus;

typedef void (^XYAdFetchResultBlock)(XYAdModule *adModule, XYAdFetchStatus status);

@class XYAdFetcher;
typedef void (^XYAdCoreFetchResultBlock)(XYAdFetcher *adFetcher, XYAdFetchStatus status);

#endif /* XYAdKitDefine_h */
