#include "MotorManager.h"

MotorManager::MotorManager(QObject *parent)
	: QObject(parent)
{
	for (int i = 0; i < MAX_MOTOR_NUM; i++)
	{
		p_Motor_SCLLibHelper[i] = new SCLLibHelper();
		IsMotorPortOpenMap.insert(i, false);
	}
}

MotorManager::~MotorManager()
{
	for (int i = 0; i < MAX_MOTOR_NUM; i++)
	{
		delete p_Motor_SCLLibHelper[i];
	}
}

//打开电机的串口
bool MotorManager::OpenMotorPort(int motorindex, int port_num)
{
	if (motorindex >= MAX_MOTOR_NUM)
	{
		return false;
	}
	else
	{
		if (p_Motor_SCLLibHelper[motorindex]->IsOpen())
		{
			p_Motor_SCLLibHelper[motorindex]->Close();
		}
		else
		{
			p_Motor_SCLLibHelper[motorindex]->Open(port_num, 9600);	//端口号波特率
		}

		p_Motor_SCLLibHelper[motorindex]->SetCommParam(0, false);
		p_Motor_SCLLibHelper[motorindex]->WriteMotorEnable(0);
	}
	return true;
}



//关闭电机的串口
bool MotorManager::CloseMotorPort(int motorindex)
{
	bool ret = false;
	if (motorindex >= MAX_MOTOR_NUM)
	{
		return false;
	}
	else
	{
		if (p_Motor_SCLLibHelper[motorindex]->IsOpen())
		{
			ret = p_Motor_SCLLibHelper[motorindex]->Close();
		}
	}
	return ret;
}


//设置电机运动
bool MotorManager::SetMotorMove(int motorindex, int nDistance, double* dVelocity, double* dAccel, double* dDecel)
{
	bool ret = false;
	if (motorindex >= MAX_MOTOR_NUM)
	{
		return false;
	}
	else
	{
		ret = p_Motor_SCLLibHelper[motorindex]->RelMove(0, nDistance, dVelocity, dAccel, dDecel);
	}
	return ret;
}


//设置电机停止
bool MotorManager::SetMotorStopMove(int motorindex)
{
	bool ret = false;
	if (motorindex >= MAX_MOTOR_NUM)
	{
		return false;
	}
	else
	{	
//		if()
		{
			ret = p_Motor_SCLLibHelper[motorindex]->WriteStopMove(0, 'D');
		}
	}
	return ret;
}


int MotorManager::ReadInput(int motorindex)
{
	int nInputStatus = 0;
	p_Motor_SCLLibHelper[motorindex]->ReadInputStatus(0, &nInputStatus);
	return nInputStatus;


//		ReadInputStatus(BYTE nNodeID, int* nInputStatus, BOOL bWithOptionalX = FALSE);

}


bool MotorManager::WriteOutput(int ynum, int motorindex, bool isHigh)
{
	bool ret;
	if (true == isHigh)
	{
		ret = p_Motor_SCLLibHelper[motorindex]->WriteImmediateHighOutput(0, ynum);
	}
	else
	{
		ret = p_Motor_SCLLibHelper[motorindex]->WriteImmediateLowOutput(0, ynum);
	}
	return ret;
}


//电机状态相关函数
bool MotorManager::IsMotorEnable(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsMotorEnabled(0);
}

bool MotorManager::IsMoving(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsMoving(0);
}

bool MotorManager::IsStopping(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsStopping(0);
}

bool MotorManager::IsInAlarmCWLimit(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsInAlarmCWLimit(0);
}

bool MotorManager::IsInAlarmCCWLimit(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsInAlarmCCWLimit(0);
}

bool MotorManager::IsInPosition(int motorindex)
{
	return p_Motor_SCLLibHelper[motorindex]->IsInPosition(0);
}








