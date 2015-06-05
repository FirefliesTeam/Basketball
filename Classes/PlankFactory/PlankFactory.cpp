// ���������� ���������� ����������� �������

#include "PlankFactory.h"
#include "BasketballObjects/BOPlank.h"
#include "Definitions/DefForPlanks.h"

USING_NS_CC;

BPlank* PlankFactory::createMetalPlank() {
	PhysicsMaterial material = PhysicsMaterial(METAL_PLANK_DENSITY, METAL_PLANK_RESTITUTION, METAL_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(METALL_PLANK_COST, NORMAL_PLANK, material);
	return newPlank;
}

BPlank* PlankFactory::createWoddenPlank() {
	PhysicsMaterial material = PhysicsMaterial(WOODEN_PLANK_DENSITY, WOODEN_PLANK_RESTITUTION, WOODEN_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(WOODEN_PLANK_COST, NORMAL_PLANK, material);
	return newPlank;
}

BPlank* PlankFactory::createRubberPlank() {
	PhysicsMaterial material = PhysicsMaterial(RUBBER_PLANK_DENSITY, RUBBER_PLANK_RESTITUTION, RUBBER_PLANK_FRICTION);
	BPlank *newPlank = new BPlank(RUBBER_PLANK_COST, NORMAL_PLANK, material);
	return newPlank;
}