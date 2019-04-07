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
	class TurnPad
	{
	public:
		TurnPad();
		TurnPad(bool up, bool down, bool left, bool right,cocos2d::Vec2 loc);
		Game::Object getBox();
		bool directions[4];
	private:
		Game::Object hitBox;
	};
}
