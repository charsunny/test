#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "BrickWall.h"
#include "Player.h"
#include "EnemyFactory.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bg.m4a", true);
    
    _enemys = new CCArray;
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("background.jpg");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    _wallSpeed = 5;
    
    BrickWall* leftwall = BrickWall::create(SCENE_DEFAULT, WALL_LEFT);
    leftwall->setPosition(ccp(leftwall->getContentSize().width/2, 0));
    this->addChild(leftwall);
    leftwall->setSpeed(_wallSpeed);
    
    _wallSize = leftwall->getContentSize();
    
    BrickWall* rightwall = BrickWall::create(SCENE_DEFAULT, WALL_RIGHT);
    rightwall->setPosition(ccp(size.width - rightwall->getContentSize().width/2, 0));
    this->addChild(rightwall);
    rightwall->setSpeed(_wallSpeed);
    
    _player = Player::create();
    _player->setScale(0.5f);
    _player->setRotation(180);
    _player->setFlipX(true);
    CCRect playerBounds = _player->boundingBox();
    //CCLog("pos:x:%f,y:%f",playerSize.width, playerSize.height);
    _player->setPosition(ccp(_wallSize.width + playerBounds.size.width ,size.height/4));
    this->addChild(_player);
    this->setTouchEnabled(true);
    
    GameController* controller = new GameController(this);
    
    controller->addEnemy();
    
    return true;
}

void HelloWorld::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
    if (!_isTouching) {
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        CCRect playerBounds = _player->boundingBox();
        ccBezierConfig c;
        c.controlPoint_1 = ccp(size.width/2, size.height/2);
        c.controlPoint_2 = ccp(size.width/2, size.height/2);
        c.endPosition = ccp(!_player->isFlipX()?(_wallSize.width+playerBounds.size.width):(size.width-_wallSize.width), size.height/4);
        _player->runAction(CCSequence::create(CCBezierTo::create(0.5f, c),CCCallFunc::create(this, callfunc_selector(HelloWorld::moveFinish)), NULL));
        _player->setFlipX(!_player->isFlipX());
        _isTouching = true;
    }
    return false;
}

void HelloWorld::moveFinish() {
    _isTouching = false;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
