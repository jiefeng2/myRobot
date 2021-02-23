#pragma once
#include "qstring.h"
#include "FsmState2.h"


enum
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
};


enum
{
	EVENT1 = 1,
	EVENT2,
	EVENT3,
	EVENT4,
	EVENT5,
	EVENT6,
	EVENT7,
};


void InitFSM();
//设置状态机的事件
void SetFSMEvent(int stateevent);

void GetMonday();
void GetTuesday();
void GetWednesday();
void GetThursday();
void GetFriday();
void GetSaturday();
void GetSunday();

extern FsmTable_t Table[];

