#include "Primitive.h"

Primitive::d_Node::d_Node()
{
	d_node = cocos2d::DrawNode::create();
}

Primitive::d_Node::d_Node(const cocos2d::Vec2 loc)
{
	d_node = cocos2d::DrawNode::create();
	d_node->setPosition(loc);
}

Primitive::d_Node::~d_Node()
{
}

cocos2d::DrawNode * Primitive::d_Node::getPrim()
{
	return d_node;
}


Primitive::Recta::Recta()
{
}

Primitive::Recta::Recta(const cocos2d::Vec2  startPos, const cocos2d::Vec2  endPos)
{
	d_Node(cocos2d::Vec2(startPos));
	squareBox = endPos - startPos;
	rect[0] = cocos2d::Vec2(startPos.x, startPos.y);
	rect[1] = cocos2d::Vec2(endPos.x / 2, startPos.y);
	rect[2] = cocos2d::Vec2(endPos.x / 2, endPos.y);
	rect[3] = cocos2d::Vec2(startPos.x, endPos.y);
	cocos2d::Color4F white(1, 1, 1, 1);
	getPrim()->drawPolygon(&squareBox,4,white,1,white);
}

Primitive::Recta::~Recta()
{
}




