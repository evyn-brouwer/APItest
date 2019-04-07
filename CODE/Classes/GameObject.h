/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
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
		Object(const char* fileName, const cocos2d::Vec2 & location, float new_rad);
		~Object();
		cocos2d::Sprite* getSprite();
		void update(float dt);
		template <typename T>
		void addVelocity(T force);
		void setVelocity(cocos2d::Vec2);
		void setLocation(cocos2d::Vec2);
		cocos2d::Vec2 getLocation();
		cocos2d::Vec2 getVelocity();
		bool checkRectCollision(Game::Object other);
		bool checkCircCollision(Game::Object other);
		void setSprite(std::string);
	private:
		cocos2d::Sprite *sprite;
		Primitives::Circ cBox;
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


