#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     狼的配置文件
*/
#ifndef __WOLFCONFIG_H__
#define __WOLFCONFIG_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "UIManager.h"
#include "EnumDefine.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;


class WolfConfig
{
public:
	WolfConfig();
	~WolfConfig();

	static WolfConfig* getInstance();
	string getSymbolPath(int symbolId);
	Size getSymbolSize();
	int getNum();
	string getRollList1();
	int getSpeed();
	
	//Layer *getUIFromScene(std::unordered_map<std::string, string*>& uiParam);
private:
	std::unordered_map<int, string> m_symbolCsbPath;
	Size m_size;
	int m_num;//信号块数量
	string m_roll_list1;
	int m_speed;
	//CCArray m_roll_list1;
};


#endif