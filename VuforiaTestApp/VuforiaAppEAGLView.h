//
//  VuforiaAppEAGLView.h
//  VuforiaTestApp
//
//  Created by Eduardo on 2/4/15.
//  Copyright (c) 2015 Eduardo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QCAR/UIGLViewProtocol.h>

#import "VuforiaAppSession.h"
#import "Texture.h"
#import "SampleApplication3DModel.h"

#define NUM_AUGMENTATION_TEXTURES 1
@interface VuforiaAppEAGLView : UIView <UIGLViewProtocol>{
    @private
    //openGL context
    EAGLContext *context;
    //renders for this view
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
    GLuint depthRenderbuffer;
    //shader handles
    GLuint shaderProgramID;
    GLuint vertexHandle;
    GLuint normalHandle;
    GLuint textureCoordHandle;
    GLuint mvpMatrixHandle;
    GLint textSampler2DHandle;
    
    Texture *augmentationTexture[NUM_AUGMENTATION_TEXTURES];
    
    bool offTargetTrakingEnabled;
    SampleApplication3DModel *buildingModel;
    
    VuforiaApplicationSession *vapp;
    
}

-(id)initWithFrame:(CGRect)frame appSession:(VuforiaApplicationSession *)app;
-(void)finishOpenGLESComands;
-(void)freeOpenGLESResources;
-(void) setOffTargerTrakingMode:(BOOL) enabled;

@end
