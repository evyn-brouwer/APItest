#pragma once
#include "cocos2d.h"
#include "Enums and Typedefs.h"
#include "Primitive.h"
namespace Game
{
	class Object
	{
	public:
		Object();
		Object(const char* fileName,const cocos2d::Vec2 &location);
		Object(const char* fileName, const cocos2d::Vec2 &location, float radius, float angle, unsigned int segments);
		Object(const char* fileName,const cocos2d::Vec2 & location, cocos2d::Vec2 size);
		~Object();
		cocos2d::Sprite* getSprite()const;
		void update(float dt);
		cocos2d::Vec2 getLocation()const;
		void setLocation(const cocos2d::Vec2 &newLoc);
	private:
		cocos2d::Sprite *sprite;
		baseGame::ObjectBox collisionBoxType;
		cocos2d::Vec2 squareBox;
		cocos2d::Vec2 rect[4];
		Primitive::Circ cBox;
		cocos2d::DrawNode *node;
	};
}