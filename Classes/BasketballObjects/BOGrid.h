#ifndef __GRID_OBJECT_H__
#define __GRID_OBJECT_H__

#include "cocos2d.h"

class BGrid {
public:
    void Draw(cocos2d::Layer *layer);
    void Remove();
    cocos2d::Vec2 getNearIntersectionPoint(cocos2d::Vec2 point);
    BGrid(cocos2d::Layer *layer);
    ~BGrid() {}
private:
    cocos2d::Vec2 origin;
    cocos2d::Size visible_size;

    std::vector<cocos2d::Sprite*> vertical_lins;
    std::vector<cocos2d::Sprite*> horizontal_lins;
    cocos2d::Sprite* grid_point;
};

#endif // __GRID_OBJECT_H__