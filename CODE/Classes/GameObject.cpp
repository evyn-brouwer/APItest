#include "GameObject.h"

Game::Object::Object(const char * fileName, const cocos2d::Vec2 & location)
{
	node = cocos2d::DrawNode::create();
	sprite = cocos2d::Sprite::create(fileName);
	sprite->setPosition(location);
}

Game::Object::Object(const char * fileName, const cocos2d::Vec2 & location, float radius, float angle, unsigned int segments)
{
	Object(fileName,location);

}

Game::Object::Object(const char * fileName, const cocos2d::Vec2 & location, cocos2d::Vec2 size)
{
	Object(fileName,location);
	squareBox = size;
	rect[0] = cocos2d::Vec2(location.x - size.x / 2, location.y - size.y / 2);
	rect[1] = cocos2d::Vec2(location.x + size.x / 2, location.y - size.y / 2);
	rect[2] = cocos2d::Vec2(location.x + size.x / 2, location.y + size.y / 2);
	rect[3] = cocos2d::Vec2(location.x - size.x / 2, location.y + size.y / 2);
}

Game::Object::~Object()
{
}

cocos2d::Sprite * Game::Object::getSprite() const
{
	return sprite;
}

void Game::Object::update(float dt)
{
	node->setPosition(this->getLocation());
}

cocos2d::Vec2 Game::Object::getLocation() const
{
	return sprite->getPosition();
}

void Game::Object::setLocation(const cocos2d::Vec2 & newLoc)
{
	sprite->setPosition(newLoc);
}
