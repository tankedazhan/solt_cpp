#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     UI������
*/
#ifndef __ENUMDEFINE_H__
#define __ENUMDEFINE_H__


#define EVENT_NAME_REELTABLE_ROLL "EVENT_NAME_REELTABLE_ROLL"

enum UI_GROUP_DEFINE	//layer����
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
	LOADING_VIEW,    // loading���� 
	SHOP_VIEW,       // �̵����
	START_VIEW,		 // ��������
	LEVEL_VIEW,		 // �ؿ�ģ�����
	BUTTON_VIEW,	 // Button����
	TOP_VIEW,		 // TOP����
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
//�źſ�
enum BASE_SYMBOL_UNIT
{
	
};


#endif