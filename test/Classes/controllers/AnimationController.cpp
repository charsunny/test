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
        _animations->setObject(new CCString(name), plist);
        for (int i = 1; i <= framecount; i++) {
            CCString* name = CCString::createWithFormat("grossini_dance_generic_%02d.png",i);
            CCSpriteFrame* frame = kCCSpriteFrameCache->spriteFrameByName(name->getCString());
            animation->addSpriteFrame(frame);
        }
        animation->setDelayPerUnit(0.3f);
        //animation->setRestoreOriginalFrame(true);
        CCAnimationCache::sharedAnimationCache()->addAnimation(animation, name);
    }
}

CCAnimation* AnimationController::getAnimation(const char* name) {
    return CCAnimationCache::sharedAnimationCache()->animationByName(name);
}