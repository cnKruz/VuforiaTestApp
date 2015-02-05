//
//  VuforiaARAppViewController.h
//  VuforiaTestApp
//
//  Created by Eduardo on 2/3/15.
//  Copyright (c) 2015 Eduardo. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "ImageTargetsEAGLView.h"
#import "VuforiaAppSession.h"
#import <QCAR/DataSet.h>

@interface VuforiaARAppViewController : UIViewController <VuforiaApplicationControl>{
    CGRect viewFrame;
    //ImageTargetsEAGLView* eaglView;
    QCAR::DataSet*  dataSetCurrent;
    QCAR::DataSet*  dataSetTarmac;
    QCAR::DataSet*  dataSetStonesAndChips;
    UITapGestureRecognizer * tapGestureRecognizer;
    VuforiaApplicationSession * vapp;
    
    BOOL switchToTarmac;
    BOOL switchToStonesAndChips;
    BOOL extendedTrackingIsOn;
    
}

@end
