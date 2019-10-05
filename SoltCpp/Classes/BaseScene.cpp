#include "BaseScene.h"


BaseScene::BaseScene()
{
	this->m_uimagager = new (std::nothrow) UIManager(this);
}
BaseScene::~BaseScene()
{
	CCLOG("BaseScene::~BaseScene");
	delete this->m_uimagager;
}
const char* BaseScene::getSceneName() const
{
	return "BaseScene";
}

void BaseScene::onEnterTransitionDidFinish()
{
	
}

