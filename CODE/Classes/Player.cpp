#include "Player.h"

Pacman::Player::Player()
{
	hitBox = Game::Object("CloseNormal.png",cocos2d::Vec2(100,100));
}

Pacman::Direction Pacman::Player::getDirection()
{
	return currentDirection;
}

void Pacman::Player::setDirection(Pacman::Direction new_direction)
{
	currentDirection = new_direction;
}

Pacman::Direction Pacman::Player::getNextDirection()
{
	return nextDirection;
}

void Pacman::Player::setNextDirection(Pacman::Direction new_direction)
{
	nextDirection = new_direction;
}

int Pacman::Player::getLives()
{
	return lives;
}

void Pacman::Player::setLives(unsigned int new_Lives)
{
	lives = new_Lives;
}

void Pacman::Player::loseLife()
{
	lives--;
}

int Pacman::Player::getPoints()
{
	return points;
}

void Pacman::Player::setPoints(unsigned int new_Points)
{
	points = new_Points;
}

void Pacman::Player::addPoints(unsigned int more_points)
{
	points += more_points;
}

Game::Object Pacman::Player::getBox()
{
	return hitBox;
}
