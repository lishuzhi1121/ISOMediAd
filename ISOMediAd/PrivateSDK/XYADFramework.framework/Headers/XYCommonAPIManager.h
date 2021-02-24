//
//  XYCommonAPIManager.h
//  XYCommonAPIManager
//
//  Created by lizitao on 2019/8/14.
//

#import <Foundation/Foundation.h>
#import "XYCommonAPITools.h"
#import "XYCommonParamsModel.h"
#import "XYCommonQADomainMap.h"

//Router信息更新成功通知
#define XYCommonDomainRouterHasChangedNotification         @"xy_common_domainRouter_changedSuccess_notification"
//Router信息不更新通知
#define XYCommonDomainRouterNotChangedNotification         @"xy_common_domainRouter_not_changed_notification"
//Router接口Fail通知
#define XYCommonDomainRouterFailedNotification             @"xy_common_domainRouter_failed_notification"
//DeviceRegist信息变化通知
#define XYCommonDeviceRegisterHasChangedNotification       @"xy_common_deviceRegister_changed_notification"
//DeviceRegist信息不更新通知
#define XYCommonDeviceRegisterNotChangedNotification       @"xy_common_deviceRegister_not_changed_notification"

#define XYCommonOriginRouterDataKey           @"xy_common_origin_router_data_Key"
#define XYCommonCurrentRouterZoneKey          @"xy_common_current_router_zone_Key"
#define XYCommonCurrentRouterDomainKey        @"xy_common_current_router_domain_Key"
#define XYCommonCurrentDeviceIDKey            @"xy_common_current_deviceID_Key"

typedef void (^XYCommonAPIFinished)(id request, NSInteger nErrCode, id response);
typedef void (^XYCommonAPICompleteCallback)(id request, NSError * error, id response);
typedef void (^XYCommonParamsBlock)(XYCommonParamsModel *model);

@interface XYCommonAPIManager : NSObject

+ (instancetype)manager;
+ (instancetype)defaultManager;
//当前的Zone，根据接口返回来定（适合全区域投放的产品）
@property (nonatomic, copy) NSString *curRouterZone;
//当前的domain，根据接口返回来查找（适合全区域投放的产品）
@property (nonatomic, copy) NSString *curRouterDomain;

//外部指定的url，根据外部指定（不走切区逻辑）
@property (nonatomic, copy) NSString *curAllocatedRouterUrl;
//外部指定的zone，根据外部指定（不走切区逻辑）
@property (nonatomic, copy) NSString *curAllocatedRouterZone;
//外部指定的domain，根据外部指定（不走切区逻辑）
@property (nonatomic, copy) NSString *curAllocatedRouterDomain;

//设备标识
@property (nonatomic, copy) NSString *curDuiddigest;

@property (nonatomic, copy, readonly) NSDictionary *commonParams; // 公共参数

@property (nonatomic, assign, readonly) BOOL isQAEnvironment; // 公共参数

@property (nonatomic, assign) BOOL isAsyncCompletion; //接口返回是否需要在子线程（默认是主线程）


/// 发起POST请求
/// @param path 请求路径，例如 /api/rest/push/commontag
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callPOSTWithPath:(NSString *)path
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;

/// 发起GET请求
/// @param path 请求路径，例如 /api/rest/push/commontag
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callGETWithPath:(NSString *)path
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;

/// 带自定义域名并发起GET请求
/// @param path 请求路径，例如 /api/rest/push/commontag
/// @param domain 自定义域名，例如 https://www.xiaoying.tv
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callGETWithPath:(NSString *)path
                 domain:(NSString *)domain
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;

/// 带自定义域名并发起POST请求
/// @param path path 请求路径，例如 /api/rest/push/commontag
/// @param domain 自定义域名，例如 https://www.xiaoying.tv
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callPOSTWithPath:(NSString *)path
                  domain:(NSString *)domain
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;


/// 全功能的POST请求
/// @param path path 请求路径，例如 /api/rest/push/commontag
/// @param customCommonParameter 自定义的一级参数，例如productid
/// @param domain 自定义域名，例如 https://www.xiaoying.tv
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callPOSTWithPath:(NSString *)path
   customCommonParameter:(NSDictionary *)customCommonParameter
                  domain:(NSString *)domain
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;

/// 全功能的GET请求
/// @param path path 请求路径，例如 /api/rest/push/commontag
/// @param customCommonParameter 自定义的一级参数，例如productid
/// @param domain 自定义域名，例如 https://www.xiaoying.tv
/// @param parameters 参数，非一级参数，指的是content下面的参数
/// @param complete 完成回调
- (void)callGETWithPath:(NSString *)path
  customCommonParameter:(NSDictionary *)customCommonParameter
                 domain:(NSString *)domain
              parameters:(NSDictionary *)parameters
                complete:(XYCommonAPICompleteCallback)complete;

// 配置公共参数
- (void)configCommonAPIManagerParams:(XYCommonParamsBlock)paramsBlock;

@end

@interface XYCommonAPIManager (Deprecated)

- (void)callPostRequestWithUrl:(NSString *)url
                        params:(NSDictionary *)params
                      finished:(XYCommonAPIFinished)finished __attribute__((deprecated("已废弃，建议使用 -callPOSTWithPath:parameters:complete:")));

- (void)callPostRequestWithUrl:(NSString *)url
                 contentParams:(NSDictionary *)contentParams
                    mainParams:(NSDictionary *)mainParams
                        method:(NSString *)method
                      finished:(XYCommonAPIFinished)finished __attribute__((deprecated("已废弃，建议使用 -callPOSTWithPath:parameters:complete:")));

/**
 封装POST公共参数的请求

 @param url 完整请求url
 @param method api方法名/路径
 @param params 业务参数(content字段参数)
 @param finished 结果回调
 */
- (void)callPostRequestWithUrl:(NSString *)url
                        method:(NSString *)method
                 contentParams:(NSDictionary *)params
                      finished:(XYCommonAPIFinished)finished __attribute__((deprecated("已废弃，建议使用 -callPOSTWithPath:parameters:complete:")));

/**
 封装GET公共参数的请求

 @param url 完整请求url
 @param method api方法名/路径
 @param params 业务参数(content字段参数)
 @param finished 结果回调
 */
- (void)callGETRequestWithUrl:(NSString *)url
                        method:(NSString *)method
                 contentParams:(NSDictionary *)params
                      finished:(XYCommonAPIFinished)finished __attribute__((deprecated("已废弃，建议使用 -callGETWithPath:parameters:complete:")));
@end


