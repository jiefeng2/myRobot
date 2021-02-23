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
	void OnbtnOpenSerialPort();			//�򿪴���
	void OnbtnStartMotor1();			//�������1
	void OnbtnStartMotor2();			//�������2
	void OncboxIsLink(int);				//��������
	void OnSysTimerOut();				//
	void OnSysTimer2Out();

	void OnbtnSetFilter();				//�����˲���
	void OnbtnClearForce();				//����������������
	void OnbtnStartReadForce();			//����ֹͣ������������

	void OnbtnGoZeroMotor1();			//���1����
	void OnbtnGoZeroMotor2();			//���2����

private:

	QSerialPort *pMotor1_SerialPort;		//���1�Ĵ���	
	QSerialPort *pMotor2_SerialPort;		//���2�Ĵ���
	QSerialPort *pForce_SerialPort;		//���2�Ĵ���

	SCLLibHelper *p_Motor1_SCLLibHelper;
	SCLLibHelper *p_Motor2_SCLLibHelper;
	SCLLibHelper *p_Force_SCLLibHelper;

	QTimer *Systimer;				//ϵͳ��ʱ��
	QTimer *Systimer2;				//ϵͳ��ʱ��2

	int nBaudRate;							//ϵͳ���ڵĲ�����

	BYTE  nMotor1_COMPort;					//���1�Ĵ��ڱ��
	BYTE  nMotor2_COMPort;					//���2�Ĵ��ڱ��

	bool	IsSerilPortOpen;				//�����Ƿ񱻴�
	bool    IsLinkMove;						//��������Ƿ���Ҫ����
	bool	IsSetFilter;					//�����˲�����־λ
	bool	IsClearForce;					//������������
	bool    IsStartGetForceValue;			//����ֹͣ������������
	bool    IsReadForceVal;					//�Ƿ��ȡ����������ֵ

	//��ȡ���ķ���ֵ
	int		Gross_Weight;					//ë��
	int     Net_weight;						//���� 
	int		Tare;							//Ƥ��
	int     Max_Weight;						//��������

	int     Read_Force_Count;				//��ȡ��������������

	int		nMotor1ImmediatePosition;		//���1��λ��
	int		nMotor2ImmediatePosition;		//���2��λ��



	void ParamInit();					//ϵͳ������ʼ��
	void setSlot();						//���òۺ���

	void TraverseSerialPort();			//��������
	void SetFilter();					//�����˲���





	Ui::motorTest1Class ui;
};
