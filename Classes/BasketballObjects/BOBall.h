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
		void setPosition(){};
		/*
		void startLaunching(cocos2d::Ref *sender);
		void setImpulse(cocos2d::Ref *sender);
		void launch(cocos2d::Ref *sender);

		//for touchPad
		bool startLaunching(cocos2d::Touch *touch, cocos2d::Event *_event);
		bool setImpulse(cocos2d::Touch *touch, cocos2d::Event *_event);
		bool launch(cocos2d::Touch *touch, cocos2d::Event *_event);
		*/

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