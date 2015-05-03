#include "BSSettingScene.h"

#define BACKGROUND_SETTING_SCENE "background_5.png"

USING_NS_CC;

Scene* SettingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SettingScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SettingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create(BACKGROUND_SETTING_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    auto menu_item_1 = MenuItemFont::create("Go Back 3", CC_CALLBACK_1(SettingScene::GoBack, this));

    auto menu =  Menu::create(menu_item_1, NULL);
    menu->alignItemsVertically();
    this->addChild(menu, 1);

    return true;
}

void SettingScene::GoBack(cocos2d::Ref *sender) {
    Director::getInstance()->popScene();
}

