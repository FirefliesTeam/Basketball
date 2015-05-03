#ifndef __BASKETBALL_OBJECT_H__
#define __BASKETBALL_OBJECT_H__

#include "cocos2d.h"

class BObject
{
	public:
		BObject();
		~BObject();
		virtual void setPosition() = 0;
	protected:
		//Инициализируются в конструкторе базового класса
		cocos2d::Size				visible_size;
		cocos2d::Vec2				origin;
		//Поля инициализируются в конструкторе класса - потомка
		cocos2d::Sprite				*sprite;
		cocos2d::PhysicsBody		*body;
		unsigned int				bitmask;
		cocos2d::PhysicsMaterial	material;
};


#endif