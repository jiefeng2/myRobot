#pragma once

#include <QObject>
#include <qstring.h>
#include "User.h"

class App : public QObject
{
	Q_OBJECT

public:
	App(QObject *parent);
	~App();

	//����
	static QString  AppName;
	static QString  AppPath;

	//5������Ķ˿ڱ��
	static int  Motor1PortNum;
	static int  Motor2PortNum;
	static int  Motor3PortNum;
	static int  Motor4PortNum;
	static int  Motor5PortNum;
	static QString ForceSensorPortName;		//�������Ķ˿�����

	//��������Ĳ���
	static float  Motor1SpeedVal;
	static float  Motor1ACVal;
	static float  Motor1ReRate;

	static float  Motor2SpeedVal;
	static float  Motor2ACVal;
	static float  Motor2ReRate;

	static float  Motor3SpeedVal;
	static float  Motor3ACVal;
	static float  Motor3ReRate;

	static float  Motor4SpeedVal;
	static float  Motor4ACVal;
	static float  Motor4ReRate;

	static float  Motor5SpeedVal;
	static float  Motor5ACVal;
	static float  Motor5ReRate;

	static User g_current_user;				//��ǰ�û�����
	static User g_system_user;				//����Ա

	static void ReadConfig();           //��ȡ�����ļ�,��main�����ʼ���س�������
	static void WriteConfig();          //д�������ļ�,�ڸ��������ļ�����ر�ʱ����
};



/*
class B 
{
	int a;
	int b;
};

class A
{
	static B testB;
};
*/

