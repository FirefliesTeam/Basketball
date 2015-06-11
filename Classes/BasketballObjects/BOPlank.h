#ifndef __PLANK_H__
#define __PLANK_H__

#include "BObject.h"
#include "cocos2d.h"

class BPlank: public BObject {
public:
    BPlank(int cost, float scale);
	BPlank(int cost, float scale, cocos2d::PhysicsMaterial material, std::string sprite_type); // ����� ����������� ��� �������� ������ ������������� ���� 
    ~BPlank();

    static int value;

    void setOpacity(float opacity);
    void setPosition(cocos2d::Vec2 position); 
    void Rotate(float angl);
    void onContactBegin(); // �� ������
	virtual void serialize(std::ofstream&);
	virtual void deserialize(std::ifstream&);
    
    virtual BPlank* clone() = 0;

protected:
    float _scale;
    int _cost;
    float _rotate_angle;
    int _priority;

};


#endif // __PLANK_H__
