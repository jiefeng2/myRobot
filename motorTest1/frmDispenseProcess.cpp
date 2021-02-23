#include "frmDispenseProcess.h"
#include "common.h"
#include "QMessageBox"
#include <QDebug>
#include <QThread>
#include "GlobalParam.h"

frmDispenseProcess::frmDispenseProcess(myThread *pmyThread, ForceSensorModule *pForceSensorModule, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("��ҩ����4 ---��ҩ����"));
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	thermometer = new CThermometer(this);
	thermometer->setMaxValue(30);
	thermometer->setMinValue(0);
	thermometer->setCenterWidth(50);
	thermometer->setPrecision(CThermometer::E_ONE); //���þ���
	thermometer->setScaleColor(QColor(0, 0, 0));

	thermometer->setGeometry(20, 100, 600, 600);


	//this->showMaximized();

	p_ForceSensorModule = pForceSensorModule;

	MyT = pmyThread;
	connect(ui.btnGoNext, SIGNAL(clicked()), this, SLOT(OnbtnGoNext()));
	connect(ui.btnprocess, SIGNAL(clicked()), this, SLOT(OnbtnProcess()));

	connect(MyT->p_MOTOFun, SIGNAL(ReadWeight0()), this, SLOT(ReadForceSensor0()));
	connect(MyT->p_MOTOFun, SIGNAL(SendDisMOTO2(int)), this, SLOT(UiDisMOTO2(int)));
	connect(MyT->p_MOTOFun, SIGNAL(ReadWeight()), this, SLOT(ReadForceSensor()));
	

//	connect(this, SIGNAL(Uiset()), this, SLOT(Uisetfun()));

}

frmDispenseProcess::~frmDispenseProcess()
{
}


void frmDispenseProcess::UiDisMOTO2(int value)
{
	sum += value;
	thermometer->setValueWithAnimation(sum*2/7 - 5);
}

void frmDispenseProcess::OnbtnGoNext()
{

	emit  this->btnClickedSignal(FRM_DISPENSE_PROCESS, GO_NEXT_BTN_TYPE);
	if (MyT->isRunning() == false)
	{
		return;
	}
	MyT->quit();
	MyT->wait();
}


//������
void frmDispenseProcess::ReadForceSensor0()
{
	
	weight0 = p_ForceSensorModule->Gross_Weight;

}


void frmDispenseProcess::ReadForceSensor()
{

	QString  Gross_WeightStr = QString("Һ��������%1 g").arg((p_ForceSensorModule->Gross_Weight - weight0)*4.38 / 226);
	ui.lblForceSensorVal->setText(Gross_WeightStr);
}

void frmDispenseProcess::OnbtnProcess()
{


	MyT->start();

	/*

	*/

	int a = GlobalParam::N;
}

void frmDispenseProcess::dealSignal()
{
	int a = 0;
}


void frmDispenseProcess::Uisetfun()
{
	int i = 0;
	QString str = QString("��%1").arg(i);

	//ui.label->setText("1");
}


void frmDispenseProcess::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, tr("��ʾ"), tr("��ȷ���˳������?"), tr("ȷ��"), tr("ȡ��"), 0, 1))
	{
		//�ر����
	case 0:
		event->accept();
		qApp->quit();
		break;
	case 1:
	default:
		event->ignore();
		break;
	}
}

