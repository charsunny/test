#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "BrickWall.h"
#include "Player.h"

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

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    BrickWall* leftwall = BrickWall::create(SCENE_DEFAULT);
    leftwall->setPosition(ccp(leftwall->getContentSize().width/2, 0));
    this->addChild(leftwall);
    leftwall->setSpeed(3);
    
    CCSize wallsize = leftwall->getContentSize();
    
    BrickWall* rightwall = BrickWall::create(SCENE_DEFAULT);
    rightwall->setPosition(ccp(size.width - rightwall->getContentSize().width/2, 0));
    this->addChild(rightwall);
    rightwall->setSpeed(3);
    
    _player = Player::create();
    
    CCSize playerSize = _player->getContentSize();
    _player->setScale(0.5);
    _player->setRotation(90);
    _player->setPosition(ccp(wallsize.width + playerSize.width/4 ,size.height/4));
    this->addChild(_player);
    
    this->setTouchEnabled(true);
    
    return true;
}

void HelloWorld::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
    _player->setPosition(pTouch->getLocation());
    _player->setFlipY(!_player->isFlipY());
    return false;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}