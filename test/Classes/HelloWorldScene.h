#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameController.h"

class Player;

class HelloWorld : public cocos2d::CCLayer
{
public:
    
    friend class GameController;
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)

    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    virtual void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    void moveFinish();
    
protected:
    
    cocos2d::CCArray* _enemys;
    
    HelloWorld():_isTouching(false) {};
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCSize, _wallSize, WallSize);
    
    CC_SYNTHESIZE_READONLY(int, _wallSpeed, WallSpeed);
    
    Player* _player;
    
    bool _isTouching;
    
};

#endif // __HELLOWORLD_SCENE_H__
