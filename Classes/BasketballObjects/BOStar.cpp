#include "BOStar.h"
#include "../Definitions/DefForStar.h"
#include "../SonarSystemsBodyParser/SonarSystemsBodyParser.h"

USING_NS_CC;

//BStar::BStar() {
//    material = PhysicsMaterial(STAR_PLANK_DENSITY, STAR_PLANK_RESTITUTION, STAR_PALNK_FRICTION);
//    bitmask = STAR_COLLISION_BITMASK;
//}

BStar::BStar(cocos2d::Layer* layer) {
    material = PhysicsMaterial(STAR_PLANK_DENSITY, STAR_PLANK_RESTITUTION, STAR_PALNK_FRICTION);
    bitmask = STAR_COLLISION_BITMASK;

    SonarSysBodyParser::getInstance()->parseJsonFile(STAR_JSON_FILE);

    sprite = Sprite::create(STAR_SPRITE);
    //sprite->setPosition(Vec2(visible_size.width / 2 + origin.x, visible_size.height / 2 + origin.y));

    body = SonarSysBodyParser::getInstance()->bodyFormJson(sprite, STAR_NAME_OBJECT_IN_JSON, material);
    body->setDynamic(true);
    
    sprite->setPhysicsBody(body);

    layer->addChild(sprite);
}

BStar::~BStar() {

}

void BStar::setPosition(cocos2d::Vec2 coord) {
    sprite->setPosition(coord);
}

//void BStar::create(cocos2d::Layer* layer) {
//    if(sprite == NULL) {
//        SonarSysBodyParser::getInstance()->parseJsonFile("star.json");
//
//        sprite = Sprite::create("star.png");
//        //sprite->setPosition(Vec2(visible_size.width / 2 + origin.x, visible_size.height / 2 + origin.y));
//
//        body = SonarSysBodyParser::getInstance()->bodyFormJson(sprite, "star", material);
//        body->setDynamic(true);
//    
//        sprite->setPhysicsBody(body);
//
//        layer->addChild(sprite);
//    }
//}

//void BStar::remove() {
//    if(sprite != NULL) {
//        
//        
//    }
//} 