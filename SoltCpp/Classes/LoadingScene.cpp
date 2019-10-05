
#include "LoadingScene.h"
#include "BaseLayer.h"
#include "LoadingLayer.h"
#include "UIUtil.h"

LoadingScene::LoadingScene()
{
	
}
LoadingScene::~LoadingScene()
{

}



void LoadingScene::onEnterTransitionDidFinish()
{
	// ´´½¨loadinglayer
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::LOADING_VIEW);
}

const char* LoadingScene::getSceneName() const
{
	return "LoadingScene";
}