#pragma once


/*
author:   liuzhiyong
date:     2019-10-1
desc:     Wolf¹Ø¿¨²ã
*/

#ifndef __WOLFLAYER_H__
#define __WOLFLAYER_H__
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseLayer.h"
#include "ui/UIWidget.h"
#include "ui/UIImageView.h"
#include "BaseReelUnit.h"

USING_NS_CC;

using namespace std;
using namespace cocostudio;
using namespace cocos2d::ui;

class LevelLayer :public BaseLayer
{
public:
	LevelLayer();
	~LevelLayer();
	virtual bool init();

	virtual void onEnter();
	//void loadUi();
	CREATE_FUNC(LevelLayer);

	//void touchCallBack(Ref *sender, Widget::TouchEventType controlEvent);
private:
	//ImageView* ButtonSet;
	Sprite* sp_reel_1;
	BaseReelUnit* baseReelUnit;

	BaseSymbolUnit* baseSymbolUnit;
};


#endif