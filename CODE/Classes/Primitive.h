#pragma once
#include "cocos2d.h"

namespace Primitive
{
	class d_Node
	{
	public:
		d_Node();
		d_Node(cocos2d::Vec2 loc);
		~d_Node();
		cocos2d::DrawNode *getPrimi();
		cocos2d::Vec2 velocity;
	private:
		cocos2d::DrawNode *d_node;
	};

	class Circ : public d_Node
	{
	public:
		Circ();
		Circ(const cocos2d::Vec2 &loc, float &radius, float &angle, unsigned int &segments);
		~Circ();
		cocos2d::DrawNode *getPrim();
		void update(float dt);
		template <typename T>
		void addForce(T force);
		template <typename T>
		void setForce(T force);
		template <typename T>
		void setLocation(T force);
		cocos2d::Vec2 getLocation();
		cocos2d::Vec2 getVelocity();
		bool checkCollision(Circ other);
		bool checkCollision(Recta other);
	private:
		float rad;
		float ang;
		unsigned int seg;
		
	};

	class Recta : public d_Node
	{
	public:
		Recta(const cocos2d::Vec2 &startPos, const cocos2d::Vec2 &endPos);
		~Recta();
		cocos2d::DrawNode *getPrim();
	private:

	};

	class Line : public d_Node
	{
	public:
		Line(const cocos2d::Vec2 &startPos, const cocos2d::Vec2 &endPos);
		~Line();
		cocos2d::DrawNode *getPrim();
	private:

	};

	class Capsule : public d_Node
	{
	public:
		~Capsule();
		Capsule();
		cocos2d::DrawNode *getPrim();
	private:

	};
}