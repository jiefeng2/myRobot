#pragma once

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>

//״̬���е�״̬
typedef struct FsmTable_s
{
	int event;                  //�¼�
	int CurState;               //��ǰ״̬
	void(*eventActFun)();      //����ָ��
	int NextState;              //��һ��״̬
								//    QString StateName;          //״̬����

}FsmTable_t;

typedef struct FSM_s
{
	FsmTable_t *FsmTable;       //ָ���״̬��
	int curState;
}FSM_t;


class FsmState2 : public QObject
{
	Q_OBJECT

public:
	FsmState2(QObject *parent);
	~FsmState2();

	FsmState2(FsmTable_t *ptable, int statenum, int curstate, QObject *parent = 0);
	//    void FSM_ChangeState(int curstate);                     //�ı�״̬����״̬
	void FSM_SetStateEvent(int stateevent);                //����״̬�����¼�
	int FSM_GetCurState();                                 //��ȡ״̬���ĵ�ǰ״̬
	int FSM_GetStateNum(void);                              //��ȡ״̬����״̬����

private:
	bool IsEnableFSM;										//�Ƿ�ʹ��FSM
	FSM_t tFsm;
	int nMaxStateNum;                                       //״̬���к��е�״̬���ĸ���
	QTimer *pStateTimer;                                    //״̬����ʱ��
	int nNewStateEvent;                                     //״̬�������¼�
	int nOldStateEvent;                                     //״̬���ľ��¼�

	void FSM_Regist(FSM_t* pFsm, FsmTable_t* pTable);       //״̬��ע��
	void FSM_StateTransfer(FSM_t* pFsm, int state);         //״̬��Ǩ��
	void FSM_EventHandle(FSM_t* pFsm, int event);           //�¼�����
	void FSMInit();											//��ʼ��FSM

signals:

	public slots :
		void OnpStateTimer();


};
