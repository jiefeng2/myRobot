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


//״̬��ע��
void FsmState2::FSM_Regist(FSM_t* pFsm, FsmTable_t* pTable)
{
	pFsm->FsmTable = pTable;
}


/*״̬Ǩ��*/
void FsmState2::FSM_StateTransfer(FSM_t* pFsm, int state)
{
	pFsm->curState = state;

}

/*�¼�����*/
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
		qDebug() << "û�ж�Ӧ��״̬��";
		qDebug("state = %d, event = %d", CurState, event);
	}
}


/*
//�ı�״̬����״̬
void FsmState::FSM_ChangeState(int curstate)
{
this->tFsm.curState = curstate;
}
*/


//��ȡ״̬����״̬����
int FsmState2::FSM_GetStateNum(void)
{
	return nMaxStateNum;
}

//�ڶ�ʱ���н���״̬�л�
void FsmState2::OnpStateTimer()
{
//	qDebug() << "OnpStateTimer timerout";

	if (nNewStateEvent != nOldStateEvent)
	{
		FSM_EventHandle(&tFsm, nNewStateEvent);
		nOldStateEvent = nNewStateEvent;
	}
}

//����״̬�����¼�
void FsmState2::FSM_SetStateEvent(int stateevent)
{
	nNewStateEvent = stateevent;
}

//��ȡ״̬���ĵ�ǰ״̬
int FsmState2::FSM_GetCurState()
{
	return nNewStateEvent;
}

