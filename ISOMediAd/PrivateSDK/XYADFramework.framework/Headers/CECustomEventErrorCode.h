//
//  CECustomEventErrorCode.h
//  crystalsdk
//
//  Created by WayneShiau on 2018/1/29.
//  Copyright © 2018年 intowow. All rights reserved.
//

#import <Foundation/Foundation.h>

// While load ad results failure, please use NSError using `CECustomEventErrorDomain` as domain,
// code with `CECustomEventError` and user info with `CECustomEventDetailErrorCodeKey` if needed.
// You can also provide `NSLocalizedDescriptionKey` for tracking. The description's max length is
// 50 charactors.

extern NSErrorDomain const CECustomEventErrorDomain;

// The value should be a NSNumber. this is required while the error's code is `CECustomEventErrorLoadFailure`
extern NSString * const CECustomEventDetailErrorCodeKey;


typedef NS_ENUM(NSInteger, CECustomEventError)
{
    // Use this error if you don't know which error code should be use.
    CECustomEventErrorUnknown = 101,
    // Use this error if 3rd-party SDK doesn't have fill for the request.
    CECustomEventErrorNoFill,
    // Use this error if custom event doesn't have enough parameter to request ad.
    CECustomEventErrorParamInvalid,
    // Use this error if custom event can't consume the ad loaded from 3rd-party SDK.
    CECustomEventErrorDrop,
    // Use this error if 3rd-party SDK load ad failed and the reason is not no_fill.
    // Please provide 3rd-party SDK's error code in `userInfo` with key `CECustomEventDetailErrorCodeKey`
    CECustomEventErrorLoadFailure,
};
