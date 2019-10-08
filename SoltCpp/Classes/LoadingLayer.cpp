#include "LoadingLayer.h"
#include "WolfConfig.h"
#include "SymbolCsbCache.h"

LoadingLayer::LoadingLayer()
{
	this->m_plist.clear();
	this->m_index = 0;
	this->m_loadingBar = nullptr;
	this->m_percent = 0;
}
LoadingLayer::~LoadingLayer()
{
	this->m_plist.clear();
}

bool LoadingLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	this->addCsb("LuckySlot/Loading.csb");
	this->m_loadingBar = (LoadingBar*)this->findChild("LoadingBar");
	this->m_loadingBar->setPercent(this->m_percent);
	return true;
}

void LoadingLayer::onEnter()
{
	BaseLayer::onEnter();

	/*auto delay_time = DelayTime::create(1);
	//CallFunc *callfun = CallFunc::create(this, callfunc_selector(LoadingLayer::goToHallScene));
	auto call = CallFunc::create([&] {
		this->goToHallOrLevelScene();
	});
	auto seq = Sequence::createWithTwoActions(delay_time, call);
	this->runAction(seq);*/
	auto nextScene = SceneManager::getInstance()->getNextSceneType();
	if (nextScene == HALL)
	{
		this->loadHallResource();
	}
	if (nextScene == LEVEL)
	{
		this->loadLevelResource();
	}
	
}

//进入大厅
//void LoadingLayer::goToHallOrLevelScene()
//{
//	
//	SceneManager::getInstance()->goToHallScene();
//}

void LoadingLayer::loadHallResource()
{
	this->m_plist = WolfConfig::getInstance()->getHallResourceOfPlist();

	this->loadHallPlist();
}

void LoadingLayer::loadHallPlist()
{
	this->m_index = 0;
	this->schedule(schedule_selector(LoadingLayer::updataPlistOfHall),0.2f);
	
}

void LoadingLayer::updataPlistOfHall(float dt)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(this->m_plist[this->m_index]);
	this->m_index = this->m_index + 1;
	this->m_percent = (float)this->m_index / this->m_plist.size() * 100;
	this->m_loadingBar->setPercent(this->m_percent);
	if (this->m_index >= this->m_plist.size())
	{
		this->m_index = 0;
		this->unschedule(schedule_selector(LoadingLayer::updataPlistOfHall));
		//this->goToHallOrLevelScene();
		SceneManager::getInstance()->goToHallScene();
	}
}

//进入关卡
void LoadingLayer::loadLevelResource()
{
	this->m_plist = WolfConfig::getInstance()->getWolfLevelResourceOfPlist();

	this->loadLevelPlist();
}

void LoadingLayer::loadLevelPlist()
{
	this->m_index = 0;
	this->schedule(schedule_selector(LoadingLayer::updataPlistOfLevel), 0.2f);

}

void LoadingLayer::updataPlistOfLevel(float dt)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(this->m_plist[this->m_index]);
	this->m_index = this->m_index + 1;
	this->m_percent = (float)this->m_index / this->m_plist.size() * 100;
	this->m_loadingBar->setPercent(this->m_percent);
	if (this->m_index >= this->m_plist.size())
	{
		this->m_index = 0;
		this->unschedule(schedule_selector(LoadingLayer::updataPlistOfLevel));
		//this->goToHallOrLevelScene();

		SymbolCsbCache::getInstance()->createSymbolCsbNode();

		SceneManager::getInstance()->goToLevelScene();
	}
}

