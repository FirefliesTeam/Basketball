#ifndef __STAR_OBJECT_H__
#define __STAR_OBJECT_H__

#include "cocos2d.h"
#include "BObject.h"

class BStar: public BObject {
public:
    BStar();
    ~BStar();
    //void create(cocos2d::Layer* layer);
    //void remove(); 
    char toString();

};

#endif // __STAR_OBJECT_H__
