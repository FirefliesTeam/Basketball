#include "BOBall.h"
#include "Definitions.h"

USING_NS_CC;

BBall::BBall() : BObject() {
	bitmask = BALL_COLLISION_BITMASK;
	material = PhysicsMaterial::PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	sprite = Sprite::create("ball_sprite.png");
	body = PhysicsBody::createCircle(sprite->getContentSize().width, material);
	sprite -> setPhysicsBody(body);
	sprite -> setPosition(Vec2(visible_size.width/2 + origin.x, visible_size.height/2 + origin.y));
	Director::getInstance() -> getRunningScene() -> addChild(sprite, 200);
	
	Label label =  LabelTTF::create("WTF","Arial", 32);
	Director::getInstance() -> getRunningScene() -> addChild(label, 200);
	
}

BBall::~BBall() {

}

