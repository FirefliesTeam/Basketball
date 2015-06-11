#ifndef __RUBBER_PLANK_H__
#define __RUBBER_PLANK_H__

#include "cocos2d.h"
#include "BOPlank.h"

class BRubberPlank: public BPlank {
public:
    BRubberPlank(int cost, int priority, float scale, cocos2d::Layer *layer);
    BRubberPlank(int cost, int priority, float scale);
    ~BRubberPlank() {}

    BPlank* clone();      

};

#endif //__RUBBER_PLANK_H__