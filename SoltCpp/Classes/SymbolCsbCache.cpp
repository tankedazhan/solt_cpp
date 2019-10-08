#include "SymbolCsbCache.h"



Symbol_Csb_Meta::Symbol_Csb_Meta():
node(nullptr),
action(nullptr),
used(false),
index(0),
symbolId(0),
nodeType("")
{
	csbVar.clear();
}

Symbol_Csb_Meta::~Symbol_Csb_Meta()
{

}


static SymbolCsbCache *gSymbolCsbCache = NULL;
SymbolCsbCache::SymbolCsbCache()
{
	this->m_symbolCsbList.clear();
}

SymbolCsbCache::~SymbolCsbCache()
{
	for (auto item = this->m_symbolCsbList.begin(); item != this->m_symbolCsbList.end(); ++item)
	{
		item->second.clear();
	}
	this->m_symbolCsbList.clear();
}

SymbolCsbCache* SymbolCsbCache::getInstance()
{
	if (!gSymbolCsbCache)
	{
		gSymbolCsbCache = new (std::nothrow) SymbolCsbCache();
	}
	return gSymbolCsbCache;
}



void SymbolCsbCache::createSymbolCsbNode()
{
	std::unordered_map<int, SymbolCsbConfig> config = WolfConfig::getInstance()->getSymbolCsbConfig();
	for ( auto item = config.begin(); item != config.end(); ++item )
	{
		int symbol_id = item->first;
		this->m_symbolCsbList[symbol_id].clear();
		for ( int i = 0; i < item->second.m_count; i++ )
		{
			Symbol_Csb_Meta * meta = new Symbol_Csb_Meta();
			meta->index = i + 1;
			meta->used = false;
			meta->node = CSLoader::createNodeWithVisibleSize(item->second.m_file);
			meta->node->retain();
			meta->action = CSLoader::createTimeline(item->second.m_file);
			meta->symbolId = i;
			meta->nodeType = item->second.m_resourcetype;
			meta->csbVar.clear();
			CSBUtil::getInstance()->addOwnerVariable(meta->csbVar,meta->node);
			this->m_symbolCsbList[symbol_id].push_back(meta);
		}
	}
}

const Symbol_Csb_Meta* SymbolCsbCache::getCsbNodeBySymbolId(int symbolId)
{
	for (auto item = this->m_symbolCsbList.at(symbolId).begin();item != this->m_symbolCsbList.at(symbolId).end(); ++item)
	{
		if ( (*item)->used == false )
		{
			(*item)->used = true;
			return *item;
		}
	}
	CCLOG("------------------------------------------XINJIAKAISHI");
	Symbol_Csb_Meta * meta = new Symbol_Csb_Meta();
	meta->index = this->m_symbolCsbList[symbolId].size() + 1;
	meta->used = false;
	meta->node = CSLoader::createNodeWithVisibleSize(WolfConfig::getInstance()->getSymbolPath(symbolId));
	meta->node->retain();
	meta->action = CSLoader::createTimeline(WolfConfig::getInstance()->getSymbolPath(symbolId));
	meta->symbolId = symbolId;
	meta->nodeType = WolfConfig::getInstance()->getResourcetype(symbolId);
	meta->csbVar.clear();
	CSBUtil::getInstance()->addOwnerVariable(meta->csbVar, meta->node);
	this->m_symbolCsbList[symbolId].push_back(meta);
	return meta;
	CCLOG("------------------------------------------XINJIAJIESU");
	//return nullptr;
}