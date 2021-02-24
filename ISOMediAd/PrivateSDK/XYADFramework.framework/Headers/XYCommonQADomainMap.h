//
//  XYCommonQADomainMap.h
//  XYCommonAPIManager
//
//  Created by lizitao on 2019/9/5.
//

#import <Foundation/Foundation.h>

#define  XYCommonRouterService             @"router"
#define  XYCommonDeviceCenterService       @"deviceCenter"
#define  XYCommonUserCenterService         @"userCenter"
#define  XYCommonCommerceService           @"commerce"
#define  XYCommonOSSService                @"oss"
#define  XYCommonFeedbackService           @"feedback"
#define  XYCommonReportService             @"Report"

#define  XYCommonQADomain(service) [XYCommonQADomainMap obtainCommonDomainByService:(service)];

@interface XYCommonQADomainMap : NSObject

//传入api所属的sevice名称
+ (NSString *)obtainCommonDomainByService:(NSString *)service;

@end

