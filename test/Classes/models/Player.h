//
//  Player.h
//  test
//
//  Created by Sun Xi on 11/20/13.
//
//

#ifndef __test__Player__
#define __test__Player__

#include "cocos2d.h"

typedef enum {
    PLAYER_RUNLEFT = 0,
    PLAYER_RUNRIGHT,
    PLAYER_JUMP,
    PLAYER_DIE
} PlayerStateEnum;

class Enemey;
class MagicStuff;

class Player : public cocos2d::CCSprite {
    
public:
    
    static Player* create();
    
    virtual bool init();
    
    bool attactByEnemey(Enemey* enemey);
    
    bool getMagicStuff(MagicStuff* stuff);
    
    ~Player(){};
    
protected:
    
    cocos2d::CCAnimate* createAnimationByState(PlayerStateEnum state);
    
    CC_SYNTHESIZE(PlayerStateEnum, _playerState, PlayerState);
    
    Player();
    
};

#endif /* defined(__test__Player__) */
