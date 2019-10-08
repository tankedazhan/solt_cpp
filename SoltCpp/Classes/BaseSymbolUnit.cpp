#include "BaseSymbolUnit.h"
#include "WolfConfig.h"
#include "SymbolCsbCache.h"

USING_NS_CC;


BaseSymbolUnit::BaseSymbolUnit()
{
	this->m_size = WolfConfig::getInstance()->getSymbolSize();
	//this->m_symbolCsbList.clear;
}
BaseSymbolUnit::~BaseSymbolUnit()
{

}

void BaseSymbolUnit::onEnter()
{
	Node::onEnter();
}
void BaseSymbolUnit::onExit()
{
	Node::onExit();
}

//void BaseSymbolUnit::initStart(Size size)
//{
//	
////}


void BaseSymbolUnit::loadDataUI(int symbolId)
{
	this->createSymbolCsbNode(symbolId);
}

void BaseSymbolUnit::createSymbolCsbNode(int symbolId)
{
	//string path = WolfConfig::getInstance()->getSymbolPath(symbolId);
	//CCLOG("PATH--------------------------%s", path);
	//this->addCsb(path);
	//this->setPosition(this->m_size.width / 2, this->m_size.height / 2);
	//CCLOG("PATH--------------------------%s", this);

	const Symbol_Csb_Meta* meta = SymbolCsbCache::getInstance()->getCsbNodeBySymbolId(symbolId);
	if (meta && meta->node) {
		this->addChild(meta->node);
	}
	else
	{
		CCLOG("-----------------------------> error symbolId = %d", symbolId);
	}
	
}

void BaseSymbolUnit::getCsbNodeBySymbolId(string symbolId)
{
	
}