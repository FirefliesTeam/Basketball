#include "BOBasket.h"
#include "../Definitions/DefForBasket.h"
#include "../SonarSystemsBodyParser/SonarSystemsBodyParser.h"

USING_NS_CC;

BBasket::BBasket(cocos2d::Layer* layer) {
    material = PhysicsMaterial(BASKET_PLANK_DENSITY, BASKET_PLANK_RESTITUTION, BASKET_PALNK_FRICTION);
    bitmask = BASKET_COLLISION_BITMASK;

    SonarSysBodyParser::getInstance()->parseJsonFile("basket_6");

    sprite = Sprite::create("basket.png");
    //sprite->setPosition(Vec2(visible_size.width / 2 + origin.x, visible_size.height / 2 + origin.y));

    body = SonarSysBodyParser::getInstance()->bodyFormJson(sprite, "basket", material);
    body->setDynamic(false);
    
    sprite->setPhysicsBody(body);

    layer->addChild(sprite);


    //SonarSysBodyParser::getInstance()->parseJsonFile("newTest.json");

    //auto arrow_sprite = Sprite::create("arrow_sprite.png");
    //arrow_sprite->setPosition(Vec2(visible_size.width / 9 * 3 + origin.x, visible_size.height / 4 * 3 + origin.y));

    //auto arrow_body = SonarSysBodyParser::getInstance()->bodyFormJson(arrow_sprite, "newTest", PhysicsMaterial(0, 0, 0));
    //arrow_body->setDynamic(false);
    //
    //arrow_sprite->setPhysicsBody(arrow_body);

    //layer->addChild(arrow_sprite);
}

BBasket::~BBasket() {

}

void BBasket::setPosition(cocos2d::Vec2 coord) {
    sprite->setPosition(coord);
}