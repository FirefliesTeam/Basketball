#ifndef __TEMP_SCENE2_H__
#define __TEMP_SCENE2_H__

#include <iostream>
#include "BasketballObjects\BOBall.h"
#include "BasketballObjects\BOPlank.h"
#include "cocos2d.h"

class TempScene2 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TempScene2);

    void GoBack(cocos2d::Ref *sender);


	void edgeBoxInit();
	void setEventListeners(BBall *ball);
	bool startBallLaunching(cocos2d::Touch *touch, cocos2d::Event *_event);
	void setBallImpulse(cocos2d::Touch *touch, cocos2d::Event *_event);
	void launchBall(cocos2d::Touch *touch, cocos2d::Event *_event);
private:
	BBall *ball;
	std::vector<BObject*> MetalPlanks;
};

#endif // __TEMP_SCENE2_H__
