//
//  Chain.cpp
//  test
//
//  Created by Sun Xi on 12/30/13.
//
//

#include "Chain.h"

using namespace cocos2d;

bool Chain::init() {
    if (Enemy::init()) {
        CCSprite* bricksp = CCSprite::create("chain.png");
        m_obContentSize = bricksp->getContentSize();
        this->addChild(bricksp);
    }
    return true;
}

Bullet* Chain::fire() {
    return NULL;
}

void Chain::playAnimation(EnemyStateEnum state) {
    
}

CCAnimate* Chain::createAnimationByState(EnemyStateEnum state) {
    return NULL;
}
