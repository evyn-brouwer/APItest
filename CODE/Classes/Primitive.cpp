#include "Primitive.h"

Primitive::d_Node::d_Node()
{
	d_node = cocos2d::DrawNode::create();
}

Primitive::d_Node::d_Node(cocos2d::Vec2 loc)
{
	d_node = cocos2d::DrawNode::create();
	d_node->setPosition(loc);
}

Primitive::d_Node::~d_Node()
{
}

cocos2d::DrawNode * Primitive::d_Node::getPrimi()
{
	return d_node;
}

Primitive::Circ::Circ()
{
	d_Node();
	rad = 0;
	ang = 0;
	seg = 0;
}

Primitive::Circ::Circ(const cocos2d::Vec2 & loc, float & radius, float & angle, unsigned int & segments)
{
	d_Node(loc);
	rad = radius;
	ang = angle;
	seg = segments;
	
}

Primitive::Circ::~Circ()
{
}

cocos2d::DrawNode * Primitive::Circ::getPrim()
{
	return getPrimi();
}

void Primitive::Circ::update(float dt)
{
	
}

cocos2d::DrawNode * Primitive::Recta::getPrim()
{
	return getPrimi();
}

cocos2d::DrawNode * Primitive::Line::getPrim()
{
	return getPrimi();
}

cocos2d::DrawNode * Primitive::Capsule::getPrim()
{
	return getPrimi();
}
