#include "BSSplashScene.h"
#include "../Definitions/DefForScenes.h"
#include "BSMainScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce(schedule_selector(SplashScene::GoToMainScene), DISPLAY_TIME_SPLASH_SCENE);
    
    auto background_sprite = Sprite::create(BACKGROUND_SPLASH_SCENE);
    background_sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    this->addChild(background_sprite);
    
    return true;
}

void SplashScene::GoToMainScene(float dt) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));    
}