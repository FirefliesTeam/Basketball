#include "BOBall.h"
#include "Definitions.h"

USING_NS_CC;

BBall::BBall(Layer *layer) : BObject() {

	bitmask = BALL_COLLISION_BITMASK;
	material = PhysicsMaterial::PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	sprite = Sprite::create("ball_sprite.png");
	body = PhysicsBody::createCircle(sprite->getContentSize().width, material);
	sprite -> setPhysicsBody(body);
	sprite -> setPosition(Vec2(visible_size.width/2 + origin.x, visible_size.height/2 + origin.y));
	layer -> addChild(sprite, 0);

}

BBall::~BBall() {

}

