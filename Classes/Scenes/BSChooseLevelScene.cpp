#include "BSChooseLevelScene.h"
#include "BSMainScene.h"
#include "../Definitions/DefForScenes.h"

USING_NS_CC;

Scene* ChooseLevelScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ChooseLevelScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ChooseLevelScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create(BACKGROUND_CHOOSE_LEVEL_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    auto menu_item_1 = MenuItemFont::create("Go Back 2", CC_CALLBACK_1(ChooseLevelScene::GoBack, this));

    auto menu =  Menu::create(menu_item_1, NULL);
    menu->alignItemsVertically();
    this->addChild(menu, 1);

    return true;
}

void ChooseLevelScene::GoBack(cocos2d::Ref *sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}

