#include "BObject.h"

BObject::BObject(){

	visible_size = cocos2d::Director::getInstance() -> getVisibleSize();
	origin = cocos2d::Director::getInstance() -> getVisibleOrigin();
}

BObject::~BObject() {

}