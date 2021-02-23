#include "fscommon.h"
#include "qdebug.h"
#include "FsmState2.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif


FsmTable_t Table[] =
{
	//到来的事件，   当前的状态，     将要执行的动作，   下一个状态
	{ EVENT1,      Monday,        GetMonday,     Tuesday },
	{ EVENT2,      Tuesday,       GetTuesday,    Wednesday },
	{ EVENT3,      Wednesday,     GetWednesday,  Thursday },
	{ EVENT4,      Thursday,      GetThursday,   Friday },
	{ EVENT5,      Friday,        GetFriday,     Saturday },
	{ EVENT6,      Saturday,      GetSaturday,   Sunday },
	{ EVENT7,      Sunday,        GetSunday,     Monday },
};


void GetMonday()
{
	qDebug("我是周一\r\n");
}

void GetTuesday()
{
	qDebug("我是周二\r\n");
}

void GetWednesday()
{
	qDebug("我是周三\r\n");
}

void GetThursday()
{
	qDebug("我是周四\r\n");
}

void GetFriday()
{
	qDebug("我是周五\r\n");
}

void GetSaturday()
{
	qDebug("我是周六\r\n");
}

void GetSunday()
{
	qDebug("我是周日\r\n");
}


void polling_day(int *event)
{
	if (*event == 7)
	{
		*event = 1;
	}
	else
	{
		(*event)++;
	}
}


void InitFSM()
{
	FsmState2 *pfsmstate = new FsmState2(Table, sizeof(Table) / sizeof(FsmTable_t), Monday);

	qDebug() << "state num = " << pfsmstate->FSM_GetStateNum();
}


//设置状态机的事件
void SetFSMEvent(int stateevent)
{
	//    FSM_SetStateEvent(stateevent);

}











