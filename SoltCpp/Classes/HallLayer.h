#pragma once


/*
author:   liuzhiyong
date:     2019-10-1
desc:     ´óÌü²ã
*/

#ifndef __HALLLAYER_H__
#define __HALLLAYER_H__
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseLayer.h"
#include "ui/UIWidget.h"
#include "ui/UIImageView.h"

USING_NS_CC;

using namespace std;
using namespace cocostudio;
using namespace cocos2d::ui;

class HallLayer :public BaseLayer
{
public:
	HallLayer();
	~HallLayer();
	virtual bool init();
	//void loadUi();
	CREATE_FUNC(HallLayer);
	
	void touchCallBack(Ref *sender, Widget::TouchEventType controlEvent);
private:
	ImageView* ImageLevel1;
};










#endif