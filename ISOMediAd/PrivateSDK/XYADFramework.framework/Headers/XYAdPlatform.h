//
//  XYAdPlatform.h
//  XYAdCore
//
//  Created by 徐新元 on 2020/3/18.
//

#import <Foundation/Foundation.h>
#import "XYAdPlatformAdParamMaker.h"
#import "XYAdModule.h"
#import "XYAdView.h"
#import "XYAdKitDefine.h"
#import "XYAdProducerConfigProtocol.h"
#import "XYAdProducerConfigModel.h"
#import "XYAdPlatformConfigResponseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface XYAdPlatform : NSObject

/// 广告中台是否已经初始化完成
@property (nonatomic, assign) BOOL hasInitialized;

@property (nonatomic, strong) XYAdPlatformConfigResponseModel *configModel;

/// 单例对象
+ (instancetype)sharedInstance;

/// 初始化广告中台
/// @param adConfig 服务器下发的，或是本地预置的广告配置信息，格式可以参考接口返回值 http://restapi.quvideo.com/project/533/interface/api/9052
/// @param authorization 用户是否授权信息收集
/// @param adProducerConfigModel 第三方广告商的配置信息
- (void)initAdPlatformWithConfig:(NSDictionary *)adConfig
                   authorization:(BOOL)authorization
           adProducerConfigModel:(XYAdProducerConfigModel *)adProducerConfigModel;

///如果初始化的时候没有授权，后面同意之后，再调用一下这个接口，并传YES
/// @param authorization 用户是否授权信息收集
- (void)authorizationAdPlatform:(BOOL)authorization;

/// 根据广告配置信息，调整内部逻辑
/// @param adConfig 服务器下发的，或是本地预置的广告配置信息，格式可以参考接口返回值 http://restapi.quvideo.com/project/533/interface/api/9052
- (void)updateAdPlatformWithConfig:(NSDictionary *)adConfig;

/// 控制广告开关
/// @param enable YES 启用， NO关闭，默认值为YES
- (void)enableAd:(BOOL)enable;

#pragma mark - Native广告
/// 请求Native广告数据
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)fetchNativeAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                             result:(XYAdFetchResultBlock)result;

/// 获取Native广告缓存数据
/// @param paramMakerBlock 参数设置block
- (XYAdModule *)loadCachedNativeAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;


/// 创建Native广告MediaView
/// @param adModule Native广告数据模型
/// @param frame 需要生成的view的frame
- (UIView *)createNativeAdMediaView:(XYAdModule *)adModule frame:(CGRect)frame;

/// 注册Native广告
/// @param adView 广告View
- (void)registerNativeAdView:(XYAdView *)adView
              viewController:(UIViewController *)viewController;

/// 取消注册Native广告, 用于移除缓存, 清理内存
/// @param registedAdModule 注册过的adModule对象
- (void)unregisterNativeAdModule:(XYAdModule *)registedAdModule;

#pragma mark - 奖励视频广告
///预加载奖励视频广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)preloadRewardAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                               result:(XYAdFetchResultBlock)result;

///展示奖励视频广告
/// @param paramMakerBlock 参数设置block
/// @param rewardResultHandler 激励结果回调block
- (void)showRewardAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                    onRewardResult:(void (^)(XYAdModule *adModule, BOOL isRewarded))rewardResultHandler;


#pragma mark - 插屏广告
///获取插屏广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)fetchInterstitialAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                                   result:(XYAdFetchResultBlock)result;

/// 展示插屏广告
/// @param paramMakerBlock 参数设置block
- (void)showInterstitialAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;

#pragma mark - 视频插屏广告
///获取视频插屏广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)fetchInterstitialVideoAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                                        result:(XYAdFetchResultBlock)result;

/// 展示视频插屏广告
/// @param paramMakerBlock 参数设置block
- (void)showInterstitialVideoAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;


#pragma mark - Banner广告
///请求Banner广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)fetchBannerAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                             result:(XYAdFetchResultBlock)result;

/// 获取Banner广告, 返回BannerView
/// @param paramMakerBlock 参数设置block
- (UIView *)createBannerAdViewWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;

#pragma mark - MREC 广告

///请求MREC广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (void)fetchMRECAdWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                           result:(XYAdFetchResultBlock)result;

/// 获取MREC广告视图, 返回XYAdVungleMediumContainer
/// @param paramMakerBlock 参数设置block
- (UIView *)createMediumAdViewWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;

#pragma mark - Splash View广告
///获取SplashView广告
/// @param paramMakerBlock 参数设置block
/// @param result 请求完成block
- (UIView *)createSplashAdViewWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock
                                      result:(XYAdRequestResult)result;

/// 展示开屏广告
/// @param paramMakerBlock 参数设置block
- (void)showSplashAdViewWithParamMaker:(void(^)(XYAdPlatformAdParamMaker *maker))paramMakerBlock;


@end

NS_ASSUME_NONNULL_END
