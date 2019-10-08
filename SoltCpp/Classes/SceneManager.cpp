#include "SceneManager.h"

#include "LoadingScene.h"
#include "HallScene.h"
#include "LevelScene.h"

USING_NS_CC;

static SceneManager *gSceneManager = NULL;

SceneManager::SceneManager():
	m_sceneType(SCENE_TYPE::NONE),
	m_nextSceneType(SCENE_TYPE::NONE)
{

}
SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::getInstance()
{
	if (!gSceneManager)
	{
		gSceneManager = new (std::nothrow) SceneManager();
	}
	return gSceneManager;
}

void SceneManager::goToHallSceneByLoading()
{
	if (m_sceneType == SCENE_TYPE::LOADING)
	{
		return;
	}
	m_sceneType = SCENE_TYPE::LOADING;
	this->m_nextSceneType = SCENE_TYPE::HALL;
	LoadingScene * loadingScene = LoadingScene::create();
	auto director = Director::getInstance();
	director->runWithScene( loadingScene );
	m_currentScene = loadingScene;
}

void SceneManager::goToHallScene()
{
	if (m_sceneType == SCENE_TYPE::HALL)
	{
		return;
	}
	m_sceneType = SCENE_TYPE::HALL;
	HallScene * hallScene = HallScene::create();
	auto director = Director::getInstance();
	director->replaceScene( hallScene );
	m_currentScene = hallScene;
}

void SceneManager::goToLevelSceneByLoading()
{
	if (m_sceneType == SCENE_TYPE::LOADING)
	{
		return;
	}
	m_sceneType = SCENE_TYPE::LOADING;
	this->m_nextSceneType = SCENE_TYPE::LEVEL;
	LoadingScene * loadingScene = LoadingScene::create();
	auto director = Director::getInstance();
	director->replaceScene(loadingScene);
	m_currentScene = loadingScene;
}

void SceneManager::goToLevelScene()
{
	if (m_sceneType == SCENE_TYPE::LEVEL)
	{
		return;
	}
	m_sceneType = SCENE_TYPE::LEVEL;
	LevelScene * levelScene = LevelScene::create();
	auto director = Director::getInstance();
	director->replaceScene(levelScene);
	m_currentScene = levelScene;
	
}

SCENE_TYPE SceneManager::getNextSceneType()
{
	return this->m_nextSceneType;
}