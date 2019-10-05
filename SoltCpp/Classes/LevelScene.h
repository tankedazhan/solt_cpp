#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     ¹Ø¿¨³¡¾°
*/

#ifndef __LEVELSCENE_H__
#define __LEVELSCENE_H__


#include "BaseScene.h"
//#include "UIManager.h"


class LevelScene :public BaseScene
{
public:
	LevelScene::LevelScene();
	LevelScene::~LevelScene();
	const char* getSceneName() const;
	CREATE_FUNC(LevelScene);
	virtual void onEnterTransitionDidFinish();
private:
	int m_ac;
	UIManager* m_uimagager;
};












#endif