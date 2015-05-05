#include "BSMainScene.h"
#include "BSGameScene.h"
#include "BSChooseLevelScene.h"
#include "BSSettingScene.h"
#include "../Definitions/DefForScenes.h"
#include "../Temp/tempScene.h"

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

    auto sprite = Sprite::create(BACKGROUND_MAIN_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    std::vector<MenuItemFont*> menu_items;
    menu_items.push_back(MenuItemFont::create("New game", CC_CALLBACK_1(MainScene::GoToNewGame, this)));
    menu_items.push_back(MenuItemFont::create("Choose level",CC_CALLBACK_1(MainScene::GoToChooseLevel, this)));
    menu_items.push_back(MenuItemFont::create("Setting",CC_CALLBACK_1(MainScene::GoToSetting, this)));
    menu_items.push_back(MenuItemFont::create("Exit",CC_CALLBACK_1(MainScene::menuCloseCallback, this)));

	//Vasya comment
    //auto menu_item_1 = MenuItemFont::create("New game", CC_CALLBACK_1(MainScene::newGame, this));
    //auto menu_item_2 = MenuItemFont::create("Choose level",CC_CALLBACK_1(MainScene::chooseLevel, this));
    //auto menu_item_3 = MenuItemFont::create("Setting",CC_CALLBACK_1(MainScene::setting, this));
    //auto menu_item_4 = MenuItemFont::create("Exit",CC_CALLBACK_1(MainScene::menuCloseCallback, this));

    //auto main_menu =  Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);

    for(int i = 0; i < menu_items.size(); ++i) {
        CCLOG("%i", (menu_items.size() - i));
        menu_items[i]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / (menu_items.size() + 1) * (menu_items.size() - i) + origin.y));
    }

    auto main_menu =  Menu::create();
    for(size_t i = 0; i < menu_items.size(); ++i) {
	    main_menu->addChild(menu_items[i], 1);
    }
    //main_menu->alignItemsVertically();
    main_menu->setPosition(Point::ZERO);

    //////////////////////////// GO TO tempScene
    auto menu_item_go_to_tempScene = MenuItemFont::create("TempScene", CC_CALLBACK_1(MainScene::GoToTempScene,this));
    menu_item_go_to_tempScene->setPosition(Point(visibleSize.width / 4 + origin.x, visibleSize.height / 5 * 4 + origin.y));
    main_menu->addChild(menu_item_go_to_tempScene);
    ////////////////////////////

    this->addChild(main_menu, 1);

    return true;
}

void MainScene::GoToNewGame(cocos2d::Ref *sender) {
    auto game_scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, game_scene));
}

void MainScene::GoToChooseLevel(cocos2d::Ref *sender) {
    auto choose_level_scene = ChooseLevelScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, choose_level_scene));
}

void MainScene::GoToSetting(cocos2d::Ref *sender) {
    auto setting_scene = SettingScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, setting_scene));
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

///////////////////////////////// GO TO tempScene
void MainScene::GoToTempScene(cocos2d::Ref *sender) {
    auto temp_scene = TempScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, temp_scene));
}
/////////////////////////////////