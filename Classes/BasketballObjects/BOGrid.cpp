#include "BOGrid.h"
#include "../Definitions/DefForGrid.h"

USING_NS_CC;

BGrid::BGrid(cocos2d::Layer *layer) {
    origin = Director::getInstance()->getVisibleOrigin();
    visible_size = Director::getInstance()->getVisibleSize();
        
    grid_point = Sprite::create(GRID_POINT_SPRITE);
    grid_point->setPosition(Vec2(-1 + origin.x, -1 + origin.y));
    layer->addChild(grid_point, GRID_POINT_PREORITY);

    for(int vertic_position = 0; vertic_position < visible_size.height; vertic_position += GRID_PERIOD) {
        auto sprite_line = Sprite::create(GRID_LINE_SPRITE);
        sprite_line->runAction(RotateBy::create(0, 90));
        sprite_line->setOpacity(0);
        sprite_line->setPosition(Vec2(visible_size.width / 2 + origin.x, vertic_position + origin.y));
        horizontal_lins.push_back(sprite_line);
        layer->addChild(sprite_line);
    } 
    for(int horiz_position = 0; horiz_position < visible_size.width; horiz_position += GRID_PERIOD) {
        auto sprite_line = Sprite::create(GRID_LINE_SPRITE);
        sprite_line->setOpacity(0);
        sprite_line->setPosition(Vec2(horiz_position + origin.x, visible_size.height / 2 + origin.y));
        vertical_lins.push_back(sprite_line);
        layer->addChild(sprite_line);
    }
}

void BGrid::Draw(cocos2d::Layer* layer) {
    for(int i = 0; i < vertical_lins.size(); ++i) {
        vertical_lins[i]->setOpacity(255);
    } 
    for(int i = 0; i < horizontal_lins.size(); ++i) {
        horizontal_lins[i]->setOpacity(255);
    }
}

cocos2d::Vec2 BGrid::getNearIntersectionPoint(cocos2d::Vec2 point) {
    int x = (point.x + GRID_PERIOD / 2) / GRID_PERIOD;
    x *= GRID_PERIOD;   
    int y = (point.y + GRID_PERIOD / 2) / GRID_PERIOD;
    y *= GRID_PERIOD;

    grid_point->setPosition(Vec2(x + origin.x, y + origin.y));    

    return Vec2(x, y);
}

void BGrid::Remove() {
    for(int i = 0; i < vertical_lins.size(); ++i) {
        vertical_lins[i]->setOpacity(0);
    } 
    for(int i = 0; i < horizontal_lins.size(); ++i) {
        horizontal_lins[i]->setOpacity(0);
    }
}
