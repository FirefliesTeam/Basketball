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
	is_flying = false;

}

float BBall::getLaunchingRotation(Vec2& ball_position, Vec2& touch_position) {
	float rotate_angle = (touch_position - ball_position).getAngle();
	rotate_angle = rotate_angle * 180 / 3.14;
	return  rotate_angle + 90;
}

void  BBall::startLaunching(cocos2d::Touch *touch) {
	if (!is_flying) {
		Vec2 touch_position = touch -> getLocationInView();
		Vec2 ball_position = this -> body -> getPosition();

		auto force_vector = Sprite::create("arrow_sprite.png");
		force_vector -> setPosition(ball_position);
		force_vector -> setAnchorPoint(Vec2(0.5,1));
		force_vector -> setTag(1);
		force_vector -> setScale(0.1);
		force_vector -> setRotation(this -> getLaunchingRotation(ball_position, touch_position));
		Director::getInstance() ->getRunningScene() -> addChild(force_vector, 0);
	}
}

void BBall::setImpulse(cocos2d::Touch *touch) {
	if (!is_flying) {
		Vec2 touch_position = touch -> getLocationInView();
		Vec2 ball_position = this -> sprite -> getPosition();
		auto force_vector = Director::getInstance() -> getRunningScene() -> getChildByTag(1);
		force_vector -> setRotation(getLaunchingRotation(ball_position, touch_position));
		force_vector -> setScale((ball_position - touch_position).getLength()/1000);
	}
}

void BBall::launch(cocos2d::Touch *touch) {
	if (!is_flying) {
		body -> setGravityEnable(true);
		Vec2 touch_position = touch -> getLocation();
		Vec2 ball_position = this -> body -> getPosition();
		body -> applyImpulse((ball_position - touch_position)*1000);
		is_flying = true;
		Director::getInstance() -> getRunningScene() -> removeChildByTag(1);
	}
}

BBall::~BBall() {

}

