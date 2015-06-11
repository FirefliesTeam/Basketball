#ifndef __METAL_PLANK_H__
#define __METAL_PLANK_H__

#include "cocos2d.h"
#include "BOPlank.h"

class BMetalPlank: public BPlank {
public:
    BMetalPlank(int cost, int priority, float scale, cocos2d::Layer *layer);
    BMetalPlank(int cost, int priority, float scale);
    ~BMetalPlank() {}
    
    BPlank* clone();   

};

#endif //__METAL_PLANK_H__