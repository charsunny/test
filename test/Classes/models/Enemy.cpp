//
//  Enemy.cpp
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#include "Enemy.h"

bool Enemy::init() {
    if (CCSprite::init()) {
        
    }
    return true;
}

void Enemy::update(float delta) {
    if (_speed > 0) {
        this->setPosition(ccpAdd(this->getPosition(), ccp(0,-_speed)));
    }
}
