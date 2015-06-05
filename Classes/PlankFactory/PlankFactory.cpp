// Реализация интерфейса абстрактной фабрики

#include "cocos2d.h"
#include "PlankFactory.h"
#include "BasketballObjects/BOPlank.h"
#include "Definitions/DefForPlanks.h"

USING_NS_CC;

BPlank* PlankFactory::createMetalPlank() {
	PhysicsMaterial material = PhysicsMaterial(METAL_PLANK_DENSITY, METAL_PLANK_RESTITUTION, METAL_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(METALL_PLANK_COST, NORMAL_PLANK, material, METAL_PLANK);
	return newPlank;
}

BPlank* PlankFactory::createWoodenPlank() {
	PhysicsMaterial material = PhysicsMaterial(WOODEN_PLANK_DENSITY, WOODEN_PLANK_RESTITUTION, WOODEN_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(WOODEN_PLANK_COST, NORMAL_PLANK, material, WOODEN_PLANK);
	return newPlank;
}

BPlank* PlankFactory::createRubberPlank() {
	PhysicsMaterial material = PhysicsMaterial(RUBBER_PLANK_DENSITY, RUBBER_PLANK_RESTITUTION, RUBBER_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(RUBBER_PLANK_COST, NORMAL_PLANK, material, RUBBER_PLANK);
	return newPlank;
}