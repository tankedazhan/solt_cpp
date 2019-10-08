#include "WolfConfig.h"


SymbolCsbConfig::SymbolCsbConfig(string file, string resourcetype, int count)
{
	m_file = file;
	m_resourcetype = resourcetype;
	m_count = count;
}

SymbolCsbConfig::SymbolCsbConfig()
{

}

SymbolCsbConfig::~SymbolCsbConfig()
{
	
}

static WolfConfig *gWolfConfig = NULL;

WolfConfig::WolfConfig()
{
	this->m_size.height = 160;
	this->m_size.width = 160;
	this->m_num = 3;//可显示数量
	this->m_speed = 25;//每帧移动速度
	this->m_symbolCsbConfig.clear();

	this->m_symbolCsbConfig[0] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_1.csb", "csb", 15);
	this->m_symbolCsbConfig[1] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_2.csb", "csb", 15);
	this->m_symbolCsbConfig[2] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_3.csb", "csb", 15);
	this->m_symbolCsbConfig[3] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_4.csb", "csb", 15);
	this->m_symbolCsbConfig[4] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_5.csb", "csb", 15);
	this->m_symbolCsbConfig[5] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_6.csb", "csb", 15);
	this->m_symbolCsbConfig[6] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_7.csb", "csb", 15);
	this->m_symbolCsbConfig[7] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_8.csb", "csb", 15);
	this->m_symbolCsbConfig[8] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_9.csb", "csb", 15);
	this->m_symbolCsbConfig[9] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_Scatter.csb", "csb", 15);
	this->m_symbolCsbConfig[10] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_Wild.csb", "csb", 15);
	this->m_symbolCsbConfig[11] = SymbolCsbConfig("wolfLighting/Socre_Pharaoh_Special_1.csb", "csb", 15);
	

	this->m_roll_list1 = "7,2,8,1,5,0,6,11,11,11,7,1,5,2,8,1,7,2,8,9,4,1,7,11,11,8,2,7,1,8,9,2,8,3,7,2,8,1,8,0,5,1,\
		11,11,11, 6, 2, 7, 0, 8, 3, 5, 7, 2, 5, 8, 11, 11, 11, 8, 2, 7, 5, 0, 5, 8, 1, 7, 4, 1, 5, 7, 9, 5, 0, 8, 2, 5, 8, 2, 11, 11, 8, 5, 2, 8, 3, 7, 2,\
		5, 3, 6, 9, 5, 1, 8, 0, 5, 6, 0, 8, 3, 7, 9, 2, 6, 2, 5, 8, 0, 5, 9, 8, 0, 7, 11, 11, 11, 2, 5, 4, 7, 1, 8, 2, 5, 1, 8, 4, 2, 7, 1, 11, 11,\
		11, 1, 8, 2, 4, 5, 1, 8, 2, 5, 3, 7, 4, 8, 1, 11, 11, 2, 5, 1, 8, 2, 7, 4, 5, 2, 4, 7, 1, 5, 11, 11, 11, 5, 2, 8, 1, 7, 2, 5, 1, 7, 2, 5, 3, 7,\
		11, 11, 7, 1, 8, 1, 5, 0, 7, 3, 5, 2, 7, 1, 6, 3, 8, 4, 7, 7";

	//int m_roll_list1[] = {};
	//大厅的Plist资源
	this->m_hallResourceOfPlist[0] = "LuckySlot/SlotPlist1.plist";
	this->m_hallResourceOfPlist[1] = "LuckySlot/SlotPlist2.plist";
	//狼关卡资源
	this->m_wolfLevelResourceOfPlist[0] = "wolfLighting/Pharaoh1.plist";
	this->m_wolfLevelResourceOfPlist[1] = "wolfLighting/Pharaoh2.plist";
	this->m_wolfLevelResourceOfPlist[2] = "wolfLighting/Pharaoh3.plist";
	this->m_wolfLevelResourceOfPlist[3] = "wolfLighting/Pharaoh4.plist";
	this->m_wolfLevelResourceOfPlist[4] = "wolfLighting/Pharaoh5.plist";
	this->m_wolfLevelResourceOfPlist[5] = "wolfLighting/Pharaoh6.plist";
	this->m_wolfLevelResourceOfPlist[6] = "wolfLighting/Pharaoh7.plist";

	//中奖号码
	this->m_winNumStr = "3,3,3";
	
	//this->m_roll_list1;
}

WolfConfig::~WolfConfig()
{
	this->m_symbolCsbConfig.clear();
}

WolfConfig* WolfConfig::getInstance()
{
	if (!gWolfConfig)
	{
		gWolfConfig = new (std::nothrow) WolfConfig();
	}
	return gWolfConfig;
}

const std::unordered_map<int, SymbolCsbConfig>& WolfConfig::getSymbolCsbConfig()
{
	return this->m_symbolCsbConfig;
}

const SymbolCsbConfig& WolfConfig::getSymbolCsbConfig(int symbolId) const
{
	return this->m_symbolCsbConfig.at(symbolId);
}

string WolfConfig::getSymbolPath(int symbolId)
{
	return this->m_symbolCsbConfig.at(symbolId).m_file;
}
string WolfConfig::getResourcetype(int symbolId)
{
	return this->m_symbolCsbConfig.at(symbolId).m_resourcetype;
}

Size WolfConfig::getSymbolSize()
{
	return this->m_size;
}

int WolfConfig::getNum()
{
	return this->m_num;
}

string WolfConfig::getRollList1()
{
	return this->m_roll_list1;
}

int WolfConfig::getSpeed()
{
	return this->m_speed;
}

string WolfConfig::getWinNumStr()
{
	return this->m_winNumStr;
}

std::unordered_map<int, string> WolfConfig::getHallResourceOfPlist()
{
	return this->m_hallResourceOfPlist;
}

std::unordered_map<int, string> WolfConfig::getWolfLevelResourceOfPlist()
{
	return this->m_wolfLevelResourceOfPlist;
}