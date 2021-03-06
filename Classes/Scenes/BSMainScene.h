#ifndef __MAIN_SCENE_SCENE_H__
#define __MAIN_SCENE_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

    void GoToNewGame(cocos2d::Ref *sender);
    void GoToChooseLevel(cocos2d::Ref *sender);
    void GoToSetting(cocos2d::Ref *sender);

    ////////////////////////// GO TO tempScene
    void GoToTempScene(cocos2d::Ref *sender);
	void GoToTempScene2(cocos2d::Ref *sender);
    /////////////////////////
};

#endif // __MAIN_SCENE_SCENE_H__
