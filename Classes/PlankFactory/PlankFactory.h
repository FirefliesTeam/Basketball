// Реализация интерфейса абстрактной фабрики

#ifndef __PLANK_FACTORY_H__
#define __PLANK_FACTORY_H__

#include "cocos2d.h"
#include "IPlankFactory.h"
#include "../BasketballObjects/BOPlank.h"

class PlankFactory: public IPlankFactory
{
public:
	PlankFactory();
	~PlankFactory();
	BPlank* createMetalPlank();
	BPlank* createWoddenPlank();
    BPlank* createRubberPlank();
};


#endif