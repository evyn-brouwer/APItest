/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Input.h"
#include "Events.h"
#include "Enums and Typedefs.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	//put code here
	initPrimitives();
	initObjects();
	initSprites();
	initLabels();
	director = cocos2d::Director::getInstance();
	

	this->scheduleUpdate();
	return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void GameScene::initPrimitives()
{
	borders = new Primitives::Recta(cocos2d::Vec2(50, 12.5), cocos2d::Vec2(350, 312.5));
	borders->getPrim()->setVisible(true);
	this->addChild(borders->getPrim(), 10);
}

void GameScene::initObjects()
{
	startPad = new Pacman::TurnPad(true,true,true,true,cocos2d::Vec2(150,150));
	startPad->getBox().getSprite()->setVisible(true);
	this->addChild(startPad->getBox().getSprite());

	testPad = new Pacman::TurnPad(true,true,true,true,cocos2d::Vec2(150,200));
	testPad->getBox().getSprite()->setVisible(true);
	this->addChild(testPad->getBox().getSprite());
	turnPadList.push_back(testPad);

	player.getBox()->getSprite()->setVisible(true);
	player.getBox()->setLocation(startPad->getBox().getLocation());
	turnPadList.push_back(startPad);
	this->addChild(player.getBox()->getSprite());
}

void GameScene::initSprites()
{
	backGround = cocos2d::Sprite::create("tempBackgorund.png");
	backGround->setGlobalZOrder(-1);
	backGround->setAnchorPoint(cocos2d::Vec2(0,0));
	backGround->setPosition(50,12.5);
	backGround->setVisible(true);
	this->addChild(backGround);
}

void GameScene::initLabels()
{
	scoreLabel = cocos2d::Label::create(("Score: \n" +std::to_string(player.getPoints())),"fonts/arial.ttf",10);
	scoreLabel->setPosition(400,300);
	scoreLabel->setVisible(true);
	this->addChild(scoreLabel);

	testLabel = cocos2d::Label::create("test", "fonts/arial.ttf", 10);
	testLabel->setPosition(400, 270);
	testLabel->setVisible(true);
	this->addChild(testLabel);
}

void GameScene::update(float dt)
{
	checkInput(dt);
	playerDirections(dt);
	player.getBox()->update(dt);
	scoreLabel->setString("Score: \n" + std::to_string(player.getPoints()));
	player.addPoints(1);
}

void GameScene::checkInput(float dt)
{
	if (isEvent(Events::A))
	{
		if (player.getDirection()==Pacman::right)
		{
			player.setDirection(Pacman::left);
			player.getBox()->setVelocity(cocos2d::Vec2(-50, 0));
		}
		player.setNextDirection(Pacman::left);
	}

	if (isEvent(Events::W))
	{
		if (player.getDirection() == Pacman::down)
		{
			player.setDirection(Pacman::up);
			player.getBox()->setVelocity(cocos2d::Vec2(0, 50));
		}
		player.setNextDirection(Pacman::up);
	}

	if (isEvent(Events::D))
	{
		if (player.getDirection() == Pacman::left)
		{
			player.setDirection(Pacman::right);
			player.getBox()->setVelocity(cocos2d::Vec2(50, 0));
		}
		player.setNextDirection(Pacman::right);
	}

	if (isEvent(Events::S))
	{
		if (player.getDirection() == Pacman::up)
		{
			player.setDirection(Pacman::up);
			player.getBox()->setVelocity(cocos2d::Vec2(0, -50));
		}
		player.setNextDirection(Pacman::down);
	}

}

void GameScene::playerDirections(float dt)
{
	for (unsigned int i=0;i<turnPadList.size();i++)
	{
		if (player.getBox()->checkCircCollision(turnPadList[i]->getBox()))
		{
			if (turnPadList[i]->directions[player.getNextDirection()])
			{
				switch (player.getNextDirection())
				{
				case Pacman::up:
					player.getBox()->setVelocity(cocos2d::Vec2(0, 50));
					break;
				case Pacman::down:
					player.getBox()->setVelocity(cocos2d::Vec2(0, -50));
					break;
				case Pacman::left:
					player.getBox()->setVelocity(cocos2d::Vec2(-50, 0));
					break;
				case Pacman::right:
					player.getBox()->setVelocity(cocos2d::Vec2(50, 0));
					break;
				default:
					player.getBox()->setVelocity(cocos2d::Vec2(0, 0));
					break;
				}
			}
			else
			{
				player.getBox()->setVelocity(cocos2d::Vec2(0,0));
			}
			player.setDirection(player.getNextDirection());
		}
	}
}


