#pragma once

/*
author:   liuzhiyong
date:     2019-10-3
desc:     滚轴
*/
#ifndef __BASEREELUNIT_H__
#define __BASEREELUNIT_H__

#include "BaseNode.h"
#include "BaseSymbolUnit.h"
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>


class BaseReelUnit :public BaseNode
{
public:
	BaseReelUnit();
	~BaseReelUnit();
	virtual bool init();
	void loadReelUI();
	void createSymbolCsbFullReel();
	void addClipNode();//初始化裁剪区域
	void getListToArray();
	void startJumpAction();
	void updataSymbolUnit(float dt);
	void stopRoll(string destData);
	void reviseSymbolPosition();

	virtual void onEnter();
	virtual void onExit();

	//void getCsbNodeBySymbolId(string symbolId);
	
	CREATE_FUNC(BaseReelUnit);
private:
	Size m_size;
	int m_num;
	int m_symbolTotalNum;
	ClippingRectangleNode* m_clippingNode;//裁剪区域
	BaseSymbolUnit* m_symbolUnit;
	//std::unordered_map<int, Node*> m_symbolUnitList;
	std::vector<BaseSymbolUnit*> m_symbolUnitList;
	BaseSymbolUnit* m_topSymbolUnit;//指向最上方信号块
	BaseSymbolUnit* m_topSymbolUnitOfHold;//停止是标记指向最上方信号块
	int m_symbolCurrentNum;//当前需要创建的信号块的标识
	string m_list1;//配置滚动数据字符串
	vector<int> m_roll_list1;//配置滚动数据
	int do_began;
	bool m_rollState;
	string m_winNumStr;//传入，最终的结果数据
	vector<int> m_winNumInt;//拆分后的数据结果
	vector<int> m_winNumIntOfHold;//保留替换的数据，结束后更换回去
	int m_symbolCurrentNumOfHold;//保留替换数据的标识


};


#endif