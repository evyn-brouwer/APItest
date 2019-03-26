#include "GameObject.h"

Game::Object::Object()
{
}

Game::Object::Object(const char * fileName, const cocos2d::Vec2 & location)
{
	node = cocos2d::DrawNode::create();
	sprite = cocos2d::Sprite::create(fileName);
	sprite->setPosition(location);
}

Game::Object::Object(const char * fileName, const cocos2d::Vec2 & location, cocos2d::Vec2 size)
{
	node = cocos2d::DrawNode::create();
	sprite = cocos2d::Sprite::create(fileName);
	sprite->setPosition(location);
	rBox = Primitives::Recta(cocos2d::Vec2(location.x,location.y),cocos2d::Vec2(location.x+size.x, location.y+size.y));
}

Game::Object::~Object()
{
}

cocos2d::Sprite * Game::Object::getSprite() 
{
	return sprite;
}

void Game::Object::update(float dt)
{
	this->setLocation((this->getLocation() + this->getVelocity()*dt));
}


void Game::Object::setLocation(cocos2d::Vec2 new_Loc)
{
	sprite->setPosition(new_Loc);
}

cocos2d::Vec2 Game::Object::getLocation()
{
	return sprite->getPosition();
}

cocos2d::Vec2 Game::Object::getVelocity()
{
	return velocity;
}

bool Game::Object::checkCollision(Game::Object other)
{
	//TODO
	return false;
}

void Game::Object::setSprite(std::string imageName)
{
	sprite = cocos2d::Sprite::create(imageName);
}

