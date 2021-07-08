# XYMediEventAdapter

[![CI Status](https://img.shields.io/travis/irobbin1024/XYMediEventAdapter.svg?style=flat)](https://travis-ci.org/irobbin1024/XYMediEventAdapter)
[![Version](https://img.shields.io/cocoapods/v/XYMediEventAdapter.svg?style=flat)](https://cocoapods.org/pods/XYMediEventAdapter)
[![License](https://img.shields.io/cocoapods/l/XYMediEventAdapter.svg?style=flat)](https://cocoapods.org/pods/XYMediEventAdapter)
[![Platform](https://img.shields.io/cocoapods/p/XYMediEventAdapter.svg?style=flat)](https://cocoapods.org/pods/XYMediEventAdapter)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

XYMediEventAdapter is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'XYMediEventAdapter'
```
## 用法

### 业务端配置

```objective-c
self.eventService = [XYEventService new];
[XYMediEventManager sharedInstance].eventAdapter = self.eventService;
```

XYEventService 是业务层的一个发送埋点的类，实现了 XYAPIProtocol 协议

```objective-c
@interface XYEventService : NSObject<XYMediEventProtocol>

@property (nonatomic, strong) void(^sendCallback)(NSString * name, NSDictionary * attribute);

@end
```

### 使用端用法

```objective-c
XYMediAppEventSend(@"test", @{@"key": @"value"});
[[XYMediEventManager sharedInstance] appEventWithName:@"test" attribute:@{@"key": @"value"}]
```

## Author

irobbin1024, longbin.lai@quvideo.com

## License

XYMediEventAdapter is available under the MIT license. See the LICENSE file for more info.
