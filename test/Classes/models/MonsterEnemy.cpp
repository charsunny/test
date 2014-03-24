//
//  MonsterEnemy.cpp
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#include "MonsterEnemy.h"

using namespace cocos2d;

bool MonsterEnmey::init() {
    if (Enemy::init()) {
        CCSprite* bricksp = CCSprite::create("Icon.png");
        m_obContentSize = bricksp->getContentSize();
        this->addChild(bricksp);
    }
    return true;
}

Bullet* MonsterEnmey::fire() {
    return NULL;
}

void MonsterEnmey::playAnimation(EnemyStateEnum state) {

}

CCAnimate* MonsterEnmey::createAnimationByState(EnemyStateEnum state) {
    return NULL;
}