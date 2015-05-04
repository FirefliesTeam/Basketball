#include "BOPlank.h"
#include "../Definitions/DefForPlanks.h"

USING_NS_CC;

int BPlank::value = 0;

BPlank::BPlank(int cost, float scale) {
    _scale = scale;
    _cost = cost;
    _rotate_angle = 0;
    bitmask = PLANK_COLLITION_BITMASK;
}

BPlank::~BPlank() {
    
}

void BPlank::setPosition(cocos2d::Vec2 coord) {
    sprite->setPosition(coord);
}

void BPlank::Rotate(float angl) {
    _rotate_angle += angl;
    sprite->runAction(RotateBy::create(PLANK_ROTATE_TIME, _rotate_angle));
}

void BPlank::setOpacity(float opacity) {
    sprite->setOpacity(opacity);
}