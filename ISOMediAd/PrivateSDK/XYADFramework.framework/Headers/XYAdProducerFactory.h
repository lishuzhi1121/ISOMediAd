//
//  XYAdProducerFactory.h
//  AFNetworking
//
//  Created by Frenzy Feng on 2018/8/6.
//

#import <Foundation/Foundation.h>
#import "XYAdBase.h"

@interface XYAdProducerFactory : NSObject

@property (nonatomic, strong) NSMutableArray *producers;

+ (NSArray *)createProducersWithDelegate:(id<XYAdBaseDelegate>)delegate;

+ (NSArray *)createProducersWithDelegate:(id<XYAdBaseDelegate>)delegate producersDict:(NSDictionary *)dict;

@end
