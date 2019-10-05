#include "GameBottom.h"
#include "SceneManager.h"

GameBottom::GameBottom()
{
	this->m_buttonSpinState = false;
	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
}
GameBottom::~GameBottom()
{

}

bool GameBottom::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	//this->addCsb("wolfLighting/GameScreenPharaoh.csb");
	this->addCsb("LuckySlot/GameMainDown.csb");
	//this->addCsb("LuckySlot/GameTop.csb");


	this->ButtonSpin = (ImageView*)BaseLayer::findChild("ButtonSpin");
	this->ButtonSpin->setTouchEnabled(true);
	//CCLOG("HallLayer::init-------------------222222222222");
	//this->ButtonSet->setPosition(Vec2(100, 100));
	this->ButtonSpin->addTouchEventListener(CC_CALLBACK_2(GameBottom::touchCallBack, this));
	return true;
}

void GameBottom::touchCallBack(Ref *sender, Widget::TouchEventType controlEvent)
{
	if (controlEvent == Widget::TouchEventType::ENDED)
	{
		if (this->m_buttonSpinState == false)
		{
			this->m_buttonSpinState = true;
			EventCustom myEvent("BEGIN");
			char data[20] = "I am data of user!";
			myEvent.setUserData(data);
			this->_eventDispatcher->dispatchEvent(&myEvent);
		}
		else
		{
			this->m_buttonSpinState = false;
			EventCustom myEvent("STOP");
			this->_eventDispatcher->dispatchEvent(&myEvent);
		}
		
	}
}