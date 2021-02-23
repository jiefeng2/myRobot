#pragma once

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>

//状态机中的状态
typedef struct FsmTable_s
{
	int event;                  //事件
	int CurState;               //当前状态
	void(*eventActFun)();      //函数指针
	int NextState;              //下一个状态
								//    QString StateName;          //状态名称

}FsmTable_t;

typedef struct FSM_s
{
	FsmTable_t *FsmTable;       //指向的状态表
	int curState;
}FSM_t;


class FsmState2 : public QObject
{
	Q_OBJECT

public:
	FsmState2(QObject *parent);
	~FsmState2();

	FsmState2(FsmTable_t *ptable, int statenum, int curstate, QObject *parent = 0);
	//    void FSM_ChangeState(int curstate);                     //改变状态机的状态
	void FSM_SetStateEvent(int stateevent);                //设置状态机的事件
	int FSM_GetCurState();                                 //获取状态机的当前状态
	int FSM_GetStateNum(void);                              //获取状态机的状态数量

private:
	bool IsEnableFSM;										//是否使能FSM
	FSM_t tFsm;
	int nMaxStateNum;                                       //状态表中含有的状态机的个数
	QTimer *pStateTimer;                                    //状态机定时器
	int nNewStateEvent;                                     //状态机的新事件
	int nOldStateEvent;                                     //状态机的旧事件

	void FSM_Regist(FSM_t* pFsm, FsmTable_t* pTable);       //状态机注册
	void FSM_StateTransfer(FSM_t* pFsm, int state);         //状态机迁移
	void FSM_EventHandle(FSM_t* pFsm, int event);           //事件处理
	void FSMInit();											//初始化FSM

signals:

	public slots :
		void OnpStateTimer();


};
