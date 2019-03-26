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
	private:
		bool directions[4];
		Game::Object hitBox;
	};
}
