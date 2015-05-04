#include "BORubberPlank.h"
#include "Definitions.h"

USING_NS_CC;

BRubberPlank::BRubberPlank(int cost, int priority, float scale, cocos2d::Layer *layer): BPlank(cost, scale) {
    sprite = Sprite::create(RUBBER_PLANK);
    sprite->setScaleX(scale);
    material = PhysicsMaterial(RUBBER_PLANK_DENSITY, RUBBER_PLANK_RESTIITUTION, RUBBER_PLANK_FRICTION);

    body = PhysicsBody::createBox(Size(sprite->getContentSize().width * scale, sprite->getContentSize().height), material);
    body->setDynamic(false);
    body->setCollisionBitmask(bitmask);
    body->setContactTestBitmask(true);

    sprite->setPhysicsBody(body);

    layer->addChild(sprite, priority);
}