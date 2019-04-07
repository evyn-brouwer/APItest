/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
#include "Primitive.h"

Primitives::d_Node::d_Node()
{
	d_node = cocos2d::DrawNode::create();
}

Primitives::d_Node::d_Node(const cocos2d::Vec2 loc)
{
	d_node = cocos2d::DrawNode::create();
	d_node->setPosition(loc);
}

Primitives::d_Node::~d_Node()
{
}

cocos2d::DrawNode * Primitives::d_Node::getPrim()
{
	return d_node;
}



Primitives::Recta::Recta()
{
}

Primitives::Recta::Recta(const cocos2d::Vec2  startPos, const cocos2d::Vec2  endPos)
{
	squareBox = endPos - startPos;
	rect[0] = cocos2d::Vec2(startPos.x, startPos.y);
	rect[1] = cocos2d::Vec2(endPos.x, startPos.y);
	rect[2] = cocos2d::Vec2(endPos.x, endPos.y);
	rect[3] = cocos2d::Vec2(startPos.x, endPos.y);
	cocos2d::Color4F white(1, 1, 1, 1);
	cocos2d::Color4F blank(0,0,0,0);
	getPrim()->drawPolygon(rect, 4, blank, 1, white);
}

Primitives::Recta::~Recta()
{
}

cocos2d::Vec2 Primitives::Recta::getSize() const
{
	return squareBox;
}

Primitives::Circ::Circ()
{
	radius = 0;
}

Primitives::Circ::Circ(float new_radius)
{
	radius = new_radius;
}

Primitives::Circ::~Circ()
{
}

float Primitives::Circ::getRadius()
{
	return radius;
}
