#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QtWidgets/QMainWindow>
#include "ui_motorTest1.h"
#include "qpushbutton.h"
#include "qcheckbox.h"
#include "qdebug.h"
#include "qstring.h"
#include "qcombobox.h"
#include "qspinbox.h"
#include "qserialport.h"
#include "qmap.h"
#include "qserialportinfo.h"
#include "qlist.h"
#include "qstringlist.h"
#include "qmessagebox.h"
#include "qlabel.h"
#include "SCLLibHelper.h"
#include "QTimer"

#define   uint8  unsigned char 
//#define		unsigned char BYTE

#define		READ_FORCE_VAL_TIMEOUT			(2)



class motorTest1 : public QMainWindow
{
	Q_OBJECT

public:
	motorTest1(QWidget *parent = Q_NULLPTR);

	private slots:
	void OnbtnOpenSerialPort();			//打开串口
	void OnbtnStartMotor1();			//启动电机1
	void OnbtnStartMotor2();			//启动电机2
	void OncboxIsLink(int);				//联动设置
	void OnSysTimerOut();				//
	void OnSysTimer2Out();

	void OnbtnSetFilter();				//设置滤波器
	void OnbtnClearForce();				//清零力传感器读数
	void OnbtnStartReadForce();			//启动停止力传感器读数

	void OnbtnGoZeroMotor1();			//电机1回零
	void OnbtnGoZeroMotor2();			//电机2回零

private:

	QSerialPort *pMotor1_SerialPort;		//电机1的串口	
	QSerialPort *pMotor2_SerialPort;		//电机2的串口
	QSerialPort *pForce_SerialPort;		//电机2的串口

	SCLLibHelper *p_Motor1_SCLLibHelper;
	SCLLibHelper *p_Motor2_SCLLibHelper;
	SCLLibHelper *p_Force_SCLLibHelper;

	QTimer *Systimer;				//系统定时器
	QTimer *Systimer2;				//系统定时器2

	int nBaudRate;							//系统串口的波特率

	BYTE  nMotor1_COMPort;					//电机1的串口编号
	BYTE  nMotor2_COMPort;					//电机2的串口编号

	bool	IsSerilPortOpen;				//串口是否被打开
	bool    IsLinkMove;						//两个电机是否需要联动
	bool	IsSetFilter;					//设置滤波器标志位
	bool	IsClearForce;					//清零力传感器
	bool    IsStartGetForceValue;			//启动停止力传感器读数
	bool    IsReadForceVal;					//是否读取力传感器的值

	//读取到的返回值
	int		Gross_Weight;					//毛重
	int     Net_weight;						//净重 
	int		Tare;							//皮重
	int     Max_Weight;						//最大称重量

	int     Read_Force_Count;				//读取力传感器计数器

	int		nMotor1ImmediatePosition;		//电机1的位置
	int		nMotor2ImmediatePosition;		//电机2的位置



	void ParamInit();					//系统参数初始化
	void setSlot();						//设置槽函数

	void TraverseSerialPort();			//遍历串口
	void SetFilter();					//设置滤波器





	Ui::motorTest1Class ui;
};
