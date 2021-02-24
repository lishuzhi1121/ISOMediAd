//
//  XYWebImageDownloader.h
//  Pods
//
//  Created by hongru qi on 2017/5/5.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, XYImageCacheType) {
    /**
     * The image wasn't available the SDWebImage caches, but was downloaded from the web.
     */
    XYImageCacheTypeNone,
    /**
     * The image was obtained from the disk cache.
     */
    XYImageCacheTypeDisk,
    /**
     * The image was obtained from the memory cache.
     */
    XYImageCacheTypeMemory
};

typedef void(^XYWebImageCompletionBlock)(UIImage *image, NSError *error, XYImageCacheType cacheType, NSURL *imageURL);
typedef void(^XYWebImageQueryCompletedBlock)(UIImage *image, XYImageCacheType cacheType);
typedef UIImage *(^XYWebImageTransformBlock)(UIImage *image, NSURL *url);

@interface XYWebImageDownloader : NSObject

+ (XYWebImageDownloader *)sharedInstance;

- (void)xy_downloadImageWithURL:(NSURL *)url completed:(XYWebImageCompletionBlock)completedBlock;

- (void)xy_queryCacheForURL:(NSURL *)url done:(XYWebImageQueryCompletedBlock)doneBlock;

- (NSString *)xy_filePathForURL:(NSURL *)url;

- (void)xy_clearDisk;

- (UIImage *)xy_imageFromCacheForKey:(NSString *)key;

- (void)xy_setMaxMemoryCountLimit:(NSInteger )limit;
@end
