#ifndef __PLANK_H__
#define __PLANK_H__

#include "BObject.h"
#include "cocos2d.h"


class BPlank: public BObject {
public:
    BPlank();
    BPlank(cocos2d::Layer *layer);
    ~BPlank();

    static BPlank* createWoodyPlank();
    static BPlank* createMetalPlank();
    static BPlank* createRubberPlank();

private:

};


#endif // __PLANK_H__