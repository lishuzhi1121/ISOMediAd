/*!
 * @header CERequestInfo.h
 *
 * @brief Ad Request Information
 *
 * @author Intowow
 * @copyright 2018 intowow. All rights reserved.
 */

@import Foundation;
@import CoreGraphics;

extern CGFloat CEAdWidthInvalid;
extern NSTimeInterval CETimeoutDefault;

@class CETargetingRule;

@interface CERequestInfo : NSObject <NSCopying>
@property (nonatomic, copy) NSString *placement;
@property (nonatomic, assign) int place;
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, copy) NSDictionary *localExtra;
@property (nonatomic, assign) CGFloat adWidth;
- (void)addTargetingRules:(NSArray<CETargetingRule *> *)rules forKey:(NSString *)key;
@end
