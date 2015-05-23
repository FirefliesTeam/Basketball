#ifndef __STAR_OBJECT_H__
#define __STAR_OBJECT_H__

#include "cocos2d.h"
#include "BObject.h"

class BStar: public BObject {
public:
    //BStar();
    BStar(cocos2d::Layer* layer);
    ~BStar();
    void setPosition(cocos2d::Vec2 coord);
    //void create(cocos2d::Layer* layer);
    //void remove(); 

    //void setPosition() {}

    void serialize(std::ofstream&){};
	void deserialize(std::ifstream&){};

};

#endif // __STAR_OBJECT_H__