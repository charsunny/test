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

class Enemy;
class MagicStuff;

class Player : public cocos2d::CCSprite
{
    
public:
    
    static Player* create();
    
    virtual bool init();
    
    void playAnimation(PlayerStateEnum state);
    
    bool touchWithEnemey(Enemy* enemey);
    
    bool getMagicStuff(MagicStuff* stuff);
    
    ~Player(){};
    
    int getSpeed() {
        return _speed;
    };
    
    void setSpeed(int speed);
    
protected:
    
    cocos2d::CCAnimation* createAnimationByState(PlayerStateEnum state);
    
    CC_SYNTHESIZE_READONLY(PlayerStateEnum, _playerState, PlayerState);
    
    int _speed;
    
    cocos2d::CCAnimation* _currectAnimate;
    
    Player();
    
};

#endif /* defined(__test__Player__) */
