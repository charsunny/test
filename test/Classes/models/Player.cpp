//
//  Player.cpp
//  test
//
//  Created by Sun Xi on 11/20/13.
//
//

#include "Player.h"
#include "Enemy.h"
#include "AnimationController.h"

using namespace cocos2d;

Player::Player():_playerState(PLAYER_RUNLEFT),_speed(10) {
    
}

Player* Player::create() {
    Player* player = new Player();
    if (player && player->init()) {
        player->autorelease();
    }
    return player;
}

bool Player::init() {
    if (CCSprite::init()) {
        playAnimation(_playerState);
    }
    return true;
}

void Player::setSpeed(int speed) {
    _speed = speed;
    if (_currectAnimate) {
        _currectAnimate->setDelayPerUnit(1/float(speed));
        this->runAction(CCRepeatForever::create(CCAnimate::create(_currectAnimate)));
    }
}

bool Player::touchWithEnemey(Enemy* enemey) {
    if (enemey->boundingBox().intersectsRect(this->boundingBox())) {
        return true;
    }
    return false;
}

bool Player::getMagicStuff(MagicStuff* stuff) {
    return false;
}

void Player::playAnimation(PlayerStateEnum state) {
    _playerState = state;
    AnimationController::sharedAnimationController()->addAnimation("horse.png", 9, 3, "horserun");
//    AnimationController::sharedAnimationController()->addAnimation("grossini-generic", 14, "playerrun");
    _currectAnimate = createAnimationByState(state);
    _currectAnimate->setDelayPerUnit(1/float(_speed));
    CCAnimationFrame* frame = (CCAnimationFrame*)(_currectAnimate->getFrames()->objectAtIndex(0));
    if (frame) {
        m_obContentSize = frame->getSpriteFrame()->getRect().size;
    }
    this->runAction(CCRepeatForever::create(CCAnimate::create(_currectAnimate)));
}

CCAnimation* Player::createAnimationByState(PlayerStateEnum state) {
    switch (state) {
        case PLAYER_RUNLEFT: {
            return AnimationController::sharedAnimationController()->getAnimation("horserun");
        }
            break;
        case PLAYER_RUNRIGHT:
            break;
        case PLAYER_JUMP:
            break;
        case PLAYER_DIE:
            break;
        default:
            break;
    }
    return NULL;
}
