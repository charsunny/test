//
//  GameController.h
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#ifndef __test__GameController__
#define __test__GameController__

#include "cocos2d.h"
#include "HelloWorldScene.h"

/**
    the class to control the game logic and other things
    must attach with the game scene
*/

class HelloWorld;
class GameController : public cocos2d::CCObject {
    
public:
    
    GameController(HelloWorld* layer);
    
    void addEnemy();
    
    void update(float delta);
    
private:
    HelloWorld* _layer;
};

#endif /* defined(__test__GameController__) */
