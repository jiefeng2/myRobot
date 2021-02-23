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

	//变量
	static QString  AppName;
	static QString  AppPath;

	//5个电机的端口编号
	static int  Motor1PortNum;
	static int  Motor2PortNum;
	static int  Motor3PortNum;
	static int  Motor4PortNum;
	static int  Motor5PortNum;
	static QString ForceSensorPortName;		//传感器的端口名称

	//各个电机的参数
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

	static User g_current_user;				//当前用户变量
	static User g_system_user;				//管理员

	static void ReadConfig();           //读取配置文件,在main函数最开始加载程序载入
	static void WriteConfig();          //写入配置文件,在更改配置文件程序关闭时调用
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

