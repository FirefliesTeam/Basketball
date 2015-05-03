#ifndef __BASKETBALL_OBJECT_H__
#define __BASKETBALL_OBJECT_H__

#include "cocos2d.h"

class BObject
{
	public:
		BObject();
		BObject();
		~BObject();
		virtual void setPosition() = 0;

	protected:
		cocos2d::Sprite *sprite;
		cocos2d::PhysicsBody *physics_size;
		cocos2d::Size visible_size;
		cocos2d::Vec2 origin;

	};

	BObject::BObject(){

		visible_size = cocos2d::Director::getInstance() -> getVisibleSize();
		origin = cocos2d::Director::getInstance() -> getVisibleOrigin();
	}

	BObject::~BObject() {

	}
};

#endif