#include "LoadingLayer.h"


LoadingLayer::LoadingLayer()
{
	
}
LoadingLayer::~LoadingLayer()
{

}

bool LoadingLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	this->addCsb("LuckySlot/Loading.csb");

	return true;
}

void LoadingLayer::onEnter()
{
	BaseLayer::onEnter();

	auto delay_time = DelayTime::create(1);
	//CallFunc *callfun = CallFunc::create(this, callfunc_selector(LoadingLayer::goToHallScene));
	auto call = CallFunc::create([&] {
		this->goToHallOrLevelScene();
	});
	auto seq = Sequence::createWithTwoActions(delay_time, call);
	this->runAction(seq);
}


void LoadingLayer::goToHallOrLevelScene()
{
	SceneManager::getInstance()->goToHallScene();
}