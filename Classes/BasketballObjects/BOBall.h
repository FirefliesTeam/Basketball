#ifndef __BASKETBALL_H__
#define __BASKETBALL_H__

#include "cocos2d.h"
#include "BObject.h"

class BBall : public BObject
{
	public:
		BBall();
		~BBall();

		void startLaunching(cocos2d::Touch *touch);
		void setImpulse(cocos2d::Touch *touch);
		void launch(cocos2d::Touch *touch);
        
        char toString();
        
		bool isFlying();
		//void fly();
		bool onContactBegin();
		
    private:
		float			getLaunchingRotation(cocos2d::Point&, cocos2d::Point&);

    private:
		cocos2d::Vec2	velocity;
		cocos2d::Vec2	acceleration;
		bool			is_flying;
    
};


#endif
