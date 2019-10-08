#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     loading����
*/

#ifndef __LOADINGSCENE_H__
#define __LOADINGSCENE_H__


#include "BaseScene.h"
#include "UIManager.h"


class LoadingScene :public BaseScene
{
public:
	LoadingScene::LoadingScene();
	LoadingScene::~LoadingScene();
	const char* getSceneName() const;
	CREATE_FUNC(LoadingScene);
	//static LoadingScene* create(SCENE_TYPE sceneType);
	//virtual bool init(SCENE_TYPE sceneType);
	virtual void onEnterTransitionDidFinish();
private:
	int m_ac;
	UIManager* m_uimagager;
};












#endif