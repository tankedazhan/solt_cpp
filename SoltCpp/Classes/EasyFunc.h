#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     读取csb的工具类
*/
#ifndef __EASYFUNC_H__
#define __EASYFUNC_H__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;
using namespace cocostudio::timeline;

class EasyFunc
{
public:
	EasyFunc();
	~EasyFunc();

	static EasyFunc* getInstance();

	void split(const string& s, vector<int>& sv, const char flag = ' ');
private:
};


#endif