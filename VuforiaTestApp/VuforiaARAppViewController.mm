//
//  VuforiaARAppViewController.m
//  VuforiaTestApp
//
//  Created by Eduardo on 2/3/15.
//  Copyright (c) 2015 Eduardo. All rights reserved.
//

#import "VuforiaARAppViewController.h"

#import <QCAR/QCAR.h>
#import <QCAR/TrackerManager.h>
#import <QCAR/ImageTracker.h>
#import <QCAR/Trackable.h>
#import <QCAR/DataSet.h>
#import <QCAR/CameraDevice.h>

@implementation VuforiaARAppViewController

-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil{
    self = [super initWithNibName:nibNameOrNil bundle:nibNameOrNil];
    if(self){
        vapp=[[VuforiaApplicationSession alloc] initWithDelegate:self];
        
        self.title = @"RA+ App Test";
        CGRect screenBounds = [[UIScreen mainScreen] bounds];
        viewFrame = screenBounds;
        
        if (YES == vapp.isRetinaDisplay) {
            viewFrame.size.width *= 2.0;
            viewFrame.size.height *= 2.0;
        }
        
        dataSetCurrent=nil;
        extendedTrackingIsOn=YES;
        
        tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(autofocus:)];
        
        [[NSNotificationCenter defaultCenter]
            addObserver:self
            selector:@selector(pauseAR)
            name:UIApplicationWillResignActiveNotification
            object:nil];
        
        [[NSNotificationCenter defaultCenter]
            addObserver:self
            selector:@selector(resumeAR)
            name:UIApplicationDidBecomeActiveNotification
            object:nil];
    }
    return self;
    
}

-(void)pauseAR{
    NSError *error =nil;
    if (! [vapp pauseAR:&error]) {
        NSLog(@"error pausing AR: %@", [error description]);
    }
}

-(void)resumeAR{
    NSError *error = nil;
    
    if (![vapp resumeAR:&error]) {
        NSLog(@"Error resuming AR: %@",[error description]);
    }
    
    QCAR::CameraDevice::getInstance().setFlashTorchMode(false);
    
}

-(void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
}

-(void)loadView{
    eaglView
}

@end
