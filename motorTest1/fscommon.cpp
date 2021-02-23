#include "fscommon.h"
#include "qdebug.h"
#include "FsmState2.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif


FsmTable_t Table[] =
{
	//�������¼���   ��ǰ��״̬��     ��Ҫִ�еĶ�����   ��һ��״̬
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
	qDebug("������һ\r\n");
}

void GetTuesday()
{
	qDebug("�����ܶ�\r\n");
}

void GetWednesday()
{
	qDebug("��������\r\n");
}

void GetThursday()
{
	qDebug("��������\r\n");
}

void GetFriday()
{
	qDebug("��������\r\n");
}

void GetSaturday()
{
	qDebug("��������\r\n");
}

void GetSunday()
{
	qDebug("��������\r\n");
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


//����״̬�����¼�
void SetFSMEvent(int stateevent)
{
	//    FSM_SetStateEvent(stateevent);

}











