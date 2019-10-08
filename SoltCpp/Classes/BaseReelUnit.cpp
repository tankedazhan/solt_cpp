#include "BaseReelUnit.h"
#include "WolfConfig.h"
//#include "CCClippingRectangleNode.h"
//NS_CC_BEGIN
#include "EasyFunc.h"



BaseReelUnit::BaseReelUnit()
{
	this->m_size = WolfConfig::getInstance()->getSymbolSize();
	this->m_symbolUnit = nullptr;
	this->m_symbolUnitList.clear();
	this->m_num = WolfConfig::getInstance()->getNum();		//��ǰ��ʾ�ĵ�Ԫ��
	this->m_symbolTotalNum = this->m_num + 2;				//��Ҫ�����ĵ�Ԫ��
	this->m_symbolCurrentNum = 0;	//��ǰ��Ҫ�������źſ�ı�ʶ
	this->m_clippingNode = nullptr;
	this->m_list1 = WolfConfig::getInstance()->getRollList1();
	this->m_roll_list1.clear();//�źſ����б�
	this->m_topSymbolUnit = nullptr;//���Ϸ��źſ�
	this->m_topSymbolUnitOfHold = nullptr;//ֹͣʱ���Ϸ��źſ�
	this->getListToArray();
	this->m_rollState = true;
	//this->m_winNumStr = NULL;
	this->m_winNumInt.clear();
	this->m_winNumIntOfHold.clear();//�����滻�����ݣ������������ȥ
	this->m_symbolCurrentNumOfHold = 0;//�����滻���ݵı�ʶ

	
	//this->sp_reel_1 = nullptr;
	//this->size = WolfConfig::getSymbolSize;
}
BaseReelUnit::~BaseReelUnit()
{
	this->m_symbolUnitList.clear();
}
bool BaseReelUnit::init()
{
	if (!Node::init())
	{
		return false;
	}
	//scheduleUpdate();
	return true;
}
void BaseReelUnit::onEnter()
{
	Node::onEnter();
}
void BaseReelUnit::onExit()
{
	Node::onExit();
}

void BaseReelUnit::loadReelUI()
{
	this->addClipNode();
	for (int i = 0; i < this->m_symbolTotalNum; i++)
	{
		this->createSymbolCsbFullReel();
		
		//this->m_symbolUnit->setPosition(this->m_size.width / 2,i * this->m_size.height - this->m_size.height/2);
	}
	
}

//�����µ��źſ�
void BaseReelUnit::createSymbolCsbFullReel()
{
	this->m_symbolUnit = BaseSymbolUnit::create();
	this->m_symbolUnit->loadDataUI(this->m_roll_list1[this->m_symbolCurrentNum]);
	//��������
	
	//int n_size = this->m_symbolUnitList.size();
	if (this->m_symbolUnitList.size() == 0)
	{
		this->m_symbolUnit->setPosition(this->m_size.width / 2, -this->m_size.height / 2);
	}
	else
	{
		auto end_unit = this->m_symbolUnitList.back();
		int end_posy = end_unit->getPositionY();
		end_posy = end_posy + this->m_size.height;
		this->m_symbolUnit->setPosition(this->m_size.width / 2, end_posy);
	}

	//this->m_symbolUnitList[this->m_symbolCurrentNum] = this->m_symbolUnit;
	this->m_symbolUnitList.push_back(this->m_symbolUnit);
	//this->addChild(m_symbolUnit);
	this->m_clippingNode->addChild(m_symbolUnit);
	this->m_symbolCurrentNum = this->m_symbolCurrentNum + 1;
	if (this->m_symbolCurrentNum == this->m_roll_list1.size())
	{
		this->m_symbolCurrentNum = 0;
	}
	this->m_topSymbolUnit = (BaseSymbolUnit*)this->m_symbolUnit;

	//this->symbolUnit->setPosition();
	//CCLOG("symbolUnit--------------------------%s", this->symbolUnit);
	//this->sp_reel_1 = (Sprite*)this->findChild("sp_reel_1");
	//this->sp_reel_1->addChild(symbolUnit);
}
//��ʼ���ü�����
void BaseReelUnit::addClipNode()
{
	if (this->m_clippingNode == nullptr)
	{
		this->m_clippingNode = ClippingRectangleNode::create();
		this->addChild(this->m_clippingNode);
	}
	this->m_clippingNode->setClippingRegion(Rect(0,0,this->m_size.width,this->m_size.height * this->m_num));


	//auto m_clippingNode = ClippingRectangleNode::create();
	//m_clippingNode->setClippingRegion(Rect(0, 0, this->m_size.width, this->m_size.height * this->m_num));//ģ���С
	//this->addChild(m_clippingNode);

	//for (int i = 0; i < this->m_symbolTotalNum; i++)
	//{
	//	this->m_symbolUnit = BaseSymbolUnit::create();
	//	this->m_symbolUnit->loadDataUI(i + 1);
	//	//this->addChild(m_symbolUnit);
	//	m_clippingNode->addChild(m_symbolUnit);
	//	this->m_symbolUnitList[i + 1] = this->m_symbolUnit;
	//	this->m_symbolUnit->setPosition(this->m_size.width / 2, i * this->m_size.height - this->m_size.height / 2);
	//}
	
}

