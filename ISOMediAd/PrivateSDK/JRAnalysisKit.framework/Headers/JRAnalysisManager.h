//
//  JRAnalysisManager.h
//  JRAnalysisKit
//
//  Created by Lan Xuping on 2020/11/23.
//  Copyright © 2020 Lan Xuping. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JRAnalysisManager : NSObject
/**
 Advice : calls once on app running.

 @param token token
 */
+ (void)initWithToken:(NSString *)token;

/**
 SDK current version

 @return version
 */
+ (NSString*)version;
@end

NS_ASSUME_NONNULL_END
