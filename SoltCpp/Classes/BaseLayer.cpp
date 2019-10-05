
#include "BaseLayer.h"

USING_NS_CC;


BaseLayer::BaseLayer() :
	m_csbNode(nullptr),
	m_csbAct(nullptr)
{
	m_csbVar.clear();
}

BaseLayer::~BaseLayer()
{

}

bool BaseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void BaseLayer::onEnter()
{
	Layer::onEnter();
	CCLOG("BaseLayer::onEnter");
}

void BaseLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CCLOG("BaseLayer::onEnterTransitionDidFinish");
}

void BaseLayer::onExit()
{
	Layer::onExit();
	CCLOG("BaseLayer::onExit");
}

void BaseLayer::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	CCLOG("BaseLayer::onExitTransitionDidStart");
}

void BaseLayer::cleanup()
{
	Layer::cleanup();
	CCLOG("BaseLayer::cleanup");
}

void BaseLayer::addCsb(string fileName, int zOrder)
{
	auto csb_node = CSBUtil::getInstance()->readLayerCsb(fileName, m_csbVar);
	this->addChild(csb_node, zOrder);
	this->m_csbNode = csb_node;
	this->m_csbAct = CSLoader::createTimeline(fileName);
	this->m_csbNode->runAction((Action *)this->m_csbAct);
}
void BaseLayer::addCsb(string fileName)
{
	//auto csb_node = CSLoader::createNode(fileName);

	//auto director = Director::getInstance();
	//auto glview = director->getOpenGLView();
	//Size frameSize = glview->getFrameSize();
	////csb_node->setContentSize(frameSize.setSize);

	//addOwnerVariable(csb_node);
	auto csb_node = CSBUtil::getInstance()->readLayerCsb(fileName, m_csbVar);
	this->addChild(csb_node);
	this->m_csbNode = csb_node;
	this->m_csbAct = CSLoader::createTimeline(fileName);
	this->m_csbNode->runAction((Action *)this->m_csbAct);
	

	
	
}

Node* BaseLayer::findChild(string name)
{
	/*for (auto item : this->m_csbVar)
	{
		CCLOG("BaseLayer::addCsb-------------------%s\n", item);
	}
	CCLOG("BaseLayer::findChild-------------------222222222222222222222222222222");
	CCLOG("BaseLayer::findChild-------------------%s\n", this->m_csbVar[name]);*/
	return m_csbVar[name];
}
