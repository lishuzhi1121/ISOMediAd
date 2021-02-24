//
//  XYAdvertiseConfigDataModel.h
//  XYCommonAPIManager
//
//  Created by 徐新元 on 2020/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/// 广告源数据
@interface XYAdvertiseConfigDataAdModel : NSObject

//string
//必须
//广告商名字
@property (nonatomic, copy) NSString *name;

//string
//必须
//广告商编号
@property (nonatomic, copy) NSString *code;

//string
//非必须
//版块序列号
@property (nonatomic, copy) NSString *blockNumber;

//string
//必须
//广告源名字
@property (nonatomic, copy) NSString *blockName;

@end



/// 广告配置数据
@interface XYAdvertiseConfigDataModel : NSObject

//number
//非必须
//排序序号
@property (nonatomic, assign) NSInteger orderno;

//非必须
//语言
@property (nonatomic, copy) NSString *lang;

//非必须
//显示位置
@property (nonatomic, copy) NSString *dispPos;

//number
//非必须
//状态(1:启用 2：不启用)
@property (nonatomic, assign) NSInteger state;

//string
//非必须
//扩展信息
@property (nonatomic, copy) NSString *extend;

//number
//非必须
//广告形式 0原生  1视频  2插屏
@property (nonatomic, assign) NSInteger disptype;

//number
//非必须
//广告刷新间隔（秒）
@property (nonatomic, assign) NSInteger interval;

//number
//非必须
//广告总数
@property (nonatomic, assign) NSInteger count;

//object []
//非必须
//广告列表
@property (nonatomic, strong) NSArray<XYAdvertiseConfigDataAdModel *> *ad;

@end

NS_ASSUME_NONNULL_END
