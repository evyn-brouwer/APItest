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

	//// Loader code
	for (int y = loader.map.size() - 1; y >= 0; y--) {
		for (int x = 0; x < loader.map[y].size(); x++) {
			int tmpy = loader.map.size() - y;

			// startPad/player position | to create a start pad: *TTTT
			if (loader.map[y][x][0] == '*') {
				std::vector<bool> dirs;
				for (int i = 1; i < 5; i++) {
					if (loader.map[y][x][i] == 'T') {
						dirs.push_back(true);
					}
					else if (loader.map[y][x][i] == 'F') {
						dirs.push_back(false);
					}
				}
				startPad = new Pacman::TurnPad(dirs[0], dirs[1], dirs[2], dirs[3], Vec2(65 + x * 30, 25 + tmpy * 30));
				startPad->getBox().getSprite()->setVisible(true);
				this->addChild(startPad->getBox().getSprite());

				player.getBox()->getSprite()->setVisible(true);
				player.getBox()->setLocation(startPad->getBox().getLocation());
				turnPadList.push_back(startPad);
				this->addChild(player.getBox()->getSprite());
			}
			// turnPad positions | to create a turn pad: TTTT
			else if (loader.map[y][x].length() == 4) {
				std::vector<bool> dirs;
				for (int i = 0; i < 4; i++) {
					if (loader.map[y][x][i] == 'T') {
						dirs.push_back(true);
					}
					else if (loader.map[y][x][i] == 'F') {
						dirs.push_back(false);
					}
				}
				Pacman::TurnPad *tempPad;
				tempPad = new Pacman::TurnPad(dirs[0], dirs[1], dirs[2], dirs[3], Vec2(65 + x * 30, 25 + tmpy * 30));
				tempPad->getBox().getSprite()->setVisible(true);
				turnPadList.push_back(tempPad);
				this->addChild(tempPad->getBox().getSprite());
			}
			// pacdot positions | to create a pacdot: .
			else if (loader.map[y][x] == ".") {
				Pacman::PacDot * tempDot;
				tempDot = new Pacman::PacDot(Vec2(65 + x * 60, 25 + tmpy * 60));
				tempDot->getBox().getSprite()->setVisible(true);
				pacDotList.push_back(tempDot);
				this->addChild(pacDotList[pacDotList.size() - 1]->getBox().getSprite());
			}
			// powerpellet positions | to create a powepellet: o
			else if (loader.map[y][x] == "o") {

			}
			// ghost spawn
			blinky.getBox()->getSprite()->setVisible(true);
			blinky.getBox()->setLocation(Vec2()); // substitute a pos
			ghostList.push_back(blinky);
			this->addChild(blinky.getBox()->getSprite());
			pinky.getBox()->getSprite()->setVisible(true);
			pinky.getBox()->setLocation(Vec2()); // substitute a pos
			ghostList.push_back(pinky);
			this->addChild(pinky.getBox()->getSprite());
			inky.getBox()->getSprite()->setVisible(true);
			inky.getBox()->setLocation(Vec2()); // substitute a pos
			ghostList.push_back(inky);
			this->addChild(inky.getBox()->getSprite());
			clyde.getBox()->getSprite()->setVisible(true);
			clyde.getBox()->setLocation(Vec2()); // substitute a pos
			ghostList.push_back(clyde);
			this->addChild(clyde.getBox()->getSprite());
		}
	}

	//put code here
	initPrimitives();
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
	initPads();
	initDots();
}

void GameScene::initSprites()
{
	backGround = cocos2d::Sprite::create("PacmanMap.png");
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

void GameScene::initPads()
{
	startPad = new Pacman::TurnPad(true, true, true, true, cocos2d::Vec2(65, 25));
	startPad->getBox().getSprite()->setVisible(true);
	this->addChild(startPad->getBox().getSprite());

	for (unsigned int i=0;i<5;i++)//TODO file reading for level
	{
		for (unsigned int n=0;n<5;n++)
		{
			Pacman::TurnPad *tempPad;
			tempPad = new Pacman::TurnPad(true, true, true, true, cocos2d::Vec2(65 + n * 60, 25 + i * 60));
			tempPad->getBox().getSprite()->setVisible(true);
			turnPadList.push_back(tempPad);
		}
	}
	for (unsigned int i=0;i<turnPadList.size();i++)
	{
		this->addChild(turnPadList[i]->getBox().getSprite());
	}
}

void GameScene::initDots()
{
	for (unsigned int i = 0; i < 5; i++)//TODO file reading for level
	{
		for (unsigned int n = 0; n < 5; n++)
		{
			Pacman::PacDot * tempDot;
			tempDot = new Pacman::PacDot(cocos2d::Vec2(65 + n * 60, 25 + i * 60));
			tempDot->getBox().getSprite()->setVisible(true);
			pacDotList.push_back(tempDot);
		}
	}
	for (unsigned int i = 0; i < pacDotList.size(); i++)
	{
		this->addChild(pacDotList[i]->getBox().getSprite());
	}
}

void GameScene::update(float dt)
{
	checkInput(dt);
	aiUpdate(dt);
	playerDirections(dt);
	player.getBox()->update(dt);
	blinky.getBox()->update(dt);
	pinky.getBox()->update(dt);
	inky.getBox()->update(dt);
	clyde.getBox()->update(dt);
	updateLabels(dt);
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

void GameScene::aiUpdate(float dt)
{
	for (int i = 0; i < ghostList.size(); i++) {

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

		for (int i = 0; i < ghostList.size(); i++) {
			if (ghostList[i].getBox()->checkCircCollision(turnPadList[i]->getBox()))
			{
				if (turnPadList[i]->directions[player.getNextDirection()])
				{
					switch (ghostList[i].getNextDirection())
					{
					case Pacman::up:
						ghostList[i].getBox()->setVelocity(cocos2d::Vec2(0, 50));
						break;
					case Pacman::down:
						ghostList[i].getBox()->setVelocity(cocos2d::Vec2(0, -50));
						break;
					case Pacman::left:
						ghostList[i].getBox()->setVelocity(cocos2d::Vec2(-50, 0));
						break;
					case Pacman::right:
						ghostList[i].getBox()->setVelocity(cocos2d::Vec2(50, 0));
						break;
					default:
						ghostList[i].getBox()->setVelocity(cocos2d::Vec2(0, 0));
						break;
					}
				}
				else
				{
					ghostList[i].getBox()->setVelocity(cocos2d::Vec2(0, 0));
				}
				ghostList[i].setDirection(ghostList[i].getNextDirection());
			}
		}
	}
}

void GameScene::updateLabels(float dt)
{
	scoreLabel->setString("Score: \n" + std::to_string(player.getPoints()));

}



	
	