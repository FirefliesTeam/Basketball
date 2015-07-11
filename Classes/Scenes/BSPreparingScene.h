#ifndef __PREPARING_SCENE_H__
#define __PREPARING_SCENE_H__

#include <iostream>
#include <fstream>
#include "cocos2d.h"
#include "../BasketballObjects/BOBall.h"
#include "../BasketballObjects/BOPlank.h"
#include "../BasketballObjects/BOGrid.h"
#include "../Scenes/BSMainScene.h"
#include "../BasketballObjects/BOBall.h"
#include "../Definitions/DefForScenes.h"


#include "cocos2d.h"

// The class defines scene, where player must put planks on map
//------------------------------------------------------------- 


class PreparingScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PreparingScene);

    void GoBack(cocos2d::Ref *sender);
    
    //Create level from file
    bool createLevel();
    
    //Define the level number to create
    void inputLevelNumber(char num);
    
    //First touch: Open Plank store to put plank on touch place 
    void openPlankStore();
    
    //Secong touch: To put chosen plank from store on scene(if touch was on plank) or close store (if touch wasn't on plank store area)
    void putPlank();
    
    //First touch: open menu to change some plank rotation or delete it (if touch was on some player's plank)
    void OpenPlankMenu();
    
    //Second touch: change some plank rotation or delete it by menu items
    void rotatePlank();

private:
	BBall *ball;
	std::vector<BObject*> SceneObjects;
	char level_number;
	// true when plank menu is open by first touch
	bool is_changing_plank;
	// true when plank store is open by first touch
	bool is_putting_plank;
};

#endif // __PREPARING_SCENE_H__
