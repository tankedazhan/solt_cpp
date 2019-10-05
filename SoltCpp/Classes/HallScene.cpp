
#include "HallScene.h"
#include "BaseLayer.h"
#include "HallLayer.h"
#include "UIUtil.h"

HallScene::HallScene()
{

}
HallScene::~HallScene()
{

}



void HallScene::onEnterTransitionDidFinish()
{
	CCLOG("\r\n HallScene::onEnterTransitionDidFinish aaaaaaaaaaaaaaaaaaaa \r\n");
	// ´´½¨halllayer
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::START_VIEW);
}

const char* HallScene::getSceneName() const
{
	return "HallScene";
}