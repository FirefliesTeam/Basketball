#include <iostream>
#include <fstream>
#include "BOPlank.h"
#include "../Definitions/DefForPlanks.h"
#include "../Definitions/DefForStrings.h"

USING_NS_CC;

int BPlank::value = 0;

BPlank::BPlank(int _cost, float _scale): BObject() {
    scale = _scale;
    cost = _cost;
    bitmask = PLANK_COLLITION_BITMASK;
}

BPlank::BPlank(int cost, float scale, PhysicsMaterial material, std::string plank_sprite_name): BObject() {
	sprite = Sprite::create(plank_sprite_name);
    sprite->setScaleX(scale);
    body = PhysicsBody::createBox(Size(sprite->getContentSize().width, sprite->getContentSize().height), material);
    body->setDynamic(false);
    body->setCollisionBitmask(bitmask);
    body->setContactTestBitmask(true);
    sprite->setPhysicsBody(body);
    
}

BPlank::~BPlank() {

}

void BPlank::setType(PlankType _type) {
    plank_type = _type;
}

PlankType BPlank::getType() const {
    return plank_type;
}

char BPlank::toString() {
    switch(plank_type) {
        case Wooden:
            return WOODEN_PLANK_NAME;
        case Metal:
            return METAL_PLANK_NAME;
        case Rubber: 
            return RUBBER_PLANK_NAME;
        default: 
            return 1;
    }
}

void BPlank::setOpacity(float opacity) {
    sprite->setOpacity(opacity);
}


