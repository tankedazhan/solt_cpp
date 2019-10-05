#include "WolfConfig.h"

static WolfConfig *gWolfConfig = NULL;

WolfConfig::WolfConfig()
{
	this->m_size.height = 160;
	this->m_size.width = 160;
	this->m_num = 3;//可显示数量
	this->m_speed = 25;//每帧移动速度
	this->m_symbolCsbPath.clear();
	this->m_symbolCsbPath[0] = "wolfLighting/Socre_Pharaoh_1.csb";
	this->m_symbolCsbPath[1] = "wolfLighting/Socre_Pharaoh_2.csb";
	this->m_symbolCsbPath[2] = "wolfLighting/Socre_Pharaoh_3.csb";
	this->m_symbolCsbPath[3] = "wolfLighting/Socre_Pharaoh_4.csb";
	this->m_symbolCsbPath[4] = "wolfLighting/Socre_Pharaoh_5.csb";
	this->m_symbolCsbPath[5] = "wolfLighting/Socre_Pharaoh_6.csb";
	this->m_symbolCsbPath[6] = "wolfLighting/Socre_Pharaoh_7.csb";
	this->m_symbolCsbPath[7] = "wolfLighting/Socre_Pharaoh_8.csb";
	this->m_symbolCsbPath[8] = "wolfLighting/Socre_Pharaoh_9.csb";
	this->m_symbolCsbPath[9] = "wolfLighting/Socre_Pharaoh_Scatter.csb";
	this->m_symbolCsbPath[10] = "wolfLighting/Socre_Pharaoh_Special_1.csb";
	this->m_symbolCsbPath[11] = "wolfLighting/Socre_Pharaoh_Wild.csb";
	

	this->m_roll_list1 = "7,2,8,1,5,0,6,11,11,11,7,1,5,2,8,1,7,2,8,9,4,1,7,11,11,8,2,7,1,8,9,2,8,3,7,2,8,1,8,0,5,1,\
		11,11,11, 6, 2, 7, 0, 8, 3, 5, 7, 2, 5, 8, 11, 11, 11, 8, 2, 7, 5, 0, 5, 8, 1, 7, 4, 1, 5, 7, 9, 5, 0, 8, 2, 5, 8, 2, 11, 11, 8, 5, 2, 8, 3, 7, 2,\
		5, 3, 6, 9, 5, 1, 8, 0, 5, 6, 0, 8, 3, 7, 9, 2, 6, 2, 5, 8, 0, 5, 9, 8, 0, 7, 11, 11, 11, 2, 5, 4, 7, 1, 8, 2, 5, 1, 8, 4, 2, 7, 1, 11, 11,\
		11, 1, 8, 2, 4, 5, 1, 8, 2, 5, 3, 7, 4, 8, 1, 11, 11, 2, 5, 1, 8, 2, 7, 4, 5, 2, 4, 7, 1, 5, 11, 11, 11, 5, 2, 8, 1, 7, 2, 5, 1, 7, 2, 5, 3, 7,\
		11, 11, 7, 1, 8, 1, 5, 0, 7, 3, 5, 2, 7, 1, 6, 3, 8, 4, 7, 7";

	//int m_roll_list1[] = {};
	
	//this->m_roll_list1;
}

WolfConfig::~WolfConfig()
{
	this->m_symbolCsbPath.clear();
}

WolfConfig* WolfConfig::getInstance()
{
	if (!gWolfConfig)
	{
		gWolfConfig = new (std::nothrow) WolfConfig();
	}
	return gWolfConfig;
}

string WolfConfig::getSymbolPath(int symbolId)
{
	return this->m_symbolCsbPath[symbolId];
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