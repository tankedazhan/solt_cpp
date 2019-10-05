#include "EasyFunc.h"


static EasyFunc *gEasyFunc = NULL;

EasyFunc::EasyFunc()
{

}
EasyFunc::~EasyFunc()
{

}

EasyFunc* EasyFunc::getInstance()
{
	if (!gEasyFunc)
	{
		gEasyFunc = new (std::nothrow) EasyFunc();
	}
	return gEasyFunc;
}


void EasyFunc::split(const string& s, vector<int>& sv, const char flag ) 
{
	sv.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, flag)) {
		sv.push_back(stoi(temp));
	}
}