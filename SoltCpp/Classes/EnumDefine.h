#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     UI管理器
*/
#ifndef __ENUMDEFINE_H__
#define __ENUMDEFINE_H__


#define EVENT_NAME_REELTABLE_ROLL "EVENT_NAME_REELTABLE_ROLL"

enum UI_GROUP_DEFINE	//layer层组
{
	Main = 1000,
	UI,
	Dialog,
	Notice,
	Guid,
	Loading
};

enum LAYER_FLAG_DEFING	
{
	LOADING_VIEW,    // loading界面 
	SHOP_VIEW,       // 商店界面
	START_VIEW,		 // 大厅界面
	LEVEL_VIEW,		 // 关卡模块界面
	BUTTON_VIEW,	 // Button界面
	TOP_VIEW,		 // TOP界面
	VIEW_OVER
};

inline UI_GROUP_DEFINE operator++(UI_GROUP_DEFINE &rs, int)
{
	UI_GROUP_DEFINE oldEnum = rs;
	rs = (UI_GROUP_DEFINE)(rs + 1);
	return oldEnum;
}

enum GAME_LEVEL_DEFINE
{
	WOLF_LEVEL
};
//信号块
enum BASE_SYMBOL_UNIT
{
	
};


#endif