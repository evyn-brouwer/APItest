#pragma once
#include "cocos2d.h"

namespace Primitives
{
	class d_Node
	{
	public:
		d_Node();
		d_Node(const cocos2d::Vec2 loc);
		~d_Node();
		cocos2d::DrawNode *getPrim();
	private:
		cocos2d::DrawNode *d_node;
	};

	class Recta : public d_Node
	{
	public:
		Recta();
		Recta(const cocos2d::Vec2 startPos, const cocos2d::Vec2 endPos);
		~Recta();
		
		cocos2d::Vec2 getSize()const;
	private:
		cocos2d::Vec2 squareBox;
		cocos2d::Vec2 rect[4];
	};



}