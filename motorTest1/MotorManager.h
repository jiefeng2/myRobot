#pragma once

#include <QObject>
#include "common.h"
#include "SCLLibHelper.h"
#include <QMap>

#define  MAX_MOTOR_NUM   (5)			//���������Ŀ

class MotorManager : public QObject
{
	Q_OBJECT

public:
	MotorManager(QObject *parent);
	~MotorManager();

	SCLLibHelper *p_Motor_SCLLibHelper[MAX_MOTOR_NUM];
	QMap<int, int> motorPortMap;					//�������������źʹ��ں�

	QMap<int, bool>IsMotorPortOpenMap;				//�����Ӧ�Ĵ����Ƿ񱻴�

	bool OpenMotorPort(int motorindex, int port_num);
	bool SetMotorMove(int motorindex, int nDistance, double* dVelocity, double* dAccel, double* dDecel);
	bool SetMotorStopMove(int motorindex);
	//�رյ���Ĵ���
	bool CloseMotorPort(int motorindex);
	bool WriteOutput(int ynum, int motorindex, bool isHigh);


	//���״̬��غ���
	bool IsMotorEnable(int motorindex);
	bool IsMoving(int motorindex);
	bool IsStopping(int motorindex);
	bool IsInAlarmCWLimit(int motorindex);
	bool IsInAlarmCCWLimit(int motorindex);
	bool IsInPosition(int motorindex);

	int ReadInput(int motorindex);


};
