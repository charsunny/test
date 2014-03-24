//
//  Enemy.h
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#ifndef __test__Enemy__
#define __test__Enemy__

#include "cocos2d.h"

typedef enum {
    ENEMY_MOVE = 0,
    ENEMY_ATTACT,
    ENEMY_DIE
} EnemyStateEnum;

class Bullet;

class Enemy : public cocos2d::CCSprite
{
    
public:
    
    Enemy():_touchable(true){};
    
    virtual bool init();
    
    virtual ~Enemy(){};
    
    virtual Bullet* fire() = 0;
    
    virtual void playAnimation(EnemyStateEnum state) = 0;
    
    virtual void update(float delta);
    
    virtual bool isTouchable() {return _touchable;};
    
protected:
    
    CC_SYNTHESIZE(float, _speed, Speed);
    
    bool _touchable;
    
    //CC_SYNTHESIZE(float, _hp, Hp);
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, _bullets, Bullets);
    
    virtual cocos2d::CCAnimate* createAnimationByState(EnemyStateEnum state) = 0;
    
    CC_SYNTHESIZE_READONLY(EnemyStateEnum, _enemyState, EnemyState);
    
};

#endif /* defined(__test__Enemy__) */
