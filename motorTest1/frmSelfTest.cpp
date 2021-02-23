#include "frmSelfTest.h"
#include "QMessageBox"
#include "common.h"
#include "GlobalParam.h"


frmSelfTest::frmSelfTest(MOTOFun *pMOTOFun, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("��ҩ����2 ---�Լ�"));
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	connect(ui.btnGoNext, SIGNAL(clicked()), this, SLOT(OnbtnGoNext()));
	connect(ui.btnGoBack, SIGNAL(clicked()), this, SLOT(OnbtnGoBack()));
	connect(ui.btnStartSelfTest, SIGNAL(clicked()), this, SLOT(OnbtnStartSelfTest()));
	//������
	connect(ui.btnOpenPort, SIGNAL(clicked()), this, SLOT(OnbtnOpenPort()));
//	connect(ui.btnGoForward, SIGNAL(clicked()), this, SLOT(OnbtnGoForward()));
//	connect(ui.btnGoBackward, SIGNAL(clicked()), this, SLOT(OnbtnGoBackward()));
	
	p_MOTOFun = pMOTOFun;
}

frmSelfTest::~frmSelfTest()
{
}


void frmSelfTest::OnbtnGoNext()
{
	emit  this->btnClickedSignal(FRM_SELF_TEST, GO_NEXT_BTN_TYPE);
}

void frmSelfTest::OnbtnGoBack()
{
	emit  this->btnClickedSignal(FRM_SELF_TEST, GO_BACK_BTN_TYPE);
}


void frmSelfTest::OnbtnOpenPort()
{
	bool ret1 = false;
	bool ret2 = false;
	bool ret3 = false;
	bool ret4 = false;
	bool ret5 = false;
	bool ret6 = false;

	//֮ǰ�Ĺرյĵ�
	if (false == IsMotorOpen)
	{
		//ret1 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_1_INDEX, 9);
		//ret2 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_2_INDEX, 6);
		//ret3 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_3_INDEX, 10);
		//ret4 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_4_INDEX, 8);
		//ret5 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_5_INDEX, 7);
		//ret6 = p_MOTOFun->p_ForceSensorModule->OpenForceSensorPort("COM4");
		//���ڴ򿪳ɹ�
		
		//ͨ������򿪴�����
  /*      ret1 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_1_INDEX, App::Motor1PortNum);
		ret2 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_2_INDEX, App::Motor2PortNum);
		ret3 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_3_INDEX, App::Motor3PortNum);
		ret4 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_4_INDEX, App::Motor4PortNum);
		ret5 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_5_INDEX, App::Motor5PortNum);
		ret6 = p_MOTOFun->p_ForceSensorModule->OpenForceSensorPort(App::ForceSensorPortName);*/

		//ͨ�����ݿ�򿪴��ڵķ���
		ret1 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_1_INDEX, GlobalParam::com1);
		ret2 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_2_INDEX, GlobalParam::com2);
		ret3 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_3_INDEX, GlobalParam::com3);
		ret4 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_4_INDEX, GlobalParam::com4);
		ret5 = p_MOTOFun->p_MotorManager->OpenMotorPort(MOTOR_5_INDEX, GlobalParam::com5);
		ret6 = p_MOTOFun->p_ForceSensorModule->OpenForceSensorPort(GlobalParam::com6);


		//���ڴ򿪳ɹ�
		if (true == ret1 && true == ret2 && true == ret3 && true == ret4 && true == ret5 && true == ret6)
		{
			IsMotorOpen = true;
			ui.btnOpenPort->setText(tr("�򿪴���"));

		}

		if (ret1 == true)
		{
			ui.textEdit->append("����1ͨ�ųɹ�...");

		}
		else
		{
			QMessageBox::about(NULL, "����", "����1��ʧ��");
		}

		if (ret2 == true)
		{
			ui.textEdit->append("����2ͨ�ųɹ�...");
		}
		else
		{
			QMessageBox::about(NULL, "����", "����2��ʧ��");
		}

		if (ret3 == true)
		{
			ui.textEdit->append("����3ͨ�ųɹ�...");
		}
		else
		{
			QMessageBox::about(NULL, "����", "����3��ʧ��");
		}

		if (ret4 == true)
		{
			ui.textEdit->append("����4ͨ�ųɹ�...");
		}
		else
		{
			QMessageBox::about(NULL, "����", "����4��ʧ��");
		}

		if (ret5 == true)
		{
			ui.textEdit->append("����5ͨ�ųɹ�...");
		}
		else
		{
			QMessageBox::about(NULL, "����", "����5��ʧ��");
		}

		if (ret6 == true)
		{
			ui.textEdit->append("����6ͨ�ųɹ�...");
		}
		else
		{
			QMessageBox::about(NULL, "����", "����6��ʧ��");
		}


		ui.btnOpenPort->setText(tr("�رմ���"));

		ret1 = ret2 = ret3 = ret4 = ret5 = ret6 = false;
	}
	//֮ǰ���Ǵ򿪵�
	else if (true == IsMotorOpen)
	{
		ret1 = p_MOTOFun->p_MotorManager->CloseMotorPort(MOTOR_1_INDEX);
		ret2 = p_MOTOFun->p_MotorManager->CloseMotorPort(MOTOR_2_INDEX);
		ret3 = p_MOTOFun->p_MotorManager->CloseMotorPort(MOTOR_3_INDEX);
		ret4 = p_MOTOFun->p_MotorManager->CloseMotorPort(MOTOR_4_INDEX);
		ret5 = p_MOTOFun->p_MotorManager->CloseMotorPort(MOTOR_5_INDEX);
		ret6 = p_MOTOFun->p_ForceSensorModule->CloseForceSensorPort();


		if (true == ret1&& true == ret2 && true == ret3 && true == ret4 && true == ret5 && true == ret6)
		{
			IsMotorOpen = false;
			ui.btnOpenPort->setText(tr("�򿪴���"));

		}
		else
		{
			QMessageBox::about(NULL, "����", "���ڹر�ʧ��");
		}
	}
}




void frmSelfTest::OnbtnStartSelfTest()
{
	ui.textEdit->clear();
	ui.textEdit->append("�Լ��Ѿ���������װ����ƿ�Լ�ע����");
	p_MOTOFun->OnbtnZeroAll();
}


void frmSelfTest::closeEvent(QCloseEvent *event)
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