void BaseReelUnit::getListToArray()
{
	EasyFunc::getInstance()->split(WolfConfig::getInstance()->getRollList1(), this->m_roll_list1,',');
}

void BaseReelUnit::startJumpAction()
{
	
	this->do_began = 0;
	//int do_end = this->m_symbolUnitList.
	for (auto item : this->m_symbolUnitList)
	{
		
		this->do_began = this->do_began + 1;
		auto move_action = MoveBy::create(0.2f, Vec2(0,30));
		auto sine_out = EaseSineOut::create(move_action);
		auto roll_began = CallFunc::create([&] {
			
			if (this->do_began == this->m_symbolUnitList.size())
			{
				this->schedule(schedule_selector(BaseReelUnit::updataSymbolUnit));
				
				//this->updataSymbolUnit();
			}
		});
		auto seq = Sequence::createWithTwoActions(sine_out, roll_began);
		item->runAction(seq);
	}
	

}
//�ص�����
void BaseReelUnit::updataSymbolUnit(float dt)
{
	//����
	for (auto item : this->m_symbolUnitList)
	{
		auto pos = item->getPositionY();
		pos = pos - WolfConfig::getInstance()->getSpeed();
		item->setPositionY(pos);
	}
	//�����źſ�
	if (this->m_symbolUnitList[0]->getPositionY() <= -WolfConfig::getInstance()->getSymbolSize().height / 2 - WolfConfig::getInstance()->getSymbolSize().height)
	{
		//CCLOG("---------------------------SHENGYUD-------%d", this->m_symbolUnitList.size());
		auto n_unit = this->m_symbolUnitList.begin();
		this->m_symbolUnitList.erase(n_unit);
		this->createSymbolCsbFullReel();
	}

	//�Ƿ�ֹͣ
	if (this->m_rollState == false)
	{
		if (this->m_topSymbolUnitOfHold->getPositionY() <= -this->m_size.width / 2)
		{
			this->m_rollState = true;
			this->unschedule(schedule_selector(BaseReelUnit::updataSymbolUnit));
			this->reviseSymbolPosition();
		}
	}
}
//ֹͣ��λ��У��
void BaseReelUnit::reviseSymbolPosition()
{
	if (this->m_topSymbolUnitOfHold->getPositionY() >= -this->m_size.width / 2)
	{
		return;
	}
	auto moveY = this->m_size.width / 2 - this->m_topSymbolUnitOfHold->getPositionY();
	for (auto item : this->m_symbolUnitList)
	{
		auto move_by = MoveBy::create(0.1f,Vec2(0, moveY));
		item->runAction(move_by);
	}
}

//ֹͣ����
void BaseReelUnit::stopRoll(string destData)
{
	this->m_winNumStr = destData;
	EasyFunc::getInstance()->split(this->m_winNumStr, this->m_winNumInt, ',');
	this->m_rollState = false;
	//��������
	this->m_topSymbolUnitOfHold = this->m_topSymbolUnit;
	//this->m_topSymbolUnit = (BaseSymbolUnit*)this->m_symbolUnit;
	this->m_topSymbolUnitOfHold = this->m_topSymbolUnit;
	int i = 0;
	for (auto item : this->m_winNumInt)
	{
		this->m_winNumIntOfHold.push_back(this->m_roll_list1[this->m_symbolCurrentNum + i]);
		this->m_roll_list1[this->m_symbolCurrentNum + i] = item;
		i = i + 1;
	}
}