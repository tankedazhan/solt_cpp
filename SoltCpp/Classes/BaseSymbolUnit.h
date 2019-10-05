#pragma once

/*
author:   liuzhiyong
date:     2019-10-3
desc:     信号块的基类
*/
#ifndef __BASESYMBOLUNIT_H__
#define __BASESYMBOLUNIT_H__

#include "BaseNode.h"

class BaseSymbolUnit :public BaseNode
{
public:
	BaseSymbolUnit();
	~BaseSymbolUnit();

	//void initStart();
	//virtual void onEnter();
	void loadDataUI(int symbolId);
	void createSymbolCsbNode(int symbolId);
	void getCsbNodeBySymbolId(string symbolId);

	virtual void onEnter();
	virtual void onExit();
	
	CREATE_FUNC(BaseSymbolUnit);
private:
	Size m_size;
	
};


#endif