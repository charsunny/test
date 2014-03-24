//
//  EnemyFactory.h
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#ifndef __test__EnemyFactory__
#define __test__EnemyFactory__

#include "cocos2d.h"
#include "Enemy.h"

typedef enum {
    ENEMY_MONSTER = 0,
    ENEMY_CHAIN,
    ENEMY_DRAGON
} ENEMYTYPE;

class EnemyFactory {
    
public:
    
    static EnemyFactory* sharedFactory();
    
    Enemy* createEnemy(ENEMYTYPE enmeytype);
    
protected:
    
    static EnemyFactory* _instance;
    
};

#endif /* defined(__test__EnemyFactory__) */
