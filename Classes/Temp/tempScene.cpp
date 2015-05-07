#include "../Definitions/DefForScenes.h"
#include "tempScene.h"
#include "../Scenes/BSMainScene.h"
#include "../SonarSystemsBodyParser/SonarSystemsBodyParser.h"
#include "../BasketballObjects/BOStar.h"

USING_NS_CC;

Scene* TempScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = TempScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());

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

    auto sprite = Sprite::create(BACKGROUND_GAME_SCENE);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    
    auto menu_item = MenuItemFont::create("Go Back", CC_CALLBACK_1(TempScene::GoBack, this));
    menu_item->setPosition(Point(visibleSize.width - menu_item->getContentSize().width / 2 + origin.x - 10, visibleSize.height - menu_item->getContentSize().height + origin.y + 20));

    auto menu =  Menu::create();
	menu->addChild(menu_item, 1);
    menu->setPosition(Point::ZERO);

    this->addChild(menu, 1);

    //auto temp_star = Sprite::create("star.png");
    //temp_star->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    //this->addChild(temp_star);

        auto edge_body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    
        auto edge_node = Node::create();
        edge_node->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        edge_node->setPhysicsBody(edge_body);

        this->addChild(edge_node);

    //SonarSysBodyParser::getInstance()->parseJsonFile("star.json");

    //auto json_sprite = Sprite::create("star.png");
    //json_sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    //auto json_sprite_body = SonarSysBodyParser::getInstance()->bodyFormJson(json_sprite, "star", PhysicsMaterial(1, 1, 0));
    //json_sprite_body->setDynamic(true);
    //
    //json_sprite->setPhysicsBody(json_sprite_body);

    //this->addChild(json_sprite);
 
    BStar* star = new BStar(this);
    star->setPosition(Vec2(200 + origin.x, 200 + origin.y));

    return true;
}

void TempScene::GoBack(cocos2d::Ref* sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}