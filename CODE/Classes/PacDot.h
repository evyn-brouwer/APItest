/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
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

	class PowerPellet
	{
	public:
		PowerPellet(cocos2d::Vec2 new_loc);
		Game::Object getBox();
	private:
		Game::Object hitBox;
	};


}