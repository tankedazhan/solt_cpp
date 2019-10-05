#pragma once


/*
author:   liuzhiyong
date:     2019-10-1
desc:     TOP²ã
*/

#ifndef __TOPLAYER_H__
#define __TOPLAYER_H__
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseLayer.h"
#include "ui/UIWidget.h"
#include "ui/UIImageView.h"

USING_NS_CC;

using namespace std;
using namespace cocostudio;
using namespace cocos2d::ui;

class GameTop :public BaseLayer
{
public:
	GameTop();
	~GameTop();
	virtual bool init();
	//void loadUi();
	CREATE_FUNC(GameTop);

	//void touchCallBack(Ref *sender, Widget::TouchEventType controlEvent);
private:
	//ImageView* ButtonSet;
};


#endif