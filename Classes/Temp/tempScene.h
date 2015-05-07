#ifndef __TEMP_SCENE_H__
#define __TEMP_SCENE_H__

#include "cocos2d.h"

class TempScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TempScene);

    void GoBack(cocos2d::Ref *sender);

private:

    cocos2d::PhysicsWorld* _world;

    void setPhysicsWorld(cocos2d::PhysicsWorld* world) { _world = world; }

};

#endif // __TEMP_SCENE_H__
