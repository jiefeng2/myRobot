#pragma once

#include <QObject>
#include "common.h"
#include "SCLLibHelper.h"
#include <QMap>

#define  MAX_MOTOR_NUM   (5)			//最大电机的数目

class MotorManager : public QObject
{
	Q_OBJECT

public:
	MotorManager(QObject *parent);
	~MotorManager();

	SCLLibHelper *p_Motor_SCLLibHelper[MAX_MOTOR_NUM];
	QMap<int, int> motorPortMap;					//用来关联电机编号和串口号

	QMap<int, bool>IsMotorPortOpenMap;				//电机对应的串口是否被打开

	bool OpenMotorPort(int motorindex, int port_num);
	bool SetMotorMove(int motorindex, int nDistance, double* dVelocity, double* dAccel, double* dDecel);
	bool SetMotorStopMove(int motorindex);
	//关闭电机的串口
	bool CloseMotorPort(int motorindex);
	bool WriteOutput(int ynum, int motorindex, bool isHigh);


	//电机状态相关函数
	bool IsMotorEnable(int motorindex);
	bool IsMoving(int motorindex);
	bool IsStopping(int motorindex);
	bool IsInAlarmCWLimit(int motorindex);
	bool IsInAlarmCCWLimit(int motorindex);
	bool IsInPosition(int motorindex);

	int ReadInput(int motorindex);


};
