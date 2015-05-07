#ifndef __BASKETBALL_OBJECT_H__
#define __BASKETBALL_OBJECT_H__

#include "cocos2d.h"

class BObject
{
	public:
		BObject();
		~BObject();
		virtual void setPosition(cocos2d::Vec2 position) = 0;
	protected:
		//���������������� � ������������ �������� ������
		cocos2d::Size				visible_size;
		cocos2d::Vec2				origin;
		//���� ���������������� � ������������ ������ - �������
		cocos2d::Sprite				*sprite;
		cocos2d::PhysicsBody		*body;
		unsigned int				bitmask;
		cocos2d::PhysicsMaterial	material;
};


#endif