#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     UIπ‹¿Ì∆˜
*/
#ifndef __UIMANAGER_H__
#define __UIMANAGER_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "EnumDefine.h"

USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;


class UIManager
{
public:
	UIManager(Scene* scene);
	~UIManager();
	
	void createUiGroup();
	void addLayer( Layer* layer, UI_GROUP_DEFINE falg, LAYER_FLAG_DEFING layer_flag);
	void removeLayer(UI_GROUP_DEFINE flag, LAYER_FLAG_DEFING layer_flag);
private:
	std::unordered_map<UI_GROUP_DEFINE, Node*> m_nodeList;
	Scene* m_scene;
};


#endif