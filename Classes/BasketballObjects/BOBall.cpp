#include "BOBall.h"
#include "../Definitions/DefForBall.h"

USING_NS_CC;

BBall::BBall(Layer *layer) : BObject() {

	bitmask = BALL_COLLISION_BITMASK;
	material = PhysicsMaterial::PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	sprite = Sprite::create("ball_sprite.png");
	body = PhysicsBody::createCircle(sprite->getContentSize().width, material);
	body -> setGravityEnable(false);
	sprite -> setPhysicsBody(body);
	sprite -> setPosition(Vec2(visible_size.width/2 + origin.x, visible_size.height/2 + origin.y));
	layer -> addChild(sprite, 0);

}

void BBall::launchingBall(cocos2d::Ref *sender) {
	Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto mouse_event = (EventMouse*)sender;
	Vec2 mouse_position = Vec2(mouse_event -> getCursorX(), mouse_event -> getCursorY());
	Vec2 ball_position = Vec2(this -> sprite -> getPositionX(), this -> sprite -> getPositionY());

    
	auto force_vector = Sprite::create("arrow_sprite.png");
	force_vector -> setPosition(ball_position);
	force_vector -> setAnchorPoint(Vec2(0.5,1));
	force_vector -> setTag(1);
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

	Vec2 mouse_position = Vec2(mouse_event -> getCursorX(), mouse_event -> getCursorY());
	Vec2 ball_position = Vec2(this -> sprite -> getPositionX(), this -> sprite -> getPositionY());
	Director::getInstance() -> getRunningScene() -> getChildByTag(1) -> setRotation(getLaunchingRotation(ball_position, mouse_position));
}

void BBall::launch(cocos2d::Ref *sender) {
	this -> body -> setGravityEnable(true);
	auto mouse_event = (EventMouse*)sender;
	Vec2 mouse_position = Vec2( - mouse_event -> getCursorX(), visible_size.height - mouse_event -> getCursorY());
	Vec2 ball_position = this -> body -> getPosition();
	//body -> applyImpulse(Vect(ball_position.x - mouse_position.x - origin.x, ball_position.y - mouse_position.y - origin.y)*1000);
	body -> applyImpulse((mouse_position - ball_position)*1000);
}

float BBall::getLaunchingRotation(Point& begin, Point& end) {
	float rotate_angle = (Vec2(end.x - begin.x, end.x - begin.y)).getAngle();
	rotate_angle = rotate_angle * 180 / 3.14;
	if (end.x < begin.x && end.y > begin.y) {
		return 270 + rotate_angle;
	}
	else if (end.x < begin.x && end.y < begin.y) {
		return 90 + rotate_angle;
	}
	/*
	else if (end.x > begin.x && end.y < begin.y) {
		return 180 + rotate_angle;
	}
	*/
	return rotate_angle + 180;
}

BBall::~BBall() {

}

