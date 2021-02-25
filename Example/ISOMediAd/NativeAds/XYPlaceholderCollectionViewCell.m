//
//  XYPlaceholderCollectionViewCell.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/23.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYPlaceholderCollectionViewCell.h"
#import "UIColor+XYRandom.h"

@interface XYPlaceholderCollectionViewCell ()

@property (weak, nonatomic) IBOutlet UILabel *placeholderLabel;

@end

@implementation XYPlaceholderCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    
    self.backgroundColor = [UIColor _randomColor];
}

- (void)setText:(NSString *)text {
    _text = text;
    
    self.placeholderLabel.text = text;
}


@end
