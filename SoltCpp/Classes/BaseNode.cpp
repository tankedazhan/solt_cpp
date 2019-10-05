
#include "BaseNode.h"

USING_NS_CC;


BaseNode::BaseNode() :
	m_csbAct(nullptr),
	m_csbNode(nullptr)
{
	m_csbVar.clear();
}

BaseNode::~BaseNode()
{

}

bool BaseNode::init()
{
	if (!Node::init())
	{
		return false;
	}
	CCLOG("BaseNode::init");
	return true;
}

void BaseNode::onEnter()
{
	Node::onEnter();
	CCLOG("BaseNode::onEnter");
}

void BaseNode::onEnterTransitionDidFinish()
{
	Node::onEnterTransitionDidFinish();
	CCLOG("BaseNode::onEnterTransitionDidFinish");
}

void BaseNode::onExit()
{
	Node::onExit();
	CCLOG("BaseNode::onExit");
}

void BaseNode::onExitTransitionDidStart()
{
	Node::onExitTransitionDidStart();
	CCLOG("BaseNode::onExitTransitionDidStart");
}

void BaseNode::cleanup()
{
	Node::cleanup();
	CCLOG("BaseNode::cleanup");
}

void BaseNode::addCsb(string fileName,int zOrder)
{
	auto csb_node = CSBUtil::getInstance()->readNodeCsb(fileName, m_csbVar);
	
	this->addChild(csb_node,zOrder);
	
	this->m_csbNode = csb_node;
	this->m_csbAct = CSLoader::createTimeline(fileName);
	this->m_csbNode->runAction((Action *)this->m_csbAct);
}

void BaseNode::addCsb(string fileName)
{
	auto csb_node = CSBUtil::getInstance()->readNodeCsb(fileName, m_csbVar);

	this->addChild(csb_node);
	//addOwnerVariable(csb_node);
	this->m_csbNode = csb_node;
	this->m_csbAct = CSLoader::createTimeline(fileName);
	this->m_csbNode->runAction((Action *)this->m_csbAct);
}

//void BaseNode::addOwnerVariable(Node *node)
//{
//	if (node->getChildrenCount() > 0)
//	{
//		Vector<Node*> childs = node->getChildren();
//		for (auto item : childs)
//		{
//			std::string name = item->getName();
//			if (!name.empty() && name != "")
//			{
//				if (m_csbVar[name])
//				{
//					CCASSERT(false, __String::createWithFormat(" !! csb文件中存在同名的node name = % s !! ", name.c_str())->getCString());
//				}
//				m_csbVar[name] = item;
//			}
//			addOwnerVariable(item);
//		}
//	}
//}

Node* BaseNode::findChild(string name)
{
	return m_csbVar[name];
}