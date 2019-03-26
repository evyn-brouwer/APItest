#pragma once
#include "cocos2d.h"
#include "Primitive.h"
namespace Game
{
	class Object
	{
	public:
		Object();
		Object(const char* fileName,const cocos2d::Vec2 &location);
		Object(const char* fileName,const cocos2d::Vec2 & location, cocos2d::Vec2 size);
		~Object();
		cocos2d::Sprite* getSprite();
		void update(float dt);
		template <typename T>
		void addVelocity(T force);
		template <typename T>
		void setVelocity(T force);
		void setLocation(cocos2d::Vec2);
		cocos2d::Vec2 getLocation();
		cocos2d::Vec2 getVelocity();
		bool checkCollision(Game::Object other);
		void setSprite(std::string);
	private:
		cocos2d::Sprite *sprite;
		Primitives::Recta rBox;
		cocos2d::DrawNode *node;
		cocos2d::Vec2 velocity;
	};
}

template<typename T>
inline void Game::Object::addVelocity(T new_velocity)
{
	velocity += new_velocity;
}

template<typename T>
inline void Game::Object::setVelocity(T new_velocity)
{
	velocity = new_velocity;
}

