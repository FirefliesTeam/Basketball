#include "BSGameScene.h"
#include "BSMainScene.h"
#include "../BasketballObjects/BOBall.h"
#include "../Definitions/DefForScenes.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object 
	//auto scene = Scene::create(); Pavel comment

	// 'scene' with physics
	auto scene = Scene::createWithPhysics();
	scene -> getPhysicsWorld() -> setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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

	
	BBall *ball = new BBall(this);
	this -> edgeBoxInit();
	this -> setEventListeners(ball);
	
    auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(GameScene::GoBack, this));

    auto menu =  Menu::create(menu_item_1, NULL);
	menu->setPosition(Vec2(visibleSize.width/10  + origin.x, visibleSize.height/10 + origin.y));
    this->addChild(menu, 1);
	

    return true;
}

void GameScene::GoBack(cocos2d::Ref *sender) {
    auto main_scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, main_scene));
}

void GameScene::edgeBoxInit() {
	Size visible_size = cocos2d::Director::getInstance() -> getVisibleSize();
	Vec2 origin = cocos2d::Director::getInstance() -> getVisibleOrigin();
	auto edgeBody = PhysicsBody::createEdgeBox(visible_size, PHYSICSBODY_MATERIAL_DEFAULT);
	auto edgeNode = Node::create();
	edgeNode -> setPosition(Point(visible_size.width/2 + origin.x, visible_size.height/2 + origin.y));
	edgeNode -> setPhysicsBody(edgeBody);
	this -> addChild(edgeNode,0);
}

void GameScene::setEventListeners(BBall *ball) {
	
	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener -> setSwallowTouches(true);
	touch_listener -> onTouchBegan = CC_CALLBACK_2(BBall::TstartLaunching, ball);
	
	//auto touch_listener = EventListenerMouse::create();
	//touch_listener -> onMouseDown = CC_CALLBACK_1(BBall::startLaunching, ball);
	Director::getInstance() -> getEventDispatcher() -> addEventListenerWithSceneGraphPriority(touch_listener, this);
}
