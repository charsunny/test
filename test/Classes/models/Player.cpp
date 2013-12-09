//
//  Player.cpp
//  test
//
//  Created by Sun Xi on 11/20/13.
//
//

#include "Player.h"
#include "AnimationController.h"

using namespace cocos2d;

Player::Player():_playerState(PLAYER_RUNLEFT) {
    
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
        AnimationController::sharedAnimationController()->addAnimation("grossini-generic", 14, "playerrun");
        CCAnimate* animate = createAnimationByState(_playerState);
        CCAnimationFrame* frame = (CCAnimationFrame*)(animate->getAnimation()->getFrames()->objectAtIndex(0));
        if (frame) {
            m_obContentSize = frame->getSpriteFrame()->getRect().size;
        }
        this->runAction(CCRepeatForever::create(animate));
    }
    return true;
}

bool Player::attactByEnemey(Enemey* enemey) {
    return false;
}

bool Player::getMagicStuff(MagicStuff* stuff) {
    return false;
}

CCAnimate* Player::createAnimationByState(PlayerStateEnum state) {
    switch (state) {
        case PLAYER_RUNLEFT: {
            return CCAnimate::create(AnimationController::sharedAnimationController()->getAnimation("playerrun"));
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
