#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "XYMediEventAdapter.h"
#import "XYMediEventManager.h"
#import "XYMediEventProtocol.h"

FOUNDATION_EXPORT double XYMediEventAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char XYMediEventAdapterVersionString[];

