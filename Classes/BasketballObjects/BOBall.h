#ifndef __BASKETBALL_H__
#define __BASKETBALL_H__

#include "cocos2d.h"
#include "BObject.h"

class BBall : BObject
{
	public:
		BBall();
		BBall(cocos2d::Layer *layer);
		~BBall();
		void setPosition();
		void launch();
		void fly();
		bool onContactBegin();

	private:
		cocos2d::Vec2	velocity;
		cocos2d::Vec2	acceleration;
		bool			is_flying;

};


#endif