#import <GoogleMobileAds/GADAdSize.h>

/// Returns a GADAdSize with the given width and a Google-optimized height to create a banner ad.
/// The size returned has an aspect ratio similar to that of kGADAdSizeBanner, suitable for
/// anchoring near the top or bottom of your app. The height is never larger than 15% of the
/// device's portrait height and never smaller than 50 points. This function always returns the same
/// height for any width / device combination.
GAD_EXTERN GADAdSize GADPortraitAnchoredAdaptiveBannerAdSizeWithWidth(CGFloat width);

/// Returns a GADAdSize with the given width and a Google-optimized height to create a banner ad.
/// The size returned has aspect ratio similar to that of kGADAdSizeBanner, suitable for
/// anchoring near the top or bottom of your app. The height is never larger than 15% of the
/// device's landscape height and never smaller than 50 points. This function always returns the
/// same height for any width / device combination.
GAD_EXTERN GADAdSize GADLandscapeAnchoredAdaptiveBannerAdSizeWithWidth(CGFloat width);

/// Returns a GADAdSize with the given width and a Google-optimized height. This is a convenience
/// function to return GADPortraitAnchoredAdaptiveBannerAdSizeWithWidth or
/// GADLandscapeAnchoredAdaptiveBannerAdSizeWithWidth based on the current interface orientation.
GAD_EXTERN GADAdSize GADCurrentOrientationAnchoredAdaptiveBannerAdSizeWithWidth(CGFloat width);
