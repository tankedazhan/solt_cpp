#pragma once
/*
author:   liuzhiyong
date:     2019-09-29
desc:     BaseLayer:读取csb的基类
*/

#ifndef __BASELAYER_H__
#define __BASELAYER_H__

//#include "cocos2d.h"
//#include "BaseNode.h"
//#include "cocostudio/ActionTimeline/CSLoader.h"
#include "CSBUtil.h"
//USING_NS_CC;
//using namespace std;
//using namespace cocostudio;
//using namespace cocostudio::timeline;

class BaseLayer :public cocos2d::Layer
{
public:
	BaseLayer();
	~BaseLayer();
	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	void addCsb(string fileName, int zOrder);
	void addCsb(string fileName);
	Node* findChild(string name);
	
	//void BaseLayer::addOwnerVariable(BaseLayer *node);
	CREATE_FUNC(BaseLayer);

private:
	Node* m_csbNode;
	ActionTimeline * m_csbAct;
	std::unordered_map<std::string, Node*> m_csbVar;
};


#endif