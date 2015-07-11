#ifndef __BOBASKET_H__
#define __BOBASKET_H__

#include "cocos2d.h"
#include "BObject.h"

class BBasket: public BObject {
public:
    BBasket();
    ~BBasket();
    
    char toString();    
    
};

#endif // __BOBASKET_H__
