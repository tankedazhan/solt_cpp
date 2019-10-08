#include "HallLayer.h"
#include "SceneManager.h"

HallLayer::HallLayer()
{
	//this->ButtonSet = (ImageView*)BaseLayer::findChild("ImageLevel1");
}
HallLayer::~HallLayer()
{

}

bool HallLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	this->addCsb("LuckySlot/Start.csb");
	this->ImageLevel1 = (ImageView*)BaseLayer::findChild("ImageLevel1");
	this->ImageLevel1->setTouchEnabled(true);
	//CCLOG("HallLayer::init-------------------222222222222");
	//this->ButtonSet->setPosition(Vec2(100, 100));
	this->ImageLevel1->addTouchEventListener(CC_CALLBACK_2(HallLayer::touchCallBack, this));
	return true;
}

void HallLayer::touchCallBack(Ref *sender, Widget::TouchEventType controlEvent)
{
	CCLOG("HallLayer::touchCallBack----------------------------------HallLayer::touchCallBack");
	SceneManager::getInstance()->goToLevelSceneByLoading();
}