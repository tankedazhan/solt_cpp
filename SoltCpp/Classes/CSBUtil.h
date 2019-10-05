#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     读取csb的工具类
*/
#ifndef __CSBUTIL_H__
#define __CSBUTIL_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;

class CSBUtil
{
public:
	CSBUtil();
	~CSBUtil();

	static CSBUtil* getInstance();

	Node* readLayerCsb(string csbFilePath, std::unordered_map<std::string, Node*>& csbVar);
	Node* readNodeCsb(string csbFilePath, std::unordered_map<std::string, Node*>& csbVar);
	void addOwnerVariable(std::unordered_map<std::string, Node*>& csbVar, Node* node);
private:
};


#endif