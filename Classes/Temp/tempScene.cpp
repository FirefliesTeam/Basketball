#include "tempScene.h"
#include "../Definitions/DefForScenes.h"
#include "../Scenes/BSMainScene.h"
#include "../SonarSystemsBodyParser/SonarSystemsBodyParser.h"
#include "../BasketballObjects/BOStar.h"
#include "../BasketballObjects/BOBasket.h"
#include "../BasketballObjects/BORubberPlank.h"

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

    auto background_sprite = Sprite::create(BACKGROUND_GAME_SCENE);
    background_sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background_sprite, 0);
    
    
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
 
    BStar* star = new BStar(this);
    star->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + 300 + origin.y));

    BBasket* basket = new BBasket(this);
    basket->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(TempScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TempScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TempScene::onTouchEnded, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    BRubberPlank* r_plank = new BRubberPlank(2, 2, 1, this);
    r_plank->setPosition(Vec2(visibleSize.width / 4 * 3 + origin.x, visibleSize.height / 8 * 5 + origin.y));
    //r_plank->Rotate(150);
    r_plank->Rotate(-20);

    return true;
}

void TempScene::GoBack(cocos2d::Ref* sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}

bool TempScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    //bird->fly();
    //this->scheduleOnce(schedule_selector(GameScene::stopFlying), BIRD_FLY_DURATION);
    float x = touch->getLocation().x,
          y = touch->getLocation().y;
    CCLOG("x = %f, y = %f", x, y);
    return true;
}

void TempScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
    float x = touch->getLocation().x,
          y = touch->getLocation().y;
    CCLOG("!!!!!!!!!!!!!!x = %f, y = %f", x, y);
}

 void TempScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    BStar* star = new BStar(this);
    star->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
}