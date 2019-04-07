/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
#include "Player.h"

Pacman::Player::Player()
{
	hitBox = new Game::Object("CloseNormal.png",cocos2d::Vec2(100,100),1);
	nextDirection = none;
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

Game::Object* Pacman::Player::getBox()
{
	return hitBox;
}

void Pacman::Player::update(float dt)
{
	this->hitBox->update(dt);
}

bool Pacman::Player::checkCollision(Game::Object other)
{
	if (this->hitBox->checkCircCollision(other))
		return true;
	return false;
}

Pacman::Ghost::Ghost()
{
	hitBox = new Game::Object("CloseNormal.png", cocos2d::Vec2(100, 100), 1);
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

Game::Object* Pacman::Ghost::getBox()
{
	return hitBox;
}

void Pacman::Ghost::update(float dt)
{
	this->hitBox->update(dt);
}
