#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     sceneµÄ»ùÀà
*/

#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "UIManager.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;

class BaseScene :public cocos2d::Scene
{
public:
	BaseScene::BaseScene();
	BaseScene::~BaseScene();
	virtual const char* getSceneName() const;
	UIManager* getUIManager() { return m_uimagager; }
	CREATE_FUNC(BaseScene);

	virtual void onEnterTransitionDidFinish();
private:
	UIManager* m_uimagager;
};












#endif