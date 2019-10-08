#pragma once
/*
author:   liuzhiyong
date:     2019-10-3
desc:     ÐÅºÅ¿éµÄ»º´æ
*/
#ifndef __SYMBOLCSBCACHE_H__
#define __SYMBOLCSBCACHE_H__

#include "BaseNode.h"
#include "CSBUtil.h"
#include "WolfConfig.h"
using namespace std;

class Symbol_Csb_Meta
{
public:
	Node* node;
	ActionTimeline* action;
	bool used;
	int index;
	int symbolId;
	std::unordered_map<std::string,Node*> csbVar;
	std::string nodeType;
	Symbol_Csb_Meta();
	~Symbol_Csb_Meta();
};

class SymbolCsbCache
{
public:
	SymbolCsbCache();
	~SymbolCsbCache();

	static SymbolCsbCache* getInstance();
	void createSymbolCsbNode();
	const Symbol_Csb_Meta* getCsbNodeBySymbolId(int symbolId);
private:
	std::unordered_map<int, vector<Symbol_Csb_Meta*>> m_symbolCsbList;
};













#endif