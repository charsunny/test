//
//  GameController.cpp
//  test
//
//  Created by Sun Xi on 12/10/13.
//
//

#include "GameController.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyFactory.h"

USING_NS_CC;

GameController::GameController(HelloWorld* layer) {
    _layer = layer;
    CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this, 0, false);
}

void GameController::addEnemy() {
    
    Enemy* enmey =  EnemyFactory::sharedFactory()->createEnemy(ENEMY_CHAIN);
    
    enmey->setPosition(ccp(_layer->_wallSize.width + enmey->getContentSize().width/2,
                           CCDirector::sharedDirector()->getWinSize().height));
    
    enmey->setSpeed(_layer->getWallSpeed());
    
    _layer->addChild(enmey);
    
    _layer->_enemys->addObject(enmey);
}

void GameController::update(float delta) {
    CCObject* obj;
    CCARRAY_FOREACH(_layer->_enemys, obj) {
        Enemy* enemy = dynamic_cast<Enemy*>(obj);
        enemy->update(delta);
        
        if (_layer->_player->touchWithEnemey(enemy)) {
            enemy->removeFromParent();
            _layer->_enemys->removeObject(obj);
            addEnemy();
            break;
        }
        
        if (enemy->getPosition().y < -20) {
            enemy->removeFromParent();
            _layer->_enemys->removeObject(obj);
            addEnemy();
            break;
        }
    }
}

