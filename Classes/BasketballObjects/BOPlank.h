#ifndef __PLANK_H__
#define __PLANK_H__

#include "BObject.h"
#include "cocos2d.h"

class BPlank: public BObject {
public:
    BPlank(int cost, float scale);
    ~BPlank();

    static int value;

    void setOpacity(float opacity);
    void setPosition(cocos2d::Vec2 position); //названия переменных не должны содержать сокращения coor -> position
    void Rotate(float angl);
    void onContactBegin();     /////// Не описан
	virtual void serialize(std::ofstream&);
	virtual void deserialize(std::ifstream&);
protected:
    float _scale;
    int _cost;
    float _rotate_angle;
};


#endif // __PLANK_H__
