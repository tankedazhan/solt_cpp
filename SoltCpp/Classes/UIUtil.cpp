#include "UIUtil.h"
#include "SceneManager.h"
#include "UIManager.h"
#include "LoadingLayer.h"
#include "LoadingScene.h"
#include "EnumDefine.h"
#include "HallLayer.h"
#include "LevelLayer.h"
#include "GameBottom.h"
#include "GameTop.h"

static UIUtil *gUiUtil = NULL;

UIUtil::UIUtil()
{

}
UIUtil::~UIUtil()
{

}

UIUtil* UIUtil::getInstance()
{
	if (!gUiUtil)
	{
		gUiUtil = new (std::nothrow) UIUtil();
	}
	return gUiUtil;
}

Layer* UIUtil::addUIToScene(LAYER_FLAG_DEFING flag)
{
	BaseScene * scene = SceneManager::getInstance()->getCurrentScene();
	UIManager* manager = scene->getUIManager();
	if (flag == LAYER_FLAG_DEFING::LOADING_VIEW)
	{
		auto layer = LoadingLayer::create();
		manager->addLayer(layer, UI_GROUP_DEFINE::Main,flag);
		return layer;
	}
	if (flag == LAYER_FLAG_DEFING::START_VIEW)
	{
		auto layer = HallLayer::create();
		manager->addLayer(layer, UI_GROUP_DEFINE::Main, flag);
		return layer;
	}
	if (flag == LAYER_FLAG_DEFING::LEVEL_VIEW)
	{
		auto layer = LevelLayer::create();
		manager->addLayer(layer, UI_GROUP_DEFINE::Main, flag);
		return layer;
	}
	if (flag == LAYER_FLAG_DEFING::BUTTON_VIEW)
	{
		auto layer = GameBottom::create();
		manager->addLayer(layer, UI_GROUP_DEFINE::Main, flag);
		return layer;
	}
	if (flag == LAYER_FLAG_DEFING::TOP_VIEW)
	{
		auto layer = GameTop::create();
		manager->addLayer(layer, UI_GROUP_DEFINE::Main, flag);
		return layer;
	}
	
	return nullptr;
}

void UIUtil::removeUIFromScene(LAYER_FLAG_DEFING flag)
{
	BaseScene * scene = SceneManager::getInstance()->getCurrentScene();
	UIManager* manager = scene->getUIManager();
	//manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	if (flag == LAYER_FLAG_DEFING::LOADING_VIEW)
	{
		manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	}
	if (flag == LAYER_FLAG_DEFING::START_VIEW)
	{
		manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	}
	if (flag == LAYER_FLAG_DEFING::LEVEL_VIEW)
	{
		manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	}
	if (flag == LAYER_FLAG_DEFING::BUTTON_VIEW)
	{
		manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	}
	if (flag == LAYER_FLAG_DEFING::TOP_VIEW)
	{
		manager->removeLayer(UI_GROUP_DEFINE::Main, flag);
	}
}

//Layer* UIUtil::getUIFromScene(std::unordered_map<std::string, string*>& uiParam)
//{
//
//}