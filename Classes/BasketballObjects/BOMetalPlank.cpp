#include "BOMetalPlank.h"
#include "../Definitions/DefForPlanks.h"

USING_NS_CC;

BMetalPlank::BMetalPlank(int cost, int priority, float scale, cocos2d::Layer *layer): BPlank(cost, scale) {
    sprite = Sprite::create(METAL_PLANK);
    sprite->setScaleX(scale);
    material = PhysicsMaterial(METAL_PLANK_DENSITY, METAL_PLANK_RESTITUTION, METAL_PLANK_FRICTION);

    body = PhysicsBody::createBox(Size(sprite->getContentSize().width * scale, sprite->getContentSize().height), material);
    body->setDynamic(false);
    body->setCollisionBitmask(bitmask);
    body->setContactTestBitmask(true);

    sprite->setPhysicsBody(body);

    layer->addChild(sprite, priority);
}