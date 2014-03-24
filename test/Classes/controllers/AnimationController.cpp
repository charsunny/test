//
//  AnimationController.cpp
//  test
//
//  Created by Sun Xi on 12/8/13.
//
//

#include "AnimationController.h"

using namespace cocos2d;

AnimationController* AnimationController::_instance = NULL;

AnimationController* AnimationController::sharedAnimationController() {
    if (_instance == NULL) {
        _instance = new AnimationController();
    }
    return _instance;
}

AnimationController::AnimationController() {
    _animations = new CCDictionary();
}

AnimationController::~AnimationController() {
    delete [] _animations;
}

void AnimationController::addAnimation(const char* plist, int framecount, const char* name) {
    CCDictElement* el;
    bool hasKey = false;
    CCDICT_FOREACH(_animations, el) {
        if(!strcmp(el->getStrKey(),plist)) {
            hasKey = true;
            break;
        }
    }
    if (!hasKey) {
        CCSpriteFrameCache* kCCSpriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
        CCAnimation *animation = CCAnimation::create();
        CCString* string = new CCString;
        string->initWithFormat("%s.plist", plist);
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(string->getCString());
        for (int i = 1; i <= framecount; i++) {
            CCString* name = CCString::createWithFormat("grossini_dance_generic_%02d.png",i);
            CCSpriteFrame* frame = kCCSpriteFrameCache->spriteFrameByName(name->getCString());
            animation->addSpriteFrame(frame);
        }
        animation->setDelayPerUnit(0.3f);
        //animation->setRestoreOriginalFrame(true);
        _animations->setObject(new CCString(name), plist);
        CCAnimationCache::sharedAnimationCache()->addAnimation(animation, name);
    }
}

void AnimationController::addAnimation(const char* filename, int framecount, int col, const char* aniName) {
    CCDictElement* el;
    bool hasKey = false;
    CCDICT_FOREACH(_animations, el) {
        if(!strcmp(el->getStrKey(),filename)) {
            hasKey = true;
            break;
        }
    }
    CCSprite* bgSprite = CCSprite::create(filename);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(bgSprite->displayFrame(), filename);
    CCSize spsize = bgSprite->getContentSize();
    int row = (framecount%col==0)?(framecount/col):(framecount/col+1);
    float width = spsize.width/col;
    float height = spsize.height/row;
    CCAnimation *animation = CCAnimation::create();
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (i*col + j >= framecount) {
                continue;
            }
            CCSpriteFrame* spriteframe = CCSpriteFrame::create(filename, CCRectMake(i*width, j*height, width, height));
            animation->addSpriteFrame(spriteframe);
        }
    }
    //animation->setDelayPerUnit(0.2f);
    //animation->setRestoreOriginalFrame(true);
    _animations->setObject(new CCString(aniName), filename);
    CCAnimationCache::sharedAnimationCache()->addAnimation(animation, aniName);
}

CCAnimation* AnimationController::getAnimation(const char* name) {
    return CCAnimationCache::sharedAnimationCache()->animationByName(name);
}