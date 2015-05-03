#include "BSMainScene.h"
#include "BSGameScene.h"
#include "BSChooseLevelScene.h"
#include "BSSettingScene.h"

#define BACKGROUND_MAIN_SCENE "background_2.png"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //   auto closeItem = MenuItemImage::create(
    //                                          "CloseNormal.png",
    //                                          "CloseSelected.png",
    //                                          CC_CALLBACK_1(MainScene::menuCloseCallback, this));
    //   
    //closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                               origin.y + closeItem->getContentSize().height/2));

    //   auto menu = Menu::create(closeItem, NULL);
    //   menu->setPosition(Vec2::ZERO);
    //   this->addChild(menu, 1);

    auto sprite = Sprite::create(BACKGROUND_MAIN_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    std::vector<MenuItemFont*> menu_items;

    menu_items.push_back(MenuItemFont::create("New game", CC_CALLBACK_1(MainScene::newGame, this)));
    menu_items.push_back(MenuItemFont::create("Choose level",CC_CALLBACK_1(MainScene::chooseLevel, this)));
    menu_items.push_back(MenuItemFont::create("Setting",CC_CALLBACK_1(MainScene::setting, this)));
    menu_items.push_back(MenuItemFont::create("Exit",CC_CALLBACK_1(MainScene::menuCloseCallback, this)));

    //auto menu_item_1 = MenuItemFont::create("New game", CC_CALLBACK_1(MainScene::newGame, this));
    //auto menu_item_2 = MenuItemFont::create("Choose level",CC_CALLBACK_1(MainScene::chooseLevel, this));
    //auto menu_item_3 = MenuItemFont::create("Setting",CC_CALLBACK_1(MainScene::setting, this));
    //auto menu_item_4 = MenuItemFont::create("Exit",CC_CALLBACK_1(MainScene::menuCloseCallback, this));

    //auto main_menu =  Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);

    auto main_menu =  Menu::create();
    for(size_t i = 0; i < menu_items.size(); ++i) {
	    main_menu->addChild(menu_items[i]);
    }

    main_menu->alignItemsVertically();
    this->addChild(main_menu, 1);

    return true;
}

void MainScene::newGame(cocos2d::Ref *pSender) {
    auto game_scene = GameScene::createScene();
    Director::getInstance()->replaceScene(game_scene);
}

void MainScene::chooseLevel(cocos2d::Ref *pSender) {
    auto choose_level_scene = ChooseLevelScene::createScene();
    Director::getInstance()->replaceScene(choose_level_scene);
}

void MainScene::setting(cocos2d::Ref *pSender) {
    auto setting_scene = SettingScene::createScene();
    Director::getInstance()->pushScene(setting_scene);
}

void MainScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
