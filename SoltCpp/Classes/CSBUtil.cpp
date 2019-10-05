#include "CSBUtil.h"

USING_NS_CC;

static CSBUtil *gCsbUtil = NULL;

CSBUtil::CSBUtil() 
{
	
}
CSBUtil::~CSBUtil()
{

}

CSBUtil* CSBUtil::getInstance()
{
	if (!gCsbUtil)
	{
		gCsbUtil = new (std::nothrow) CSBUtil();
	}
	return gCsbUtil;
}

Node* CSBUtil::readLayerCsb(string csbFilePath, std::unordered_map<std::string, Node*>& csbVar)
{
	auto csb_node = CSLoader::createNodeWithVisibleSize(csbFilePath);
	this->addOwnerVariable(csbVar, csb_node);
	//auto csb_act = CSLoader::createTimeline(csbFilePath);
	//csb_node->runAction((Action *)csb_act);
	return csb_node;
}
Node* CSBUtil::readNodeCsb(string csbFilePath, std::unordered_map<std::string, Node*>& csbVar)
{
	auto csb_node = CSLoader::createNode(csbFilePath);
	this->addOwnerVariable(csbVar, csb_node);
	//auto csb_act = CSLoader::createTimeline(csbFilePath);
	//csb_node->runAction((Action *)csb_act);
	return csb_node;
}

void CSBUtil::addOwnerVariable(std::unordered_map<std::string, Node*>& csbVar, Node* node)
{
	if ( node->getChildrenCount() > 0 )
	{
		Vector<Node*> childs = node->getChildren();
		for(auto item : childs)
		{
			std::string name = item->getName();
			if (!name.empty() && name != "")
			{
				if(csbVar[name])
				{
					//CCASSERT(false, __String::createWithFormat(" !! csb文件中存在同名的node name = % s !! ", name.c_str())->getCString());
					CCASSERT(false,__String::createWithFormat(" !! csb文件中存在同名的node name = % s !! ",name.c_str())->getCString());
				}
				csbVar[name] = item;
			}
			addOwnerVariable(csbVar,item);
		}
	}
}