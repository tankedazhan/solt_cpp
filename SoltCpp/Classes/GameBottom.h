#pragma once

/*
author:   liuzhiyong
date:     2019-10-1
desc:     Button²ã
*/

#ifndef __BOTTOMLAYER_H__
#define __BOTTOMLAYER_H__
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseLayer.h"
#include "ui/UIWidget.h"
#include "ui/UIImageView.h"

USING_NS_CC;

using namespace std;
using namespace cocostudio;
using namespace cocos2d::ui;

class GameBottom :public BaseLayer
{
public:
	GameBottom();
	~GameBottom();
	virtual bool init();
	//void loadUi();
	CREATE_FUNC(GameBottom);

	void touchCallBack(Ref *sender, Widget::TouchEventType controlEvent);
private:
	ImageView* ButtonSpin;
	bool m_buttonSpinState;
};


#endif