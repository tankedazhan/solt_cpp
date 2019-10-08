
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


// ÖØÐ´create
//LoadingScene* LoadingScene::create( SCENE_TYPE sceneType )
//{ 
//	LoadingScene *pRet = new(std::nothrow) LoadingScene();
//	if (pRet && pRet->init(sceneType))
//	{
//		pRet->autorelease(); 
//		return pRet; 
//	} 
//	else 
//	{ 
//		delete pRet; 
//		pRet = nullptr; 
//		return nullptr; 
//	} 
//}
//
//bool LoadingScene::init(SCENE_TYPE sceneType)
//{
//	if (BaseScene::init())
//	{
//		this->m_sceneType = sceneType;
//		return true;
//	}
//	return false;
//}




void LoadingScene::onEnterTransitionDidFinish()
{
	// ´´½¨loadinglayer
	UIUtil::getInstance()->addUIToScene(LAYER_FLAG_DEFING::LOADING_VIEW);
}

const char* LoadingScene::getSceneName() const
{
	return "LoadingScene";
}