#ifndef __BASKETBALL_OBJECT_H__
#define __BASKETBALL_OBJECT_H__

#include "cocos2d.h"
#include <iostream>
#include <string>
using namespace std;

// почему нет чистого виртуального метода setPosition??????

class BObject
{
	public:
		BObject();
		~BObject();
		
		friend ostream& operator << (ostream &os, const BObject &obj);
		friend istream& operator >> (istream &is, BObject *&obj);
		
		virtual char toString() = 0;
		
		
		cocos2d::Sprite* getSprite();
        
        void setPosition(cocos2d::Vec2 position);		
        void rotate(float angle);
        
	protected:
		//»нициализируютс€ в конструкторе базового класса
		cocos2d::Size				visible_size;
		cocos2d::Vec2				origin;
		//ѕол€ инициализируютс€ в конструкторе класса - потомка
		cocos2d::Sprite				*sprite;
		cocos2d::PhysicsBody		*body;
		unsigned int				bitmask;
		cocos2d::PhysicsMaterial	material;
		
		float rotate_angle;
};


#endif
