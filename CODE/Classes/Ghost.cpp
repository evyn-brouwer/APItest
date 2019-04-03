#include "Ghost.h"

Pacman::Ghost::Ghost()
{
	hitBox = new Game::Object("CloseNormal.png",cocos2d::Vec2(100,100),1);
	nextDirection = none;
}

Pacman::Direction Pacman::Ghost::getDirection()
{
	return currentDirection;
}

void Pacman::Ghost::setDirection(Pacman::Direction new_direction)
{
	currentDirection = new_direction;
}

Pacman::Direction Pacman::Ghost::getNextDirection()
{
	return nextDirection;
}

void Pacman::Ghost::setNextDirection(Pacman::Direction new_direction)
{
	nextDirection = new_direction;
}

int Pacman::Ghost::getLives()
{
	return lives;
}

void Pacman::Ghost::setLives(unsigned int new_Lives)
{
	lives = new_Lives;
}

void Pacman::Ghost::loseLife()
{
	lives--;
}

int Pacman::Ghost::getPoints()
{
	return points;
}

void Pacman::Ghost::setPoints(unsigned int new_Points)
{
	points = new_Points;
}

void Pacman::Ghost::addPoints(unsigned int more_points)
{
	points += more_points;
}

Game::Object* Pacman::Ghost::getBox()
{
	return hitBox;
}
