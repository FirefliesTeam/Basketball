#include "BSPreparingScene.h"
#include <iostream>
#include <string>

USING_NS_CC;

Scene* PreparingScene::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = PreparingScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PreparingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    level_number = 0;
    
    auto sprite = Sprite::create(BACKGROUND_GAME_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);

    auto grid = new BGrid(this);
    grid -> Draw(this);

    auto menu_item = MenuItemFont::create("Go Back", CC_CALLBACK_1(PreparingScene::GoBack, this));
    menu_item->setPosition(Point(visibleSize.width - menu_item->getContentSize().width / 2 + origin.x - 10, visibleSize.height - menu_item->getContentSize().height + origin.y + 20));

    auto menu =  Menu::create();
	menu->addChild(menu_item, 1);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    this -> createLevel();

    return true;
}

bool PreparingScene::createLevel() {
    char* current_level = level_number +  "0.level";
    std::ifstream input_file(current_level);
    if (input_file.is_open()) {
        BObject *scene_obj;
        scene_obj = NULL;
        while(input_file >> scene_obj) {
            if (scene_obj != NULL) {
                SceneObjects.push_back(scene_obj);
            }
        }
        for (size_t i = 0; i < SceneObjects.size(); i++) {
            this -> addChild(SceneObjects[i] -> getSprite());
        }
    } else {
        return false;
    }
    return true;
}

void PreparingScene::GoBack(cocos2d::Ref* sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}

