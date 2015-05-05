#include "BOBall.h"
#include "../Definitions/DefForBall.h"

USING_NS_CC;

BBall::BBall(Layer *layer) : BObject() {

	bitmask = BALL_COLLISION_BITMASK;
	material = PhysicsMaterial::PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	sprite = Sprite::create("ball_sprite.png");
	body = PhysicsBody::createCircle(sprite->getContentSize().width/2, material);
	body -> setGravityEnable(false);
	sprite -> setPhysicsBody(body);
	sprite -> setPosition(Vec2(visible_size.width/2 + origin.x, visible_size.height/2 + origin.y));
	layer -> addChild(sprite, 0);

}

void BBall::startLaunching(cocos2d::Ref *sender) {

	auto mouse_event = (EventMouse*)sender;
	Vec2 mouse_position = Vec2(mouse_event -> getCursorX(), visible_size.height + mouse_event -> getCursorY());
	Vec2 ball_position = this -> body -> getPosition();

    
	auto force_vector = Sprite::create("arrow_sprite.png");
	force_vector -> setPosition(ball_position);
	force_vector -> setAnchorPoint(Vec2(0.5,1));
	force_vector -> setTag(1);
	force_vector -> setScale(0.25);
	force_vector -> setRotation(this -> getLaunchingRotation(ball_position, mouse_position));

	auto touch_listener = EventListenerMouse::create();
	touch_listener -> onMouseMove = CC_CALLBACK_1(BBall::setImpulse, this);	
	touch_listener -> onMouseUp = CC_CALLBACK_1(BBall::launch, this);	

	auto event_dispatcher = Director::getInstance() -> getRunningScene() -> getEventDispatcher();
	event_dispatcher -> addEventListenerWithSceneGraphPriority(touch_listener, Director::getInstance() -> getRunningScene());
	
	Director::getInstance() ->getRunningScene() -> addChild(force_vector, 0);	
}

void BBall::setImpulse(cocos2d::Ref *sender) {
	auto mouse_event = (EventMouse*)sender;

	Vec2 mouse_position = Vec2(mouse_event -> getCursorX(), visible_size.height + mouse_event -> getCursorY() );
	Vec2 ball_position = this -> body -> getPosition();

	Director::getInstance() -> getRunningScene() -> getChildByTag(1) -> setRotation(getLaunchingRotation(ball_position, mouse_position));
}

void BBall::launch(cocos2d::Ref *sender) {
	this -> body -> setGravityEnable(true);
	auto mouse_event = (EventMouse*)sender;
	Vec2 mouse_position = Vec2(mouse_event -> getCursorX(), visible_size.height + mouse_event -> getCursorY());
	Vec2 ball_position = this -> body -> getPosition();
	
	body -> applyImpulse((mouse_position - ball_position)*1000);
}

float BBall::getLaunchingRotation(Vec2& ball_position, Vec2& touch_position) {
	float rotate_angle = (touch_position - ball_position).getAngle();
	rotate_angle = rotate_angle * 180 / 3.14;
	return  - rotate_angle - 90;
}


//for touchPad ---------------------------------------------------------------------------

bool BBall::TstartLaunching(cocos2d::Touch *touch, cocos2d::Event *sender) {
	
	Vec2 touch_position = touch -> getLocationInView();
	Vec2 ball_position = this -> body -> getPosition();

    auto force_vector = Sprite::create("arrow_sprite.png");
	force_vector -> setPosition(ball_position);
	force_vector -> setAnchorPoint(Vec2(0.5,1));
	force_vector -> setTag(1);
	force_vector -> setScale(0.25);
	force_vector -> setRotation(this -> getLaunchingRotation(ball_position, touch_position));

	auto touch_listener = EventListenerTouchOneByOne::create();
	//touch_listener -> onTouchMoved = CC_CALLBACK_2(BBall::TsetImpulse, this);	
	//touch_listener -> onTouchEnded = CC_CALLBACK_2(BBall::Tlaunch, this);	

	auto event_dispatcher = Director::getInstance() -> getRunningScene() -> getEventDispatcher();
	event_dispatcher -> addEventListenerWithSceneGraphPriority(touch_listener, Director::getInstance() -> getRunningScene());
	
	Director::getInstance() ->getRunningScene() -> addChild(force_vector, 0);	
	return true;
}

bool BBall::TsetImpulse(cocos2d::Touch *touch, cocos2d::Event *sender) {
	Vec2 touch_position = touch -> getLocationInView();
	Vec2 ball_position = this -> body -> getPosition();

	Director::getInstance() -> getRunningScene() -> getChildByTag(1) -> setRotation(getLaunchingRotation(ball_position, touch_position));
	return true;
}

bool BBall::Tlaunch(cocos2d::Touch *touch, cocos2d::Event *sender) {
	this -> body -> setGravityEnable(true);
	Vec2 touch_position = touch -> getLocationInView();
	Vec2 ball_position = this -> body -> getPosition();
	body -> applyImpulse((touch_position - ball_position)*1000);
	return true;
}


BBall::~BBall() {

}

