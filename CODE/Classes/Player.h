/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
#pragma once
#include "GameObject.h"
#include "Enums and Typedefs.h"
namespace Pacman
{
	class Player 
	{
	public:
		Player();
		Pacman::Direction getDirection();
		void setDirection(Pacman::Direction);
		Pacman::Direction getNextDirection();
		void setNextDirection(Pacman::Direction);
		int getLives();
		void setLives(unsigned int);
		void loseLife();
		int getPoints();
		void setPoints(unsigned int);
		void addPoints(unsigned int);
		Game::Object* getBox();
		void update(float dt);
		//bool checkPath();
		bool checkCollision(Game::Object other);
	private:
		Pacman::Direction currentDirection;
		Pacman::Direction nextDirection;
		int lives=3;
		int points = 0;
		Game::Object *hitBox;
	};

	class Ghost
	{
	public:
		Ghost();
		Pacman::Direction getDirection();
		void setDirection(Pacman::Direction);
		Pacman::Direction getNextDirection();
		void setNextDirection(Pacman::Direction);
		int getLives();
		void setLives(unsigned int);
		void loseLife();
		Game::Object* getBox();
		void update(float dt);
		//bool checkPath();
	private:
		Pacman::Direction currentDirection;
		Pacman::Direction nextDirection;
		int lives = 1;
		bool isEdible = false;
		Game::Object *hitBox;
	};
}