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
		cocos2d::Sprite				*sprite;
		cocos2d::PhysicsBody		*physics_body;
		cocos2d::Size				visible_size;
		cocos2d::Vec2				origin;
		unsigned int				bitmask;
		cocos2d::PhysicsMaterial	*physics_material;
};


#endif