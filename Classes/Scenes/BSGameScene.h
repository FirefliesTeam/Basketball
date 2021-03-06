#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "BasketballObjects/BOBall.h"
//#include "BasketballObjects/BOSingleBall.h"
#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void GoBack(cocos2d::Ref *sender);

	//initialisation of edgeBox for debuging
	void edgeBoxInit();

	void setEventListeners();

	bool startBallLaunching(cocos2d::Touch *touch, cocos2d::Event *_event);
	void setBallImpulse(cocos2d::Touch *touch, cocos2d::Event *_event);
	void launchBall(cocos2d::Touch *touch, cocos2d::Event *_event);

private:
	//BSingleBall *ball;
	BBall *ball;
};

#endif // __GAME_SCENE_H__
