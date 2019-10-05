#pragma once
/*
author:   liuzhiyong
date:     2019-10-1
desc:     ≥°æ∞π‹¿Ì
*/
#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "BaseScene.h"
USING_NS_CC;
using namespace std;
using namespace cocostudio;

enum SCENE_TYPE
{
	NONE,
	LOADING,
	HALL,
	LEVEL
};


class SceneManager
{
public:
	SceneManager::SceneManager();
	SceneManager::~SceneManager();

	static SceneManager* getInstance();

	void goToHallSceneByLoading();
	void goToHallScene();
	void goToLevelSceneByLoading();
	void goToLevelScene();

	SCENE_TYPE getSceneType() { return m_sceneType; }

	BaseScene * getCurrentScene() { return m_currentScene; }
private:
	SCENE_TYPE m_sceneType;
	BaseScene * m_currentScene;
};







#endif