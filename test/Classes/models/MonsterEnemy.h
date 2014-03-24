//
//  MonsterEnemy.h
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#ifndef __test__MonsterEnemy__
#define __test__MonsterEnemy__

#include "Enemy.h"

class MonsterEnmey : public Enemy {
    
public:
    
    MonsterEnmey(){_touchable = false;};
    
    virtual bool init();
    
    virtual Bullet* fire();
    
    virtual void playAnimation(EnemyStateEnum state);
    
protected:
    
    virtual cocos2d::CCAnimate* createAnimationByState(EnemyStateEnum state);
};

#endif /* defined(__test__MonsterEnemy__) */
