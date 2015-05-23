#ifndef __BOBASKET_H__
#define __BOBASKET_H__

#include "cocos2d.h"
#include "BObject.h"

class BBasket: public BObject {
public:
    BBasket(cocos2d::Layer* layer);
    ~BBasket();

    void setPosition(cocos2d::Vec2 coord);
    void serialize(std::ofstream&){};
	void deserialize(std::ifstream&){};

};

#endif // __BOBASKET_H__