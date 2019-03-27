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
