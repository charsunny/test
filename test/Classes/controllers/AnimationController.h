//
//  AnimationController.h
//  test
//
//  Created by Sun Xi on 12/8/13.
//
//

#ifndef __test__AnimationController__
#define __test__AnimationController__

#include "cocos2d.h"

class AnimationController {
    
public:
    
    static AnimationController* sharedAnimationController();
    
    cocos2d::CCAnimation* getAnimation(const char* name);
    
    void addAnimation(const char* plist, int framecount, const char* name);
    
    void addAnimation(const char* filename, int framecount, int col, const char* aniName);
    
    ~AnimationController();
    
protected:
    
    AnimationController();
    
    static AnimationController* _instance;
    
    cocos2d::CCDictionary* _animations;
    
};


#endif /* defined(__test__AnimationController__) */
