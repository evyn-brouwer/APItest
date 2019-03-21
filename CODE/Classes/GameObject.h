#pragma once
#include "cocos2d.h"
#include "Enums and Typedefs.h"
#include "Primitive.h"
namespace Game
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(const char* fileName,const cocos2d::Vec2 &location, baseGame::ObjectBox boxType);

		GameObject(const char* fileName, const cocos2d::Vec2 &location, baseGame::ObjectBox boxType, float radius, float angle, unsigned int segments);
		~GameObject();
		cocos2d::Sprite* getSprite()const;
		void update(float dt);

	private:
		cocos2d::Sprite *sprite;
		baseGame::ObjectBox collisionBox;

	};
}