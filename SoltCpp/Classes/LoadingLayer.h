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
USING_NS_CC;
using namespace std;
using namespace cocostudio;

class LoadingLayer :public BaseLayer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool init();
	//void loadUi();
	CREATE_FUNC(LoadingLayer);
	void goToHallOrLevelScene();

	virtual void onEnter();
};










#endif