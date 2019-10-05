#pragma once

/*
	author:   liuyang
	date:     2019-09-28
	desc:     BaseNode:读取csb的基类
*/
#ifndef __BASENODE_H__
#define __BASENODE_H__

//#include "cocos2d.h"
//#include "cocostudio/ActionTimeline/CSLoader.h"
//USING_NS_CC;
//using namespace std;
//using namespace cocostudio;
//using namespace cocostudio::timeline;
#include "CSBUtil.h"

class BaseNode:public cocos2d::Node
{
public:
	BaseNode();
	~BaseNode();
	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	virtual void addCsb(string fileName, int zOrder);
	//void BaseNode::addOwnerVariable(Node *node);
	virtual void BaseNode::addCsb(string fileName);
	Node* findChild( string name );
	CREATE_FUNC(BaseNode);
private:
	Node* m_csbNode;
	ActionTimeline * m_csbAct;
	std::unordered_map<std::string, Node*> m_csbVar;
};


#endif
