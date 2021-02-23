#include "FsmState2.h"

FsmState2::FsmState2(QObject *parent)
	: QObject(parent)
{
}

FsmState2::~FsmState2()
{
}






#if 1
FsmState2::FsmState2(FsmTable_t *ptable, int statenum, int curstate, QObject *parent) :
	QObject(parent)
{
	nMaxStateNum = statenum;
	tFsm.curState = curstate;
	//    tFsm->curState = Monday;
	FSM_Regist(&tFsm, ptable);

	nNewStateEvent = 0;
	nOldStateEvent = 0;

	pStateTimer = new QTimer();
	pStateTimer->setInterval(2);
	//    QObject::connect(pStateTimer, SIGNAL(timeout()), this, SLOT(OnpStateTimer()));
	QObject::connect(pStateTimer, SIGNAL(timeout()), this, SLOT(OnpStateTimer()));
	pStateTimer->start();
}
#endif


//状态机注册
void FsmState2::FSM_Regist(FSM_t* pFsm, FsmTable_t* pTable)
{
	pFsm->FsmTable = pTable;
}


/*状态迁移*/
void FsmState2::FSM_StateTransfer(FSM_t* pFsm, int state)
{
	pFsm->curState = state;

}

/*事件处理*/
void FsmState2::FSM_EventHandle(FSM_t* pFsm, int event)
{
	FsmTable_t* pActTable = pFsm->FsmTable;
	void(*eventActFun)() = NULL;
	int NextState;
	int CurState = pFsm->curState;
	bool flag = false;

	for (int i = 0; i<nMaxStateNum; i++)
	{
		if (event == pActTable[i].event)
		{
			if (CurState == pActTable[i].CurState)
			{
				flag = true;
				eventActFun = pActTable[i].eventActFun;
				NextState = pActTable[i].NextState;
				break;
			}
		}
	}

	if (flag)
	{
		if (eventActFun)
		{
			eventActFun();
			//            FSM_StateTransfer(pFsm, NextState);
		}
		FSM_StateTransfer(pFsm, NextState);
		flag = false;
	}
	else
	{
		qDebug() << "没有对应的状态表";
		qDebug("state = %d, event = %d", CurState, event);
	}
}


/*
//改变状态机的状态
void FsmState::FSM_ChangeState(int curstate)
{
this->tFsm.curState = curstate;
}
*/


//获取状态机的状态数量
int FsmState2::FSM_GetStateNum(void)
{
	return nMaxStateNum;
}

//在定时器中进行状态切换
void FsmState2::OnpStateTimer()
{
//	qDebug() << "OnpStateTimer timerout";

	if (nNewStateEvent != nOldStateEvent)
	{
		FSM_EventHandle(&tFsm, nNewStateEvent);
		nOldStateEvent = nNewStateEvent;
	}
}

//设置状态机的事件
void FsmState2::FSM_SetStateEvent(int stateevent)
{
	nNewStateEvent = stateevent;
}

//获取状态机的当前状态
int FsmState2::FSM_GetCurState()
{
	return nNewStateEvent;
}

