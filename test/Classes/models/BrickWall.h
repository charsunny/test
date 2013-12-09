//
//  BrickWall.h
//  test
//
//  Created by Sun Xi on 12/4/13.
//
//

#ifndef __test__BrickWall__
#define __test__BrickWall__

#include "cocos2d.h"

typedef enum {
    SCENE_DEFAULT = 0,
    SCENE_FORREST
} SCENETYPE;

class BrickWall : public cocos2d::CCSprite {
    
public:
    
    static BrickWall* create(SCENETYPE style);
    
    bool init();
    
    ~BrickWall();
    
    virtual void update(float delta);
    
protected:
    
    BrickWall();
    
    CC_SYNTHESIZE(float, _speed, Speed);
    
    CC_SYNTHESIZE(cocos2d::CCArray, _bricks, Bricks);

};

#endif /* defined(__test__BrickWall__) */
