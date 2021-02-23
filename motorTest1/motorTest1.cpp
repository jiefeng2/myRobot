#include "motorTest1.h"
#include <QLibrary>
#include <QDebug>

//��ѯ����ֵ
char GetValueTable[8] = {0x01, 0x03, 0x00, 0x50, 0x00, 0x08, 0x44, 0x1D};

//�����˲���
char SetFilterTable[8] = {0x01, 0x03, 0x00, 0x22, 0x00, 0x02, 0xF4, 0x7A };

//�������ֵ
char SetZeroValueTable[13] = {0x01, 0x10, 0x00, 0x54, 0x00, 0x02, 0x04, 0x7F, 0xFF, 0xFF, 0xFF, 0xDF, 0x34};

/* CRC ��λ�ֽ�ֵ�� */
const quint8 auchCRCHi[] = {
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

/* CRC��λ�ֽ�ֵ��*/
const quint8 auchCRCLo[] = {
	0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
	0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
	0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
	0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
	0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
	0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
	0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
	0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
	0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
	0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
	0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
	0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
	0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
	0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
	0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
	0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
	0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
	0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
	0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
	0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
	0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
	0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
	0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
	0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
	0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
	0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

quint16 CRC16(char *puchMsg, int usDataLen)
{
	quint8 uchCRCHi = 0xFF;     /* ��CRC�ֽڳ�ʼ�� */
	quint8 uchCRCLo = 0xFF;     /* ��CRC �ֽڳ�ʼ�� */
	quint8 uIndex;                   /* CRCѭ���е����� */

	while (usDataLen--)                 /* ������Ϣ������ */
	{
		uIndex = uchCRCHi ^ *puchMsg++; /* ����CRC */
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
		uchCRCLo = auchCRCLo[uIndex];
	}
	return (uchCRCHi << 8 | uchCRCLo);
}



motorTest1::motorTest1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	int a = 50000;
	int b = -147;

	ParamInit();

	setSlot();
	TraverseSerialPort();

}


//ϵͳ������ʼ��
void motorTest1::ParamInit()					
{
	IsSerilPortOpen = false;
	IsLinkMove = false;

//	ui.lblProtState->setStyleSheet("background-color: rgb(128,128,128)");
	pMotor1_SerialPort = new QSerialPort();		//���1�Ĵ���	
	pMotor2_SerialPort = new QSerialPort();		//���2�Ĵ���
	pForce_SerialPort = new QSerialPort();

	p_Motor1_SCLLibHelper = new SCLLibHelper();
	p_Motor2_SCLLibHelper = new SCLLibHelper();
	Systimer = new QTimer();
	Systimer2 = new QTimer();

	nMotor1_COMPort = 0;
	nMotor2_COMPort = 0;

	nMotor1ImmediatePosition = 0;		//���1��λ��
	nMotor2ImmediatePosition = 0;		//���2��λ��

	nBaudRate = 9600;

	IsSetFilter = false;					//�����˲�����־λ
	IsClearForce = false;					//������������
	IsStartGetForceValue = false;			//����ֹͣ��������������
	IsReadForceVal = false;

	Gross_Weight = 0;					//ë��
	Net_weight = 0;						//���� 
	Tare = 0;							//Ƥ��
	Max_Weight = 0;						//��������

	Read_Force_Count = 0;
}


//���òۺ���
void motorTest1::setSlot()						
{
	connect(ui.btnStartMotor1, SIGNAL(clicked()), this, SLOT(OnbtnStartMotor1()));
	connect(ui.btnStartMotor2, SIGNAL(clicked()), this, SLOT(OnbtnStartMotor2()));
	connect(ui.btnOpenSerialPort, SIGNAL(clicked()), this, SLOT(OnbtnOpenSerialPort()));
	connect(ui.cboxIsLink, SIGNAL(stateChanged(int)), this, SLOT(OncboxIsLink(int)));
	connect(ui.btnSetFilter, SIGNAL(clicked()), this, SLOT(OnbtnSetFilter()));
	connect(ui.btnClearForce, SIGNAL(clicked()), this, SLOT(OnbtnClearForce()));
	connect(ui.btnStartReadForce, SIGNAL(clicked()), this, SLOT(OnbtnStartReadForce()));

	connect(ui.btnGoZeroMotor1, SIGNAL(clicked()), this, SLOT(OnbtnGoZeroMotor1()));
	connect(ui.btnGoZeroMotor2, SIGNAL(clicked()), this, SLOT(OnbtnGoZeroMotor2()));

	connect(this->Systimer, SIGNAL(timeout()), this, SLOT(OnSysTimerOut()));
	Systimer->setInterval(100);
	Systimer->start();

	connect(this->Systimer2, SIGNAL(timeout()), this, SLOT(OnSysTimer2Out()));
	Systimer2->setInterval(10);
	Systimer2->start();
}

//��������
void motorTest1::TraverseSerialPort()			
{
	int i = 0;
	QList <QSerialPortInfo> list_info = QSerialPortInfo::availablePorts();
	QStringList portlist;

	if (list_info.isEmpty())
	{
		qDebug() << "no serial port";
	}
	else
	{
		portlist.clear();
		foreach(const QSerialPortInfo &info, list_info)
		{
			portlist << info.portName();
			qDebug() << info.portName() << info.serialNumber();
		}
		ui.comBoxMotor1->addItems(portlist);
		ui.comBoxMotor2->addItems(portlist);
		ui.comBoxForce->addItems(portlist);
	}
}


//�򿪴���
void motorTest1::OnbtnOpenSerialPort()			
{
	qDebug() << "OnbtnOpenSerialPort";
	QString  portStr;
	bool OpenPort1ret, OpenPort2ret, OpenPort3ret;
	bool ret;


	//�����ǰ���ڴ��ڹر�״̬
	if (false == IsSerilPortOpen)
	{
		//����������ڱ����ȣ���Ҫ����
		if ((ui.comBoxMotor1->count() == 0) || (ui.comBoxMotor2->count() == 0)|| (ui.comBoxForce->count() == 0))
		{
			QMessageBox::about(NULL, "����", "û��ѡ�еĴ���");
		}
		else
		{
			if ((ui.comBoxMotor1->currentText() == ui.comBoxMotor2->currentText()) || (ui.comBoxMotor1->currentText() == ui.comBoxForce->currentText()) || (ui.comBoxForce->currentText() == ui.comBoxMotor2->currentText()))
			{
				QMessageBox::about(NULL, "����", "�������������������ʹ��ͬһ������");
			}
			else
			{
				portStr = ui.comBoxMotor1->currentText();
				portStr.remove("COM", Qt::CaseInsensitive);
				nMotor1_COMPort = portStr.toInt();
				qDebug() << "portStr= " << portStr<<"nMotor1_COMPort"<< nMotor1_COMPort;

				portStr = ui.comBoxMotor2->currentText();
				portStr.remove("COM", Qt::CaseInsensitive);
				nMotor2_COMPort = portStr.toInt();

				//�򿪴���
				OpenPort1ret = p_Motor1_SCLLibHelper->Open(nMotor1_COMPort, nBaudRate);
				OpenPort2ret = p_Motor2_SCLLibHelper->Open(nMotor2_COMPort, nBaudRate);
				pForce_SerialPort->setPortName(ui.comBoxForce->currentText());
				OpenPort3ret = pForce_SerialPort->open(QIODevice::ReadWrite);


				//����˿ڱ�ռ��
				if ((OpenPort1ret == false) || (OpenPort2ret == false) ||(OpenPort3ret == false))
				{
					if (p_Motor1_SCLLibHelper->IsOpen())
					{
						p_Motor1_SCLLibHelper->Close();
					}

					if (p_Motor2_SCLLibHelper->IsOpen())
					{
						p_Motor2_SCLLibHelper->Close();
					}

					if (pForce_SerialPort->isOpen())
					{
						p_Motor2_SCLLibHelper->Close();
					}
				}
				else
				{
					ret = p_Motor1_SCLLibHelper->SetCommParam(0, FALSE);
					ret = p_Motor1_SCLLibHelper->WriteMotorEnable(0);

					ret = p_Motor2_SCLLibHelper->SetCommParam(0, FALSE);
					ret = p_Motor2_SCLLibHelper->WriteMotorEnable(0);

					pForce_SerialPort->setBaudRate(QSerialPort::Baud9600);
					pForce_SerialPort->setDataBits(QSerialPort::Data8);
					pForce_SerialPort->setFlowControl(QSerialPort::NoFlowControl);
					pForce_SerialPort->setParity(QSerialPort::NoParity);
					pForce_SerialPort->setStopBits(QSerialPort::TwoStop);

					qDebug() << p_Motor1_SCLLibHelper->IsOpen() << p_Motor2_SCLLibHelper->IsOpen();

					ui.btnOpenSerialPort->setText(tr("�رմ���"));
					ui.lblProtState->setStyleSheet("background-color: rgb(0,255,0)");
					IsSerilPortOpen = true;
				}
			}
		}
	}
	//�����ǰ���ڴ��ڴ�״̬
	else
	{
		if (p_Motor1_SCLLibHelper->IsOpen())
		{
			p_Motor1_SCLLibHelper->Close();
		}

		if (p_Motor2_SCLLibHelper->IsOpen())
		{
			p_Motor2_SCLLibHelper->Close();
		}

		if (pForce_SerialPort->isOpen())
		{
			pForce_SerialPort->close();
		}
		ui.btnOpenSerialPort->setText(tr("�򿪴���"));
		ui.lblProtState->setStyleSheet("background-color: rgb(128,128,128)");
		IsSerilPortOpen = false;

		qDebug() << p_Motor1_SCLLibHelper->IsOpen() << p_Motor2_SCLLibHelper->IsOpen();
	}
}


//�������1
void motorTest1::OnbtnStartMotor1()			
{
	bool ret;
	int nDistance1 = 20000;
	double dVelocity1= 10;
	double dAcc1 = 100;
	double dDec1 = 100;

	int nDistance2 = 20000;
	double dVelocity2 = 10;
	double dAcc2= 100;
	double dDec2 = 100;


	if (IsSerilPortOpen == false)
	{
		QMessageBox::about(NULL, "����", "���ȴ򿪴���");
	}
	else
	{


		nDistance1 = ui.spboxMotor1Position->text().toInt();
		nDistance1 = nDistance1 * 1000;
		dVelocity1 = ui.spboxMotor1Vel->text().toDouble();
//		dVelocity1 = dVelocity1 * 10;

		nDistance2 = ui.spboxMotor2Position->text().toInt();
		nDistance2 = nDistance2 * 1000;
		dVelocity2 = ui.spboxMotor2Vel->text().toDouble();
//		dVelocity2 = dVelocity2 * 10;

		qDebug() << "nDistance1 =" << nDistance1 << "dVelocity1 =" << dVelocity1;
		qDebug() << "nDistance2 =" << nDistance2 << "dVelocity2 =" << dVelocity2;

		//���������
		if (IsLinkMove)
		{
			ret = p_Motor1_SCLLibHelper->RelMove(0, nDistance1, &dVelocity1, &dAcc1, &dDec1);
			ret = p_Motor2_SCLLibHelper->RelMove(0, nDistance2, &dVelocity2, &dAcc2, &dDec2);
		}
		//��������
		else
		{
			ret = p_Motor1_SCLLibHelper->RelMove(0, nDistance1, &dVelocity1, &dAcc1, &dDec1);
		}
	}
	qDebug() << "OnbtnStartMotor1";

}


//�������2
void motorTest1::OnbtnStartMotor2()			
{
	bool ret;
	int nDistance2 = 20000;
	double dVelocity2 = 10;
	double dAcc2 = 100;
	double dDec2 = 100;



	if (IsSerilPortOpen == false)
	{
		QMessageBox::about(NULL, "����", "���ȴ򿪴���");
	}
	else
	{
		//������������������
		if (!IsLinkMove)
		{
			ret = p_Motor2_SCLLibHelper->RelMove(0, nDistance2, &dVelocity2, &dAcc2, &dDec2);
		}
	}
	qDebug() << "OnbtnStartMotor2";
}


//��������
void motorTest1::OncboxIsLink(int)				
{
	IsLinkMove = ui.cboxIsLink->isChecked();

	qDebug() << "OncboxIsLink"<<"IsLinkMove="<< IsLinkMove;
}



void motorTest1::OnSysTimerOut(void)
{
//	qDebug() << "OnSysTimerOut";
	QByteArray serialrecvdata;              //���ڽ��ջ�����
	int k = 0;

	Read_Force_Count++;
	if (Read_Force_Count == READ_FORCE_VAL_TIMEOUT)
	{
		Read_Force_Count = 0;
		if (IsReadForceVal == true)
		{
			IsStartGetForceValue = true;
		}
	}

//1. ���մ��ڷ��͹���������
	serialrecvdata = pForce_SerialPort->readAll();
	if (serialrecvdata.size() != 0)
	{
		for (k = 0; k < serialrecvdata.size(); k++)
		{
			qDebug() << serialrecvdata[k];
		}
		if ((int)serialrecvdata[2]==0x10)
		{
			Gross_Weight = (int)((uint8)serialrecvdata[3]<<24) + (int)((uint8)serialrecvdata[4]<<16) + (int)((uint8)serialrecvdata[5]<<8) + (uint8)serialrecvdata[6];					//ë��
			Net_weight = (int)((uint8)serialrecvdata[7]<<24) + (int)((uint8)serialrecvdata[8]<<16) + (int)((uint8)serialrecvdata[9]<<8) + (uint8)serialrecvdata[10];						//���� 
			Tare = (int)((uint8)serialrecvdata[11]<<24) + (int)((uint8)serialrecvdata[12]<<16) + (int)((uint8)serialrecvdata[13]<<8) + (uint8)serialrecvdata[14];							//Ƥ��
			Max_Weight = (int)((uint8)serialrecvdata[15]<<24) + (int)((uint8)serialrecvdata[16]<<16) + (int)((uint8)serialrecvdata[17]<<8) + (uint8)serialrecvdata[18];					//��������

			QString  Gross_WeightStr = QString("%1").arg(Gross_Weight);
			QString  TareStr = QString("%1").arg(Tare);
			QString  Net_weightStr = QString("%1").arg(Net_weight);

			ui.lblForceVal->setText(Net_weightStr);
//			ui.lblForceVal2->setText(TareStr);
//			ui.lblForceVal3->setText(Net_weightStr);
		}

		if ((int)serialrecvdata[2]==0x16)
		{

		}
	}


//2. ͨ�����ڷ�������
	if (true == IsSetFilter)
	{
		IsSetFilter = false;
		SetFilter();
	}
	else if (true == IsClearForce)
	{
		IsClearForce = false;
		pForce_SerialPort->write(SetZeroValueTable, 13);
	}
	else if (true == IsStartGetForceValue)
	{
		IsStartGetForceValue = false;
		pForce_SerialPort->write(GetValueTable, 8);
	}
}


//�����˲���
void motorTest1::OnbtnSetFilter()
{
	qDebug() << "OnbtnSetFilter";
	IsSetFilter = true;

}
//����������������
void motorTest1::OnbtnClearForce()
{
	qDebug() << "OnbtnClearForce";
	IsClearForce = true;
}

//����ֹͣ������������
void motorTest1::OnbtnStartReadForce()
{
	qDebug() << "OnbtnStartReadForce";
	if (IsReadForceVal == false)
	{
		ui.btnStartReadForce->setText(tr("ֹͣ����"));
		IsReadForceVal = true;
		IsStartGetForceValue = true;
		ui.lblReadForceState->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else if (IsReadForceVal == true)
	{
		ui.btnStartReadForce->setText(tr("��ʼ����"));
		IsReadForceVal = false;
		ui.lblReadForceState->setStyleSheet("background-color: rgb(128,128,128)");
	}
}


//�����˲���
void motorTest1::SetFilter()					
{
	quint16 CrcCheck = 0;
	uint8 filterType = 0;
	uint8 filterStrength = 0;
	char SendTable[13] = { 0x01, 0x10, 0x00, 0x22, 0x00, 0x02, 0x04, 0x00, 0xFF, 0x00, 0xFF, 0xDF, 0x34 };
	filterType = ui.comBoxFilterType->currentIndex();
	filterStrength = ui.spboxFilterStrength->text().toInt();

	SendTable[8] = (char)filterType;
	SendTable[10] = (char)filterStrength;
	CrcCheck = CRC16(SendTable, 11);
	SendTable[11] = CrcCheck / 256;
	SendTable[12] = CrcCheck % 256;

	pForce_SerialPort->write(SendTable, 13);
}


//���1����
void motorTest1::OnbtnGoZeroMotor1()
{
	bool ret;
	int nDistance = 2000000;
	double dVelocity = 10;
	double dAcc = 100;
	double dDec = 100;


	if (p_Motor1_SCLLibHelper->IsOpen() == false)
	{
		QMessageBox::about(NULL, "����", "���ȴ򿪴���");
	}
	else
	{
		ret = p_Motor1_SCLLibHelper->RelMove(0, nDistance, &dVelocity, &dAcc, &dDec);
	}
}

//���2����
void motorTest1::OnbtnGoZeroMotor2()
{
	bool ret;
	int nDistance = 2000000;
	double dVelocity = 10;
	double dAcc = 100;
	double dDec = 100;


	if (p_Motor2_SCLLibHelper->IsOpen() == false)
	{
		QMessageBox::about(NULL, "����", "���ȴ򿪴���");
	}
	else
	{
		ret = p_Motor2_SCLLibHelper->RelMove(0, nDistance, &dVelocity, &dAcc, &dDec);
	}

}


void motorTest1::OnSysTimer2Out()
{
	bool ret;
	int nDistance1 = -2000;
	int nDistance2 = -2000;
	double dVelocity = 10;
	double dAcc = 100;
	double dDec = 100;

	//�ж��Ƿ�������λ
	//DI+���������֧
	if (p_Motor1_SCLLibHelper->IsInAlarmCWLimit(0) == true)
	{
		nDistance1 = -2000;
		p_Motor1_SCLLibHelper->ReadImmediatePosition(0, &nMotor1ImmediatePosition);
		ret = p_Motor1_SCLLibHelper->RelMove(0, nDistance1, &dVelocity, &dAcc, &dDec);

	}
	else if (p_Motor1_SCLLibHelper->IsInAlarmCCWLimit(0) == true)
	{
		nDistance1 = 2000;
		p_Motor1_SCLLibHelper->ReadImmediatePosition(0, &nMotor1ImmediatePosition);
		ret = p_Motor1_SCLLibHelper->RelMove(0, nDistance1, &dVelocity, &dAcc, &dDec);

	}

	//DI+���������֧
	if (p_Motor2_SCLLibHelper->IsInAlarmCWLimit(0) == true)
	{
		nDistance2 = -2000;
		p_Motor2_SCLLibHelper->ReadImmediatePosition(0, &nMotor2ImmediatePosition);
		ret = p_Motor2_SCLLibHelper->RelMove(0, nDistance2, &dVelocity, &dAcc, &dDec);

	}
	else if (p_Motor2_SCLLibHelper->IsInAlarmCCWLimit(0) == true)
	{
		nDistance2 = 2000;
		p_Motor2_SCLLibHelper->ReadImmediatePosition(0, &nMotor2ImmediatePosition);
		ret = p_Motor2_SCLLibHelper->RelMove(0, nDistance2, &dVelocity, &dAcc, &dDec);

	}


}













