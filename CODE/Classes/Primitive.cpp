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




