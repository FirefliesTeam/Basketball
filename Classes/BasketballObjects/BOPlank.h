#ifndef __PLANK_H__
#define __PLANK_H__

#include "BObject.h"
#include "cocos2d.h"


class BPlank: public BObject {
public:
    BPlank();
    BPlank(cocos2d::Layer *layer);
    ~BPlank();

    static BPlank* createWoodyPlank(cocos2d::Layer *layer);
    static BPlank* createMetalPlank(cocos2d::Layer *layer);
    static BPlank* createRubberPlank(cocos2d::Layer *layer);

    static int value;

    void setPosition(cocos2d::Vec2 coord);
    void Rotate(float angl);
    void onContactBegin();

private:
    int cost;
    float rotate_angle;
        

};


#endif // __PLANK_H__