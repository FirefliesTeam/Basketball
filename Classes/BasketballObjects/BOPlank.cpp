#include <iostream>
#include <fstream>
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

BPlank::BPlank(int cost, float scale, PhysicsMaterial material, std::string type) {
	sprite = Sprite::create(type);
    sprite->setScaleX(scale);
    body = PhysicsBody::createBox(Size(sprite->getContentSize().width * scale, sprite->getContentSize().height), material);
    body->setDynamic(false);
    body->setCollisionBitmask(bitmask);
    body->setContactTestBitmask(true);
    sprite->setPhysicsBody(body);
}

BPlank::~BPlank() {

}

void BPlank::setPosition(cocos2d::Vec2 coord) {
    sprite->setPosition(coord);
}

void BPlank::Rotate(float angl) {
    //_rotate_angle += angl;
    //sprite->runAction(RotateBy::create(PLANK_ROTATE_TIME, _rotate_angle));
    _rotate_angle = angl;
    //sprite->runAction(RotateTo::create(PLANK_ROTATE_TIME, _rotate_angle));
    //sprite->setRotation(angl);
}

void BPlank::setOpacity(float opacity) {
    sprite->setOpacity(opacity);
}

void BPlank::serialize(std::ofstream& file){
	//file << DESIGNATION_PLANK << _scale << " " << _cost << " " << _rotate_angle << std::endl;
}

void BPlank::deserialize(std::ifstream& file){
	int x = 0;
	int y = 0;
	float angle = 0;
	_rotate_angle = 0;
	file >> _scale >> _cost >> angle >> x >> y;
	setPosition(Vec2(x, y));
	BPlank::Rotate(angle);
}
