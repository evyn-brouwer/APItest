#include "Primitive.h"

cocos2d::DrawNode * Primitive::d_Node::getPrimi()
{
	return d_node;
}

cocos2d::DrawNode * Primitive::Circ::getPrim()
{
	return getPrimi();
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
