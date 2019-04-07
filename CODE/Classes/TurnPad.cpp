/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
#include "TurnPad.h"

Pacman::TurnPad::TurnPad()
{
}

Pacman::TurnPad::TurnPad(bool up, bool down, bool left, bool right, cocos2d::Vec2 loc)
{
	directions[0] = up;
	directions[1] = down;
	directions[2] = left;
	directions[3] = right;
	hitBox = Game::Object("tilePad.png",loc,1);
}

Game::Object Pacman::TurnPad::getBox()
{
	return hitBox;
}
