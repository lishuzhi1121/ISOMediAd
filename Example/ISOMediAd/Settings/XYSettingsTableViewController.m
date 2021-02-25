//
//  XYSettingsTableViewController.m
//  XYAdPlatform_Example
//
//  Created by SandsLee on 2020/12/24.
//  Copyright © 2020 QuVideoInc. All rights reserved.
//

#import "XYSettingsTableViewController.h"
#import <XYADFramework/XYAdPlatform.h>
#import "XYAdsCommonDefine.h"

@interface XYSettingsTableViewController ()

@property (weak, nonatomic) IBOutlet UISwitch *vipSwitch;

@end

@implementation XYSettingsTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    self.vipSwitch.on = [[NSUserDefaults standardUserDefaults] boolForKey:VIP_IS_ON_KEY];
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)vipSwitchChanged:(UISwitch *)sender {
    [[NSUserDefaults standardUserDefaults] setBool:sender.isOn forKey:VIP_IS_ON_KEY];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [[XYAdPlatform sharedInstance] enableAd:!sender.isOn];
}

@end
