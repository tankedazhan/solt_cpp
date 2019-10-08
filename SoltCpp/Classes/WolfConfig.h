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


class SymbolCsbConfig
{
public:
	string m_file;
	string m_resourcetype;
	int m_count;
	SymbolCsbConfig();
	SymbolCsbConfig(string file, string resourcetype, int count);
	~SymbolCsbConfig();
};

class WolfConfig
{
public:
	WolfConfig();
	~WolfConfig();

	static WolfConfig* getInstance();
	string getSymbolPath(int symbolId);
	string getResourcetype(int symbolId);
	Size getSymbolSize();
	int getNum();
	string getRollList1();
	int getSpeed();
	string getWinNumStr();
	std::unordered_map<int, string> getHallResourceOfPlist();
	std::unordered_map<int, string> getWolfLevelResourceOfPlist();

	const SymbolCsbConfig& getSymbolCsbConfig( int symbolId ) const;
	const std::unordered_map<int, SymbolCsbConfig>& getSymbolCsbConfig();

	//Layer *getUIFromScene(std::unordered_map<std::string, string*>& uiParam);
private:
	std::unordered_map<int, SymbolCsbConfig> m_symbolCsbConfig;
	Size m_size;
	int m_num;//信号块数量
	string m_roll_list1;
	int m_speed;
	string m_winNumStr;
	//CCArray m_roll_list1;
	std::unordered_map<int, string> m_hallResourceOfPlist;
	std::unordered_map<int, string> m_wolfLevelResourceOfPlist;
};


#endif