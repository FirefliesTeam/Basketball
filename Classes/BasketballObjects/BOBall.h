#ifndef __BASKETBALL_H__
#define __BASKETBALL_H__

#include "cocos2d.h"
#include "BObject.h"

class BBall : public BObject
{
	public:
		BBall();
		BBall(cocos2d::Layer *layer, cocos2d::Vec2 position);
		~BBall();

		void setPosition(cocos2d::Vec2 position){};
		void startLaunching(cocos2d::Touch *touch);
		void setImpulse(cocos2d::Touch *touch);
		void launch(cocos2d::Touch *touch);

		bool isFlying();
		void fly();
		bool onContactBegin();
		float getLaunchingRotation(cocos2d::Point&, cocos2d::Point&);

	private:
		cocos2d::Vec2	velocity;
		cocos2d::Vec2	acceleration;
		bool			is_flying;

};


#endif