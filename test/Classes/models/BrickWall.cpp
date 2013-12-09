//
//  BrickWall.cpp
//  test
//
//  Created by Sun Xi on 12/4/13.
//
//

#include "BrickWall.h"

USING_NS_CC;

BrickWall::~BrickWall() {
    
}

BrickWall::BrickWall():_speed(0) {
    
}

BrickWall* BrickWall::create(SCENETYPE style) {
    BrickWall* brickwall = new BrickWall();
    if (brickwall && brickwall->init()) {
        brickwall->autorelease();
    }
    return brickwall;
}

bool BrickWall::init() {
    if(CCSprite::init()) {
        CCSprite* bricksp = CCSprite::create("Icon.png");
        m_obContentSize = bricksp->getContentSize();
        CCSize winsize = CCDirector::sharedDirector()->getWinSize();
        int brickcount = winsize.height/m_obContentSize.height + 2;
        this->addChild(bricksp);
        _bricks.addObject(bricksp);
        for (int i = 1; i < brickcount; ++i) {
            CCSprite* sp = CCSprite::create("Icon.png");
            sp->setPosition(ccp(0,m_obContentSize.height*i));
            this->addChild(sp);
            _bricks.addObject(sp);
        }
    }
    this->scheduleUpdate();
    return true;
}

void BrickWall::update(float delta) {
    this->setPosition(ccpAdd(this->getPosition(), ccp(0,-_speed)));
    if (_bricks.count() > 0 && _speed > 0) {
        CCSize winsize = CCDirector::sharedDirector()->getWinSize();
        CCSprite* sp = dynamic_cast<CCSprite*>(_bricks.objectAtIndex(0));
        CCPoint pos = this->convertToWorldSpace(sp->getPosition());
        CCPoint locpos = CCDirector::sharedDirector()->convertToUI(pos);
        if (locpos.y > winsize.height + m_obContentSize.height) {
            sp->setPosition(ccpAdd(sp->getPosition(),ccp(0,m_obContentSize.height*_bricks.count())));
            _bricks.removeObjectAtIndex(0,false);
            _bricks.addObject(sp);
        }
    }
}