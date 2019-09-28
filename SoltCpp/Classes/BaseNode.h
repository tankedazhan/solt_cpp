#pragma once

/*
	author:   liuyang
	date:     2019-09-28
	desc:     BaseNode:��ȡcsb�Ļ���
*/
#ifndef __BASENODE_H__
#define __BASENODE_H__

#include "cocos2d.h"

class BaseNode:public cocos2d::Node
{
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	CREATE_FUNC(BaseNode);
};


#endif
