#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     添加/删除UI的工具类
*/
#ifndef __UIUTIL_H__
#define __UIUTIL_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "UIManager.h"
#include "EnumDefine.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;


//enum GAME_VIEW_UIDEFINE
//{
//	LOADING_VIEW,    // loading界面 
//	SHOP_VIEW,       // 商店界面
//	VIEW_OVER   
//};

class UIUtil
{
public:
	UIUtil();
	~UIUtil();

	static UIUtil* getInstance();

	Layer *addUIToScene(LAYER_FLAG_DEFING flag);
	void removeUIFromScene(LAYER_FLAG_DEFING flag);
	//Layer *getUIFromScene(std::unordered_map<std::string, string*>& uiParam);
private:
};


#endif