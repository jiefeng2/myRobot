#pragma once

#include <QObject>
#include <qtimer.h>
#include "common.h"
#include "qserialport.h"
#include "qserialportinfo.h"



class ForceSensorModule : public QObject
{
	Q_OBJECT

public:
	ForceSensorModule(QObject *parent);
	~ForceSensorModule();

	//CRC校验
	quint16 CRC16(char *puchMsg, int usDataLen);

	//设置滤波器
	void SetFilter(int filterType, int filterStrength);

	void SetSensorSetFilter();
	void SetSensorSetZero();
	void GetSensorValue();

	QSerialPort *pForce_SerialPort;

	bool OpenForceSensorPort(QString portname);			//打开力传感器端口
	bool CloseForceSensorPort();			//关闭传感器串口

	int n_ForceSensorFilterType;
	int n_ForceSensorFilterStrength;

	//读取到的返回值
	int		Gross_Weight;					//毛重
	int     Net_weight;						//净重 
	int		Tare;							//皮重
	int     Max_Weight;						//最大称重量

private:
	QTimer *forceSensorReadTmr;
	int n_CmdType;

	bool IsSetFilter;					//设置滤波器标志位
	bool IsClearForce;					//清零力传感器
	bool IsStartGetForceValue;			//启动停止力传感器读数、
	bool IsReadForceVal;


	private slots:
	void OnforceSensorReadTmr();


};
