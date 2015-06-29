#ifndef __SINGLE_BASKETBALL_H__
#define __SINGLE_BASKETBALL_H__

#include "cocos2d.h"
#include "BObject.h"

class BSingleBall : public BObject
{
    public:
        static BSingleBall* GetSingleBall(cocos2d::Layer *layer, cocos2d::Vec2 position);

    protected:
        BSingleBall();
        BSingleBall(cocos2d::Layer *layer, cocos2d::Vec2 position);

    private:
        static BSingleBall* _single_ball;
        
    
	public:
		//BSingleBall();
		//BSingleBall(cocos2d::Layer *layer, cocos2d::Vec2 position);
		~BSingleBall();

		void setPosition(cocos2d::Vec2 position);
		void startLaunching(cocos2d::Touch *touch);
		void setImpulse(cocos2d::Touch *touch);
		void launch(cocos2d::Touch *touch);

        void setLayer(cocos2d::Layer *layer);

		bool isFlying();
		//void fly();
		bool onContactBegin();
		

		void serialize(std::ofstream&);
		void deserialize(std::ifstream&);


    private:
		float			getLaunchingRotation(cocos2d::Point&, cocos2d::Point&);

    private:
		cocos2d::Vec2	velocity;
		cocos2d::Vec2	acceleration;
		bool			is_flying;
    
};


#endif
