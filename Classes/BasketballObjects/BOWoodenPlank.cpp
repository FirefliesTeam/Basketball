#include "BOWoodenPlank.h"
#include "../Definitions/DefForPlanks.h"

USING_NS_CC;

BWoodenPlank::BWoodenPlank(int cost, int priority, float scale, cocos2d::Layer *layer): BPlank(cost, scale) {
    sprite = Sprite::create(WOODEN_PLANK);
    sprite->setScaleX(scale);
    material = PhysicsMaterial(WOODEN_PLANK_DENSITY, WOODEN_PLANK_RESTITUTION, WOODEN_PLANK_FRICTION);

    body = PhysicsBody::createBox(Size(sprite->getContentSize().width * scale, sprite->getContentSize().height), material);
    body->setDynamic(false);
    body->setCollisionBitmask(bitmask);
    body->setContactTestBitmask(true);

    sprite->setPhysicsBody(body);

    layer->addChild(sprite, priority);
}