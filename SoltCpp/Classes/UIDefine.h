#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     UIµÄ»ù´¡Àà
*/
#ifndef __UIDEFINE_H__
#define __UIDEFINE_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "UIManager.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;

class UIDefine
{
public:
	UIDefine();
	~UIDefine();

	static UIDefine* getInstance();

	string getUILayer();
	//string setUILayer();

	string getUIFlag();
	//string setUIFlag();

	string getUIName();
	//string setUIName();
	
private:
	string layer;
	string flag;
	string name;
};


#endif