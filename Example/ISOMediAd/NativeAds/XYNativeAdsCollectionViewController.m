//
//  XYNativeAdsCollectionViewController.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/23.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYNativeAdsCollectionViewController.h"
#import <XYADFramework/XYAdPlatform.h>
#import "XYNativeAdsCollectionViewCell.h"
#import "XYPlaceholderCollectionViewCell.h"

@interface XYNativeAdsCollectionViewController ()<UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) NSMutableArray *dataSourceList;

@property (nonatomic, strong) XYAdModule *preloadedAd;

@end

@implementation XYNativeAdsCollectionViewController

static NSString * const nativeReuseIdentifier = @"XYNativeAdsCollectionViewCell";
static NSString * const placeholderReuseIdentifier = @"XYPlaceholderCollectionViewCell";
static NSInteger placeholderIndex = 0;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    for (int i = 0; i < 500; i++) {
        NSString *placeholder = [NSString stringWithFormat:@"placeholder\n- %zd -", placeholderIndex++];
        [self.dataSourceList addObject:placeholder];
    }
    
    [self fetchNativeAdData];
}

- (void)fetchNativeAdData {
    __weak typeof(self) weakSelf = self;
    [[XYAdPlatform sharedInstance] fetchNativeAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
        maker.placement(@"4").viewController(weakSelf).from(@"test");
    } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
        if (status == XYAdFetchStatusSuccess) {
//            [weakSelf.dataSourceList addObject:adModule];
//            for (int i = 0; i < 3; i++) {
//                NSString *placeholder = [NSString stringWithFormat:@"placeholder\n- %zd -", placeholderIndex++];
//                [weakSelf.dataSourceList addObject:placeholder];
//            }
            
            [weakSelf.dataSourceList replaceObjectAtIndex:1 withObject:adModule];
            [weakSelf.collectionView reloadData];
        }
    }];
}

- (IBAction)addButtonClick:(UIBarButtonItem *)sender {
    NSLog(@"%s", __func__);
    [self fetchNativeAdData];
}

#pragma mark <UICollectionViewDataSource>

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return self.dataSourceList.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    id data = self.dataSourceList[indexPath.item];
    UICollectionViewCell *cell = nil;
    if ([data isKindOfClass:[XYAdModule class]]) {
        cell = [collectionView dequeueReusableCellWithReuseIdentifier:nativeReuseIdentifier forIndexPath:indexPath];
    } else {
        cell = [collectionView dequeueReusableCellWithReuseIdentifier:placeholderReuseIdentifier forIndexPath:indexPath];
    }
    
    // Configure the cell
    if ([cell isKindOfClass:[XYNativeAdsCollectionViewCell class]]) {
        __weak typeof(self) weakSelf = self;
        [((XYNativeAdsCollectionViewCell *)cell) renderWithNativeAd:data rootVC:self completion:^(BOOL success) {
            // TODO: 注册成功之后请求下一个
            if (success && weakSelf.preloadedAd == nil) {
                [[XYAdPlatform sharedInstance] fetchNativeAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
                    maker.placement(@"4").viewController(weakSelf).from(@"test");
                } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
                    if (status == XYAdFetchStatusSuccess) {
                        @synchronized (weakSelf) {
                            weakSelf.preloadedAd = adModule;
                        }
                    }
                }];
            }
        }];
    } else {
        ((XYPlaceholderCollectionViewCell *)cell).text = data;
    }
    
    return cell;
}

#pragma mark <UICollectionViewDelegate>

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    NSLog(@">>>> %s <<<<", __func__);
    // TODO: 停止滑动的时候判断是否插入广告
    [self checkToReplaceAds];
}

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate {
    NSLog(@">>>> %s <<<<", __func__);
    // TODO: 停止拖动的时候判断是否插入广告
    [self checkToReplaceAds];
}

- (void)checkToReplaceAds {
    NSArray<NSIndexPath *> *visibleIndexPaths = [self.collectionView indexPathsForVisibleItems];
    NSLog(@">>>> visibleIndexPaths: %@", visibleIndexPaths);
    for (NSIndexPath *indexPath in visibleIndexPaths) {
        // 第7个之后每隔7个插入一个广告
        if (indexPath.item > 5 && indexPath.item % 5 == 0) {
            // 如果这个位置不是广告, 则替换为广告
            if (![self.dataSourceList[indexPath.item] isKindOfClass:[XYAdModule class]]) {
                @synchronized (self) {
                    if (self.preloadedAd) {
                        // 1. 有广告时直接替换
                        [self.dataSourceList replaceObjectAtIndex:indexPath.item withObject:self.preloadedAd];
//                        [self.dataSourceList insertObject:self.preloadedAd atIndex:indexPath.item];
                        self.preloadedAd = nil;
                        [self.collectionView reloadItemsAtIndexPaths:@[indexPath]];
                    } else {
                        // 2. 没有广告时请求
                        __weak typeof(self) weakSelf = self;
                        [[XYAdPlatform sharedInstance] fetchNativeAdWithParamMaker:^(XYAdPlatformAdParamMaker * _Nonnull maker) {
                            maker.placement(@"4").viewController(weakSelf).from(@"test");
                        } result:^(XYAdModule *adModule, XYAdFetchStatus status) {
                            if (status == XYAdFetchStatusSuccess) {
                                @synchronized (weakSelf) {
                                    weakSelf.preloadedAd = adModule;
//                                    [weakSelf checkToReplaceAds];
                                }
                            }
                        }];
                    }
                }
            }
        }
    }
}


#pragma mark - UICollectionViewDelegateFlowLayout

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    CGFloat collectionViewWidth = collectionView.bounds.size.width;
    CGFloat cellWidth = (collectionViewWidth / 3.0) - 2.0;
    id data = self.dataSourceList[indexPath.item];
    if (indexPath.item == 1) {
        if ([data isKindOfClass:[NSString class]]) {
            return CGSizeMake(cellWidth, 1);
        } else {
            return CGSizeMake(cellWidth, 203);
        }
    }
    if (indexPath.item > 5 && indexPath.item % 5 == 0 && [data isKindOfClass:[NSString class]]) {
        return CGSizeMake(cellWidth, 1);
    }
    return CGSizeMake(cellWidth, 203);
}

- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section {
    return 5.0;
}
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section {
    return 1.0;
}



#pragma mark - getter

- (NSMutableArray *)dataSourceList {
    if (!_dataSourceList) {
        _dataSourceList = [NSMutableArray array];
    }
    return _dataSourceList;
}


- (void)dealloc
{
    NSLog(@"%s", __func__);
}

@end
