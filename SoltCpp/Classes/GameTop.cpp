#include "GameTop.h"
#include "SceneManager.h"

GameTop::GameTop()
{
	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
}
GameTop::~GameTop()
{

}

bool GameTop::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	//this->addCsb("wolfLighting/GameScreenPharaoh.csb");
	//this->addCsb("LuckySlot/GameMainDown.csb");
	this->addCsb("LuckySlot/GameTop.csb");


	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
	//this->ButtonSet->setTouchEnabled(true);
	//CCLOG("HallLayer::init-------------------222222222222");
	//this->ButtonSet->setPosition(Vec2(100, 100));
	//this->ButtonSet->addTouchEventListener(CC_CALLBACK_2(HallLayer::touchCallBack, this));
	return true;
}