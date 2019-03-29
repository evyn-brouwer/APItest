#pragma once
#include "GameObject.h"
namespace Pacman
{
	class PacDot
	{
	public:
		PacDot(cocos2d::Vec2 new_loc);
		Game::Object getBox();
	private:
		Game::Object hitBox;
	};


}