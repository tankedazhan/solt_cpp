
#include "BaseNode.h"

USING_NS_CC;

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
	CCLOG("BaseNode::onEnter");
}

void BaseNode::onEnterTransitionDidFinish()
{
	CCLOG("BaseNode::onEnterTransitionDidFinish");
}

void BaseNode::onExit()
{
	CCLOG("BaseNode::onExit");
}

void BaseNode::onExitTransitionDidStart()
{
	CCLOG("BaseNode::onExitTransitionDidStart");
}

void BaseNode::cleanup()
{
	CCLOG("BaseNode::cleanup");
}