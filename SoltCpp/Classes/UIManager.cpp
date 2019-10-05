#include "UIManager.h"

USING_NS_CC;


UIManager::UIManager( Scene* scene )
{
	m_nodeList.clear();
	CCASSERT( scene, "ERROR scene is null" );
	this->m_scene = scene;
	this->createUiGroup();
}

UIManager::~UIManager()
{
	CCLOG("UIManager::~UIManager");
	m_nodeList.clear();
}


void UIManager::createUiGroup()
{
	for (UI_GROUP_DEFINE flag = UI_GROUP_DEFINE::Main; flag <= UI_GROUP_DEFINE::Loading; (UI_GROUP_DEFINE)flag++)
	{
		Node *node = Node::create();
		node->setTag(flag);
		this->m_scene->addChild(node, flag);
		this->m_nodeList[flag] = node;
	}
}

void UIManager::addLayer(Layer* layer, UI_GROUP_DEFINE flag, LAYER_FLAG_DEFING layer_flag)
{
	this->m_nodeList[flag]->addChild(layer);
	layer->setTag( layer_flag );
	//layer->setUserData((int*)flag);
}

void UIManager::removeLayer(UI_GROUP_DEFINE flag, LAYER_FLAG_DEFING layer_flag)
{
	auto layer = this->m_nodeList[flag]->getChildByTag( layer_flag );
	layer->removeFromParent();
}
