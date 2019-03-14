#pragma once
#include "cocos2d.h"

namespace Primitive
{
	class d_Node
	{
	public:
		d_Node();
		~d_Node();
		cocos2d::DrawNode *getPrimi();
		cocos2d::DrawNode *d_node;
	private:
		
	};

	class Circ : public d_Node
	{
	public:
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
	private:
		float rad;
		float ang;
		unsigned int seg;
		cocos2d::Vec2 velocity;
	};

	class Recta : public d_Node
	{
	public:
		Recta();
		~Recta();
		cocos2d::DrawNode *getPrim();
	private:

	};

	class Line : public d_Node
	{
	public:
		Line();
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