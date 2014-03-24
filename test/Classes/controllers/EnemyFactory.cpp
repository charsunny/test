//
//  EnemyFactory.cpp
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#include "EnemyFactory.h"
#include "Enemy.h"
#include "MonsterEnemy.h"
#include "Chain.h"

EnemyFactory* EnemyFactory::_instance = NULL;

EnemyFactory* EnemyFactory::sharedFactory() {
    if (_instance == NULL) {
        _instance = new EnemyFactory;
    }
    return _instance;
}

Enemy* EnemyFactory::createEnemy(ENEMYTYPE enmeytype) {
    Enemy* enmey = NULL;
    switch (enmeytype) {
        case ENEMY_MONSTER:
            enmey = new MonsterEnmey;
            break;
        case ENEMY_CHAIN:
            enmey = new Chain();
        default:
            break;
    }
    if (enmey != NULL && enmey->init()) {
        enmey->autorelease();
    }
    return enmey;
}