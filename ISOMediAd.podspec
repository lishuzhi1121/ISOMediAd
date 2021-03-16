#
# Be sure to run `pod lib lint ISOMediAd.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ISOMediAd'
  s.version          = '1.1.0'
  s.summary          = 'ISOMediAd 广告中台隔离app专用版本.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
基于XYAdPlatform、XYAdCore封装的广告中台，打成framework供隔离环境的app专用。
                       DESC

  s.homepage         = 'https://github.com/lishuzhi1121/ISOMediAd'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'lishuzhi1121' => 'lishuzhi1121@163.com' }
  s.source           = { :git => 'https://github.com/lishuzhi1121/ISOMediAd.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'
  s.static_framework = true


  s.source_files = 'ISOMediAd/Classes/**/*'
  s.vendored_frameworks = 'ISOMediAd/PrivateSDK/ApplinsSDK.framework','ISOMediAd/PrivateSDK/JRAnalysisKit.framework','ISOMediAd/PrivateSDK/XYADFramework.framework'
  # s.resource_bundles = {
  #   'ISOMediAd' => ['ISOMediAd/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  #系统组件
  s.library = "resolv"
  s.frameworks = 'AdSupport'

  # 广告商SDK
  s.dependency 'FBAudienceNetwork'

  s.dependency 'Google-Mobile-Ads-SDK', '7.67.0'
  s.dependency 'GoogleMobileAdsMediationFacebook'
  s.dependency 'GoogleMobileAdsMediationTestSuite'

  s.dependency 'MintegralAdSDK/NativeAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/InterstitialVideoAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/RewardVideoAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/InterstitialAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/BannerAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/SplashAd', '~> 6.7.2.0'
  s.dependency 'MintegralAdSDK/NativeAdvancedAd', '~> 6.7.2.0'
  
  #s.dependency 'mopub-ios-sdk', '5.12.1'
  
  #s.dependency 'VungleSDK-iOS', '6.9.1'

  # 第三方库
  s.dependency 'AFNetworking', '~> 4.0'
  s.dependency 'SDWebImage'
  s.dependency 'SVProgressHUD', '~> 2.2.5'
  s.dependency 'Mantle', '~> 2.1.6'
  s.dependency 'Reachability', '~> 3.2'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  s.dependency 'ReactiveObjC'
  s.dependency 'QVEditorKit/Core'


end
