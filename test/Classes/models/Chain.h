//
//  Chain.h
//  test
//
//  Created by Sun Xi on 12/30/13.
//
//

#ifndef __test__Chain__
#define __test__Chain__

#include "Enemy.h"

class Chain : public Enemy {

public:
    
    Chain(){_touchable = false;};
    
    virtual bool init();
    
    virtual Bullet* fire();
    
    virtual void playAnimation(EnemyStateEnum state);
    
protected:
    
    virtual cocos2d::CCAnimate* createAnimationByState(EnemyStateEnum state);
    
};

#endif /* defined(__test__Chain__) */
