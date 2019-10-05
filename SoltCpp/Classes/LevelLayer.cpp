#include "LevelLayer.h"
#include "SceneManager.h"
#include "BaseSymbolUnit.h"

LevelLayer::LevelLayer()
{
	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
}
LevelLayer::~LevelLayer()
{

}

bool LevelLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	this->addCsb("wolfLighting/GameScreenPharaoh.csb");
	//this->addCsb("LuckySlot/GameMainDown.csb");
	//this->addCsb("LuckySlot/GameTop.csb");
	

	this->baseReelUnit = BaseReelUnit::create();
	this->baseReelUnit->loadReelUI();
	this->sp_reel_1 = (Sprite*)this->findChild("sp_reel_1");
	this->sp_reel_1->addChild(this->baseReelUnit);

	//this->baseSymbolUnit = BaseSymbolUnit::create();
	//this->baseSymbolUnit->loadDataUI(1);
	//this->sp_reel_1->addChild(this->baseSymbolUnit);

	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
	//this->ButtonSet->setTouchEnabled(true);
	//CCLOG("HallLayer::init-------------------222222222222");
	//this->ButtonSet->setPosition(Vec2(100, 100));
	//this->ButtonSet->addTouchEventListener(CC_CALLBACK_2(HallLayer::touchCallBack, this));
	return true;
}

void LevelLayer::onEnter()
{
	Layer::onEnter();
	auto listenerCustom = EventListenerCustom::create("BEGIN", [&](EventCustom* event) {
		CCLOG("Custom Event,User Data:%s", event->getUserData());
		this->baseReelUnit->startJumpAction();
	});
	this->_eventDispatcher->addEventListenerWithFixedPriority(listenerCustom, 1);

	auto listenerCustom1 = EventListenerCustom::create("STOP", [&](EventCustom* event) {
		this->baseReelUnit->stopRoll();
	});
	this->_eventDispatcher->addEventListenerWithFixedPriority(listenerCustom1, 1);
}

//void WolfLayer::touchCallBack(Ref *sender, Widget::TouchEventType controlEvent)
//{
//	SceneManager::getInstance()->goToLevelScene();
//}