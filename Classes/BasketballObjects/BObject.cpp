#include "BObject.h"
#include "BOBall.h"
#include "BOStar.h"
#include "BOBasket.h"
#include "../PlankFactory/PlankFactory.h"
#include "../Definitions/DefForStrings.h"
#include "../Definitions/DefForPlanks.h"

BObject::BObject(){

	visible_size = cocos2d::Director::getInstance() -> getVisibleSize();
	origin = cocos2d::Director::getInstance() -> getVisibleOrigin();
	rotate_angle = 0;
}

BObject::~BObject() {

}

cocos2d::Sprite* BObject::getSprite() { 
    return sprite;
}

void BObject::setPosition(cocos2d::Vec2 position) {
    sprite -> setPosition(position);
}

ostream& operator << (ostream &os, const BObject &obj) {
    char obj_name = obj.toString();
    cocos2d::Vec2 obj_position = obj.sprite -> getOffsetPosition();
    os << obj_name << ' '
        << obj_position.x << ' ' 
        << obj_position.y << ' '
        << obj.rotate_angle << ' '
        << endl;
    return os;  
}

istream& operator >> (istream& is, BObject *&obj) {
    char obj_name;
    float rotate_angle;
    float x,y;
    is >> obj_name
       >> x
       >> y
       >> rotate_angle;
    PlankFactory plankFactory;
    switch(obj_name) {
        case BALL_NAME: 
            obj = new BBall();
            break;
        case WOODEN_PLANK_NAME:
            obj = plankFactory.createWoodenPlank();
            break; 
        case METAL_PLANK_NAME:
            obj = plankFactory.createMetalPlank();
            break;
        case RUBBER_PLANK_NAME:
            obj = plankFactory.createRubberPlank();
            break;
        case STAR_NAME:
            obj = new BStar();
            break;
        case BASKET_NAME:
            obj = new BBasket();
            break;
        default:
            obj = NULL;
            break;
    }  
    if (obj != NULL) {
        cocos2d::Vec2 obj_position(x,y);
        obj -> setPosition(obj_position);
        obj -> rotate(rotate_angle);
    }
    return is;
}

void BObject::rotate(float angle) {
    rotate_angle += angle;
    //sprite->runAction(cocos2d::RotateBy::create(PLANK_ROTATE_TIME, rotate_angle));
    //_rotate_angle = angl;
    sprite->runAction(cocos2d::RotateTo::create(PLANK_ROTATE_TIME, rotate_angle));
    //sprite -> setRotation(rotate_angle);
}
