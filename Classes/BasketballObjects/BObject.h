#ifndef __BASKETBALL_OBJECT_H__
#define __BASKETBALL_OBJECT_H__

#include "cocos2d.h"

// почему нет чистого виртуального метода setPosition??????

class BObject
{
	public:
		BObject();
		~BObject();
		virtual void serialize(std::ofstream&) = 0;
		virtual void deserialize(std::ifstream&) = 0;
	protected:
		//»нициализируютс€ в конструкторе базового класса
		cocos2d::Size				visible_size;
		cocos2d::Vec2				origin;
		//ѕол€ инициализируютс€ в конструкторе класса - потомка
		cocos2d::Sprite				*sprite;
		cocos2d::PhysicsBody		*body;
		unsigned int				bitmask;
		cocos2d::PhysicsMaterial	material;
};


#endif
