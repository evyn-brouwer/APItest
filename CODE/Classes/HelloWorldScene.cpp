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

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Input.h"
#include "Events.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
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
	  CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	/*
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }*/

	//put code here
	initPrimitives();
	initObjects();
	initSprites();
	director = cocos2d::Director::getInstance();
	
	
	this->scheduleUpdate();
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::initPrimitives()
{
	borders =  new Primitives::Recta(cocos2d::Vec2(Bbottom, Bbottom), cocos2d::Vec2(Btop, Btop));
	borders->getPrim()->setVisible(true);
	this->addChild(borders->getPrim(),10);
}

void HelloWorld::initObjects()
{
	testObject = new Game::Object("t_55.png", cocos2d::Vec2(Bbottom, Bbottom), cocos2d::Vec2(10, 10));
	testObject->getSprite()->setAnchorPoint(cocos2d::Vec2(0, 0));
	testObject->getSprite()->setVisible(true);
	testObject->setVelocity(cocos2d::Vec2(40, 20));
	this->addChild(testObject->getSprite(), 10);
	
}

void HelloWorld::initSprites()
{
	test = cocos2d::Sprite::create("Evynster.jpg");
	test->setPosition(cocos2d::Vec2(0,0));
	test->setAnchorPoint(cocos2d::Vec2(0,0));
	//test->setVisible(true);
	this->addChild(test, -10);

	testLabel = cocos2d::Label::create(std::to_string(testObject->getLocation().x),"fonts/arial.ttf",25);
	testLabel->setPosition(cocos2d::Vec2(100,100));
	testLabel->setVisible(true);
	this->addChild(testLabel);
}

void HelloWorld::update(float dt)
{
	checkInput(dt);
	testObject->update(dt);
	testLabel->setString((std::to_string(testObject->getLocation().x)));
	if (testObject->getLocation().x> Btop)
	{
		testObject->setLocation(cocos2d::Vec2(Btop,testObject->getLocation().y));
		testObject->setVelocity(cocos2d::Vec2(testObject->getVelocity().x*-1,testObject->getVelocity().y));
	}
	if (testObject->getLocation().x < Bbottom)
	{
		testObject->setLocation(cocos2d::Vec2(Bbottom, testObject->getLocation().y));
		testObject->setVelocity(cocos2d::Vec2(testObject->getVelocity().x*-1, testObject->getVelocity().y));
	}
	if (testObject->getLocation().y > Btop)
	{
		testObject->setLocation(cocos2d::Vec2(testObject->getLocation().x, Btop));
		testObject->setVelocity(cocos2d::Vec2(testObject->getVelocity().x, testObject->getVelocity().y*-1));
	}
	if (testObject->getLocation().y < Bbottom)
	{
		testObject->setLocation(cocos2d::Vec2(testObject->getLocation().x, Bbottom));
		testObject->setVelocity(cocos2d::Vec2(testObject->getVelocity().x, testObject->getVelocity().y*-1));
	}
}

void HelloWorld::checkInput(float dt)
{
	if (isEvent(Events::A))
	{
		this->getDefaultCamera()->setPosition(cocos2d::Vec2(this->getDefaultCamera()->getPosition().x - 1,
			this->getDefaultCamera()->getPosition().y));
	}
		
	if (isEvent(Events::W))
	{
		this->getDefaultCamera()->setPosition(cocos2d::Vec2(this->getDefaultCamera()->getPosition().x,
			this->getDefaultCamera()->getPosition().y + 1));
	}
		
	if (isEvent(Events::D))
	{
		this->getDefaultCamera()->setPosition(cocos2d::Vec2(this->getDefaultCamera()->getPosition().x + 1,
			this->getDefaultCamera()->getPosition().y));
	}
		
	if (isEvent(Events::S))
	{
		this->getDefaultCamera()->setPosition(cocos2d::Vec2(this->getDefaultCamera()->getPosition().x,
			this->getDefaultCamera()->getPosition().y - 1));
	}
		
}


