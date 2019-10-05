#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     ´óÌü³¡¾°
*/

#ifndef __HALLSCENE_H__
#define __HALLSCENE_H__


#include "BaseScene.h"
//#include "UIManager.h"


class HallScene :public BaseScene
{
public:
	HallScene::HallScene();
	HallScene::~HallScene();
	const char* getSceneName() const;
	CREATE_FUNC(HallScene);
	virtual void onEnterTransitionDidFinish();
private:
	int m_ac;
	UIManager* m_uimagager;
};












#endif