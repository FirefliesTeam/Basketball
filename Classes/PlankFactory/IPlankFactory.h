// Интерфейс для абстракной фабрики планок
// Создаются объекты планок с разными характеристиками(материал, размеры, цена), условно:
// резиновая, металическая и деревяная - характеристики определены в Definitios/DefForPlanks.h

#ifndef __IPLANK_FACTORY_H__
#define __IPLANK_FACTORY_H__

#include "cocos2d.h"
#include "../BasketballObjects/BOPlank.h"

class IPlankFactory
{
public:
	IPlankFactory();
	virtual BPlank* createMetalPlank() = 0;
	virtual BPlank* createWoodenPlank();
	virtual BPlank* createRubberPlank();
    
};


#endif