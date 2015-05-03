#include "BOBall.h"
#include "Definitions.h"

USING_NS_CC;

BBall::BBall() : BObject() {
	bitmask = BALL_COLLISION_BITMASK;
	physics_material = new PhysicsMaterial(BALL_DENSITY, BALL_RESTITUTION, BALL_FRICTION);
}

BBall::BBall(Layer *layer) {
}

BBall::~BBall() {

}

