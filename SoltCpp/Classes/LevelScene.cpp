
#include "LevelScene.h"
#include "BaseLayer.h"
#include "LevelLayer.h"
#include "UIUtil.h"

LevelScene::LevelScene()
{

}
LevelScene::~LevelScene()
{

}



void LevelScene::onEnterTransitionDidFinish()
{
	CCLOG("\r\n HallScene::onEnterTransitionDidFinish aaaaaaaaaaaaaaaaaaaa \r\n");
	// ´´½¨gamelayer
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::LEVEL_VIEW);
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::TOP_VIEW);
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::BUTTON_VIEW);

}

const char* LevelScene::getSceneName() const
{
	return "LevelScene";
}