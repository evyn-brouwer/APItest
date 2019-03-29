#include "PacDot.h"

Pacman::PacDot::PacDot(cocos2d::Vec2 new_loc)
{
	hitBox = Game::Object("PacDot.png", new_loc, 1);
}

Game::Object Pacman::PacDot::getBox()
{
	return hitBox;
}
