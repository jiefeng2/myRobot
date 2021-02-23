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

	//CRCУ��
	quint16 CRC16(char *puchMsg, int usDataLen);

	//�����˲���
	void SetFilter(int filterType, int filterStrength);

	void SetSensorSetFilter();
	void SetSensorSetZero();
	void GetSensorValue();

	QSerialPort *pForce_SerialPort;

	bool OpenForceSensorPort(QString portname);			//�����������˿�
	bool CloseForceSensorPort();			//�رմ���������

	int n_ForceSensorFilterType;
	int n_ForceSensorFilterStrength;

	//��ȡ���ķ���ֵ
	int		Gross_Weight;					//ë��
	int     Net_weight;						//���� 
	int		Tare;							//Ƥ��
	int     Max_Weight;						//��������

private:
	QTimer *forceSensorReadTmr;
	int n_CmdType;

	bool IsSetFilter;					//�����˲�����־λ
	bool IsClearForce;					//������������
	bool IsStartGetForceValue;			//����ֹͣ��������������
	bool IsReadForceVal;


	private slots:
	void OnforceSensorReadTmr();


};
