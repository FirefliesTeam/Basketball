#include "BOBall.h"
#include "Definitions.h"

USING_NS_CC;

BBall::BBall() : BObject() {
	bitmask = BALL_COLLISION_BITMASK;
	material = new PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
	body = PhysicsBody::
}

BBall::BBall(Layer *layer) {

	layer -> addChild(sprite);
}

BBall::~BBall() {

}

