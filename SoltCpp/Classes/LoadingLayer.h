#pragma once


/*
author:   liuzhiyong
date:     2019-10-1
desc:     loading²ã
*/

#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseLayer.h"
#include "UIManager.h"
#include "SceneManager.h"
#include <editor-support/cocostudio/CocoStudio.h>
#include "ui/cocosGUI.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocos2d::ui;

class LoadingLayer :public BaseLayer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool init();
	//void loadUi();
	CREATE_FUNC(LoadingLayer);
	//void goToHallOrLevelScene();
	void loadHallResource();
	void loadHallPlist();
	void updataPlistOfHall(float dt);
	void loadLevelResource();
	void loadLevelPlist();
	void updataPlistOfLevel(float dt);

	virtual void onEnter();
private:
	std::unordered_map<int, string> m_plist;
	int m_index;
	LoadingBar* m_loadingBar;
	float m_percent;

};










#endif