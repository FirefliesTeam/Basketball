#include <iostream>
#include <fstream>
#include "BOBall.h"
#include "../Definitions/DefForBall.h"
#include "../Definitions/DefForSriteTags.h"
#include <math.h>
#include "cocos2d.h"

USING_NS_CC;

BBall::BBall(Layer *layer, Vec2 position) : BObject() {
	bitmask = BALL_COLLISION_BITMASK;
	material = PhysicsMaterial::PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	sprite = Sprite::create("ball_sprite.png");
	body = PhysicsBody::createCircle(sprite->getContentSize().width/2, material);
	body -> setGravityEnable(false);
	sprite -> setPhysicsBody(body);
	sprite -> setPosition(position);
	layer -> addChild(sprite, 0);
	is_flying = false;
}

void BBall::setPosition(cocos2d::Vec2 position) {
	sprite -> setPosition(position);
}


float BBall::getLaunchingRotation(Vec2& start_touch_position, Vec2& current_touch_position) {
	float rotate_angle = (current_touch_position - start_touch_position).getAngle();
	//перевод угла из радиан в градусы
	rotate_angle = rotate_angle * M_1_PI * ANGLE_180_DEGREES;
	return  rotate_angle + ANGLE_90_DEGREES;
}

void  BBall::startLaunching(cocos2d::Touch *touch) {
	if (!is_flying) {
		Vec2 current_touch_position = touch -> getLocationInView();
		Vec2 start_touch_position = touch -> getStartLocationInView();

		auto impulse_vector = Sprite::create("arrow_sprite.png");
		impulse_vector -> setPosition(this -> sprite -> getPosition());
		impulse_vector -> setAnchorPoint(Vec2(0.5,1));
		impulse_vector -> setTag(IMPULSE_VECTOR_TAG);
		impulse_vector -> setScale((start_touch_position - current_touch_position).getLength() * IMPULSE_VECTOR_SCALE_RATIO);
		impulse_vector -> setRotation(this -> getLaunchingRotation(start_touch_position, current_touch_position));
		Director::getInstance() -> getRunningScene() -> addChild(impulse_vector, 0);
	}
}

void BBall::setImpulse(cocos2d::Touch *touch) {
	if (!is_flying) {
		Vec2 current_touch_position = touch -> getLocationInView();
		Vec2 start_touch_position = touch -> getStartLocationInView();
		auto impulse_vector = Director::getInstance() -> getRunningScene() -> getChildByTag(1);
		impulse_vector -> setRotation(getLaunchingRotation(start_touch_position, current_touch_position));
		if(impulse_vector -> getScale() < IMPULSE_VECTOR_MAX_SCALE) {
			impulse_vector -> setScale((start_touch_position - current_touch_position).getLength() * IMPULSE_VECTOR_SCALE_RATIO);
		}
	}
}

void BBall::launch(cocos2d::Touch *touch) {
	if (!is_flying) {
		body -> setGravityEnable(true);
		Vec2 impulse_vector = touch -> getStartLocationInView() - touch -> getLocation();
		if (impulse_vector < Vec2(MAX_IMPULSE)) {
			body -> applyImpulse(impulse_vector * IMPULSE_VECTOR_RATIO);
		} else {
			body -> applyImpulse(Vec2(MAX_IMPULSE) * IMPULSE_VECTOR_RATIO);
		}
		is_flying = true;
		Director::getInstance() -> getRunningScene() -> removeChildByTag(IMPULSE_VECTOR_TAG);
	}
}

BBall::~BBall() {

}

void BBall::serialize(std::ofstream& file){
	//file << 'b' << std::endl;
}

void BBall::deserialize(std::ifstream& file){
	int x = 0;
	int y = 0;

	velocity = cocos2d::Vec2(0, 0);
	acceleration = cocos2d::Vec2(0, 0);
	//is_flying = false;
	file >> x >> y;
	setPosition(Vec2(x, y));
}
