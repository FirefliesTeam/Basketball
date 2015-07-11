#ifndef __PLANK_H__
#define __PLANK_H__

#include "BObject.h"
#include "cocos2d.h"
#include "BOPlankType.h"

class BPlank: public BObject {

public:
    BPlank(int cost, float scale);
	BPlank(int cost, float scale, cocos2d::PhysicsMaterial material, std::string sprite_type); // новый конструктор для создания планки определенного вида 
    ~BPlank();

    static int value;
    
    void setType(PlankType _type);
    PlankType getType() const;
    void setOpacity(float opacity);
    void rotate(float angl);
    void onContactBegin(); // Не описан
    char toString();

protected:
    float scale;
    int cost;
    int priority;
    PlankType plank_type;

};


#endif // __PLANK_H__
