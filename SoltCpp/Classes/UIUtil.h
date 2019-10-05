#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     ���/ɾ��UI�Ĺ�����
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
//	LOADING_VIEW,    // loading���� 
//	SHOP_VIEW,       // �̵����
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