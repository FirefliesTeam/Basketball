#ifndef __WODDY_PLANK_H__
#define __WODDY_PLANK_H__

#include "cocos2d.h"
#include "BOPlank.h"

class BWoodenPlank: public BPlank {
public:
    //BWoodenPlank(int cost, int priority, float scale, cocos2d::Layer *layer);
    BWoodenPlank(int cost, int priority, float scale);
    ~BWoodenPlank() {}

    BPlank* clone();  

};

#endif //__WODDY_PLANK_H__