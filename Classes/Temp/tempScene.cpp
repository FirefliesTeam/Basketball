#include "..\Definitions\Definitions.h"
#include "tempScene.h"
//#include "BSMainScene.h"

#define BACKGROUND_MAIN_SCENE "background_2.png"

USING_NS_CC;

Scene* TempScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TempScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TempScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create(BACKGROUND_MAIN_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    std::vector<MenuItemFont*> menu_items;
    menu_items.push_back(MenuItemFont::create("New game", CC_CALLBACK_1(TempScene::GoBack, this)));

	//Vasya comment
    //auto menu_item_1 = MenuItemFont::create("New game", CC_CALLBACK_1(MainScene::newGame, this));
    //auto menu_item_2 = MenuItemFont::create("Choose level",CC_CALLBACK_1(MainScene::chooseLevel, this));
    //auto menu_item_3 = MenuItemFont::create("Setting",CC_CALLBACK_1(MainScene::setting, this));
    //auto menu_item_4 = MenuItemFont::create("Exit",CC_CALLBACK_1(MainScene::menuCloseCallback, this));

    //auto main_menu =  Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);

    for(int i = 0; i < menu_items.size(); ++i) {
        menu_items[i]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / (menu_items.size() + 1) * (menu_items.size() - i) + origin.y));
    }

    auto main_menu =  Menu::create();
    for(size_t i = 0; i < menu_items.size(); ++i) {
	    main_menu->addChild(menu_items[i], 1);
    }
    //main_menu->alignItemsVertically();
    main_menu->setPosition(Point::ZERO);

    this->addChild(main_menu, 1);

    return true;
}

void TempScene::GoBack(cocos2d::Ref* sender) {

}