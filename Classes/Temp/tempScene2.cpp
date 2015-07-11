#include <fstream>
#include "cocos2d.h"
#include "tempScene2.h"
#include "../Scenes/BSMainScene.h"
#include "../PlankFactory/PlankFactory.h"
#include "../BasketballObjects/BOBall.h"
#include "../BasketballObjects/BObject.h"
#include "../Definitions/DefForScenes.h"
#include "../Definitions/DefForPlanks.h"

USING_NS_CC;

Scene* TempScene2::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = TempScene2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TempScene2::init()
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
	//////////////////////////

    ball = new BBall();
	ball -> setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this -> addChild(ball -> getSprite());
    auto plankFactory = new PlankFactory();    
    
    BObject  **plankArray = new BObject* [10];
    plankArray[0] = plankFactory -> createWoodenPlank();
    plankArray[1] = plankFactory -> createMetalPlank();
    plankArray[2] = plankFactory -> createRubberPlank();        
    
    for (int i = 0; i < 3; i++)
        this -> addChild(plankArray[i] -> getSprite());
    
	this->edgeBoxInit();
	this->setEventListeners(ball);

	std::ofstream file("1.txt");
    for (int i = 0; i < 3; i++)
        file << *plankArray[i] << std::endl;


	file.close();

    //////////////////////////
    auto menu_item = MenuItemFont::create("Go Back", CC_CALLBACK_1(TempScene2::GoBack, this));
    menu_item->setPosition(Point(visibleSize.width - menu_item->getContentSize().width / 2 + origin.x - 10, visibleSize.height - menu_item->getContentSize().height + origin.y + 20));

    auto menu =  Menu::create();
	menu->addChild(menu_item, 1);
    menu->setPosition(Point::ZERO);

    this->addChild(menu, 1);

    return true;
}

void TempScene2::GoBack(cocos2d::Ref* sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}

void TempScene2::edgeBoxInit() {
	Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
	Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	auto edgeBody = PhysicsBody::createEdgeBox(visible_size, PHYSICSBODY_MATERIAL_DEFAULT);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visible_size.width / 2 + origin.x, visible_size.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode, 0);
}

void TempScene2::setEventListeners(BBall *ball) {
	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->setSwallowTouches(true);
	touch_listener->onTouchBegan = CC_CALLBACK_2(TempScene2::startBallLaunching, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(TempScene2::setBallImpulse, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(TempScene2::launchBall, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch_listener, this);
}

bool TempScene2::startBallLaunching(Touch *touch, Event *_event) {

	ball->startLaunching(touch);
	return true;
}

void TempScene2::setBallImpulse(cocos2d::Touch *touch, cocos2d::Event *_event) {
	ball->setImpulse(touch);

}

void TempScene2::launchBall(cocos2d::Touch *touch, cocos2d::Event *_event) {
	ball->launch(touch);
}
