#include "TestForm1.h"
#include "qmessagebox.h"
#include "synchapi.h"
#include "GlobalParam.h"


TestForm1::TestForm1(MotorManager *pMotorManager, ForceSensorModule *pForceSensorModule, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	p_MotorManager = pMotorManager;
	p_ForceSensorModule = pForceSensorModule;

	connect(ui.btnOpenMotor1, SIGNAL(clicked()), this, SLOT(OnbtnOpenMotor1()));
	connect(ui.btnOpenMotor2, SIGNAL(clicked()), this, SLOT(OnbtnOpenMotor2()));
	connect(ui.btnOpenMotor3, SIGNAL(clicked()), this, SLOT(OnbtnOpenMotor3()));
	connect(ui.btnOpenMotor4, SIGNAL(clicked()), this, SLOT(OnbtnOpenMotor4()));
	connect(ui.btnOpenMotor5, SIGNAL(clicked()), this, SLOT(OnbtnOpenMotor5()));
	connect(ui.btnSaveParam, SIGNAL(clicked()), this, SLOT(OnbtnSaveParam()));
	connect(ui.btnGoFrm2, SIGNAL(clicked()), this, SLOT(OnbtnGoFrm2()));
	connect(ui.btnOpenForceSensor, SIGNAL(clicked()), this, SLOT(OnbtnOpenForceSensor()));

	connect(ui.btnGoRight1, SIGNAL(clicked()), this, SLOT(OnbtnGoRight1()));
	connect(ui.btnGoRight2, SIGNAL(clicked()), this, SLOT(OnbtnGoRight2()));
	connect(ui.btnGoRight3, SIGNAL(clicked()), this, SLOT(OnbtnGoRight3()));
	connect(ui.btnGoRight4, SIGNAL(clicked()), this, SLOT(OnbtnGoRight4()));
	connect(ui.btnGoRight5, SIGNAL(clicked()), this, SLOT(OnbtnGoRight5()));

	connect(ui.btnGoLeft1, SIGNAL(clicked()), this, SLOT(OnbtnGoLeft1()));
	connect(ui.btnGoLeft2, SIGNAL(clicked()), this, SLOT(OnbtnGoLeft2()));
	connect(ui.btnGoLeft3, SIGNAL(clicked()), this, SLOT(OnbtnGoLeft3()));
	connect(ui.btnGoLeft4, SIGNAL(clicked()), this, SLOT(OnbtnGoLeft4()));
	connect(ui.btnGoLeft5, SIGNAL(clicked()), this, SLOT(OnbtnGoLeft5()));

	connect(ui.btnReadInput, SIGNAL(clicked()), this, SLOT(OnbtnReadInput()));

	connect(ui.btnReadForceSensor, SIGNAL(clicked()), this, SLOT(OnbtnReadForceSensor()));
	connect(ui.btnPullLiqiud, SIGNAL(clicked()), this, SLOT(OnbtnPullLiqiud()));
	connect(ui.btnSetOutputHigh, SIGNAL(clicked()), this, SLOT(OnbtnSetOutputHigh()));
	connect(ui.btnSetOutputLow, SIGNAL(clicked()), this, SLOT(OnbtnSetOutputLow()));

	connect(ui.btnPullLiqiud_2, SIGNAL(clicked()), this, SLOT(OnbtnPullLiqiud_2()));
	

	InitPortCmb();

}

TestForm1::~TestForm1()
{
}

//初始化端口列表
void TestForm1::InitPortCmb()
{
	SerialPortNameList = MyHelp::TraverseSerialPort();
	ui.cmbMotor1Port->addItems(SerialPortNameList);
	ui.cmbMotor2Port->addItems(SerialPortNameList);
	ui.cmbMotor3Port->addItems(SerialPortNameList);
	ui.cmbMotor4Port->addItems(SerialPortNameList);
	ui.cmbMotor5Port->addItems(SerialPortNameList);
	ui.cmbForceSensorPort->addItems(SerialPortNameList);
//	ui.cmbMotor5PortName->addItems(SerialPortNameList);

	IsMotor1Open = false;
	IsMotor2Open = false;
	IsMotor3Open = false;
	IsMotor4Open = false;
	IsMotor5Open = false;
	IsForceSensorOpen = false;
}

void TestForm1::Initspb()
{


}

void TestForm1::OpenMotorPort1(int motorindex, int portnum)
{
	;
}

void TestForm1::OnbtnOpenMotor1()
{
	bool ret = false;
	int portnum = MyHelp::GetMotorPortNum(ui.cmbMotor1Port->currentText());

	//读取参数
	App::Motor1ACVal = ui.spbAC1->text().toFloat();
	App::Motor1SpeedVal = ui.spbVE1->text().toFloat();
	App::Motor1ReRate = ui.spbReRate1->text().toFloat();

	//之前的关闭的的
	if (false == IsMotor1Open)
	{
		ret = p_MotorManager->OpenMotorPort(MOTOR_1_INDEX, portnum);
		//串口打开成功
		if (ret == true)
		{
			IsMotor1Open = true;
			//1. 修改界面和文字
			ui.lblProtState1->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenMotor1->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsMotor1Open)
	{
		ret = p_MotorManager->CloseMotorPort(MOTOR_1_INDEX);
		if (true == ret)
		{
			IsMotor1Open = false;
			//1. 修改界面和文字
			ui.lblProtState1->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenMotor1->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnOpenMotor2()
{
	bool ret = false;
	int portnum = MyHelp::GetMotorPortNum(ui.cmbMotor2Port->currentText());

	//读取参数
	App::Motor2ACVal = ui.spbAC2->text().toFloat();
	App::Motor2SpeedVal = ui.spbVE2->text().toFloat();
	App::Motor2ReRate = ui.spbReRate2->text().toFloat();

	//之前的关闭的的
	if (false == IsMotor2Open)
	{
		ret = p_MotorManager->OpenMotorPort(MOTOR_2_INDEX, portnum);
		//串口打开成功
		if (ret == true)
		{
			IsMotor2Open = true;
			//1. 修改界面和文字
			ui.lblProtState2->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenMotor2->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsMotor2Open)
	{
		ret = p_MotorManager->CloseMotorPort(MOTOR_2_INDEX);
		if (true == ret)
		{
			IsMotor2Open = false;
			//1. 修改界面和文字
			ui.lblProtState2->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenMotor2->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnOpenMotor3()
{
	bool ret = false;
	int portnum = MyHelp::GetMotorPortNum(ui.cmbMotor3Port->currentText());

	//读取参数
	App::Motor3ACVal = ui.spbAC3->text().toFloat();
	App::Motor3SpeedVal = ui.spbVE3->text().toFloat();
	App::Motor3ReRate = ui.spbReRate3->text().toFloat();

	//之前的关闭的的
	if (false == IsMotor3Open)
	{
		ret = p_MotorManager->OpenMotorPort(MOTOR_3_INDEX, portnum);
		//串口打开成功
		if (ret == true)
		{
			IsMotor3Open = true;
			//1. 修改界面和文字
			ui.lblProtState3->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenMotor3->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsMotor3Open)
	{
		ret = p_MotorManager->CloseMotorPort(MOTOR_3_INDEX);
		if (true == ret)
		{
			IsMotor3Open = false;
			//1. 修改界面和文字
			ui.lblProtState3->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenMotor3->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnOpenMotor4()
{
	bool ret = false;
	int portnum = MyHelp::GetMotorPortNum(ui.cmbMotor4Port->currentText());

	//读取参数
	App::Motor4ACVal = ui.spbAC4->text().toFloat();
	App::Motor4SpeedVal = ui.spbVE4->text().toFloat();
	App::Motor4ReRate = ui.spbReRate4->text().toFloat();

	//之前的关闭的的
	if (false == IsMotor4Open)
	{
		ret = p_MotorManager->OpenMotorPort(MOTOR_4_INDEX, portnum);
		//串口打开成功
		if (ret == true)
		{
			IsMotor4Open = true;
			//1. 修改界面和文字
			ui.lblProtState4->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenMotor4->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsMotor4Open)
	{
		ret = p_MotorManager->CloseMotorPort(MOTOR_4_INDEX);
		if (true == ret)
		{
			IsMotor4Open = false;
			//1. 修改界面和文字
			ui.lblProtState4->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenMotor4->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnOpenMotor5()
{
	bool ret = false;
	int portnum = MyHelp::GetMotorPortNum(ui.cmbMotor5Port->currentText());

	//读取参数
	App::Motor5ACVal = ui.spbAC5->text().toFloat();
	App::Motor5SpeedVal = ui.spbVE5->text().toFloat();
	App::Motor5ReRate = ui.spbReRate5->text().toFloat();

	//之前的关闭的的
	if (false == IsMotor5Open)
	{
		ret = p_MotorManager->OpenMotorPort(MOTOR_5_INDEX, portnum);
		//串口打开成功
		if (ret == true)
		{
			IsMotor5Open = true;
			//1. 修改界面和文字
			ui.lblProtState5->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenMotor5->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsMotor5Open)
	{
		ret = p_MotorManager->CloseMotorPort(MOTOR_5_INDEX);
		if (true == ret)
		{
			IsMotor5Open = false;
			//1. 修改界面和文字
			ui.lblProtState5->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenMotor5->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnOpenForceSensor()
{
	bool ret = false;
	
	//读取参数
//	App::Motor5ACVal = ui.spbAC5->text().toFloat();
//	App::Motor5SpeedVal = ui.spbVE5->text().toFloat();
//	App::Motor5ReRate = ui.spbReRate5->text().toFloat();

	//之前的关闭的的
	if (false == IsForceSensorOpen)
	{
		ret = p_ForceSensorModule->OpenForceSensorPort(ui.cmbForceSensorPort->currentText());
		//串口打开成功
		if (ret == true)
		{
			IsForceSensorOpen = true;
			//1. 修改界面和文字
			ui.lblForceSensorState->setStyleSheet("background-color: rgb(0,255,0)");
			ui.btnOpenForceSensor->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口打开失败");
		}
	}
	//之前的是打开的
	else if (true == IsForceSensorOpen)
	{
		ret = p_ForceSensorModule->CloseForceSensorPort();
//		ret = p_MotorManager->CloseMotorPort(MOTOR_5_INDEX);
		if (true == ret)
		{
			IsForceSensorOpen = false;
			//1. 修改界面和文字
			ui.lblForceSensorState->setStyleSheet("background-color: rgb(128,128,128)");
			ui.btnOpenForceSensor->setText(tr("打开串口"));
		}
		else
		{
			QMessageBox::about(NULL, "警告", "串口关闭失败");
		}
	}
}

void TestForm1::OnbtnSaveParam()
{

}

void TestForm1::OnbtnGoFrm2()
{

}



void TestForm1::OnbtnGoRight1()
{
	double dVelocity = (double)(App::Motor1SpeedVal);
	double dAccel = (double)(App::Motor1ACVal);
	double dDecel = (double)(App::Motor1ACVal);

	int nDistance = App::Motor1ReRate * DISTANCE_RATE * ui.spbDistance1->text().toInt();
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoRight2()
{
	double dVelocity = (double)(App::Motor2SpeedVal);
	double dAccel = (double)(App::Motor2ACVal);
	double dDecel = (double)(App::Motor2ACVal);

	int nDistance = App::Motor2ReRate * DISTANCE_RATE * ui.spbDistance2->text().toInt();
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoRight3()
{
	double dVelocity = (double)(App::Motor3SpeedVal);
	double dAccel = (double)(App::Motor3ACVal);
	double dDecel = (double)(App::Motor3ACVal);

	int nDistance = App::Motor3ReRate * DISTANCE_RATE * ui.spbDistance3->text().toInt();
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoRight4()
{
	double dVelocity = (double)(App::Motor4SpeedVal);
	double dAccel = (double)(App::Motor4ACVal);
	double dDecel = (double)(App::Motor4ACVal);

	int nDistance = App::Motor4ReRate * DISTANCE_RATE * ui.spbDistance4->text().toInt();
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoRight5()
{
	double dVelocity = (double)(App::Motor5SpeedVal);
	double dAccel = (double)(App::Motor5ACVal);
	double dDecel = (double)(App::Motor5ACVal);

	int nDistance = App::Motor5ReRate * DISTANCE_RATE * ui.spbDistance5->text().toInt();
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}

void TestForm1::OnbtnGoLeft1()
{
	double dVelocity = (double)(App::Motor1SpeedVal);
	double dAccel = (double)(App::Motor1ACVal);
	double dDecel = (double)(App::Motor1ACVal);

	int nDistance = App::Motor1ReRate * DISTANCE_RATE * ui.spbDistance1->text().toInt() * -1;
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoLeft2()
{
	double dVelocity = (double)(App::Motor2SpeedVal);
	double dAccel = (double)(App::Motor2ACVal);
	double dDecel = (double)(App::Motor2ACVal);

	int nDistance = App::Motor2ReRate * DISTANCE_RATE * ui.spbDistance2->text().toInt() * -1;
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoLeft3()
{
	double dVelocity = (double)(App::Motor3SpeedVal);
	double dAccel = (double)(App::Motor3ACVal);
	double dDecel = (double)(App::Motor3ACVal);

	int nDistance = App::Motor3ReRate * DISTANCE_RATE * ui.spbDistance3->text().toInt() * -1;
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoLeft4()
{
	double dVelocity = (double)(App::Motor4SpeedVal);
	double dAccel = (double)(App::Motor4ACVal);
	double dDecel = (double)(App::Motor4ACVal);

	int nDistance = App::Motor4ReRate * DISTANCE_RATE * ui.spbDistance4->text().toInt() * -1;
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}
void TestForm1::OnbtnGoLeft5()
{
	double dVelocity = (double)(App::Motor5SpeedVal);
	double dAccel = (double)(App::Motor5ACVal);
	double dDecel = (double)(App::Motor5ACVal);

	int nDistance = App::Motor5ReRate * DISTANCE_RATE * ui.spbDistance5->text().toInt() * -1;
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance, &dVelocity, &dAccel, &dDecel);
}


void TestForm1::OnbtnReadForceSensor()
{
	QString  Gross_WeightStr = QString("%1").arg(p_ForceSensorModule->Gross_Weight);
	ui.lblForceSensorVal->setText(Gross_WeightStr);

}

//设置为低电平
void TestForm1::OnbtnSetOutputLow()
{
	int Ynum = ui.cmbOutputPortNum->currentIndex() + 1;
	int motornum = ui.spbMotorIndex2->text().toInt();
	p_MotorManager->WriteOutput(Ynum, motornum, false);
}

//设置输出高电平
void TestForm1::OnbtnSetOutputHigh()
{
	int Ynum = ui.cmbOutputPortNum->currentIndex() + 1;
	int motornum = ui.spbMotorIndex2->text().toInt();
	p_MotorManager->WriteOutput(Ynum, motornum, true);
}

void TestForm1::OnbtnReadInput()
{
	int inputvalue = 0;
	int motorindex = ui.spbMotorIndex->text().toInt();
	inputvalue = p_MotorManager->ReadInput(motorindex);

//input1
	if (inputvalue & 0x01)
	{
		ui.lblInputState1->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState1->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input2
	if (inputvalue & 0x02)
	{
		ui.lblInputState2->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState2->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input3
	if (inputvalue & 0x04)
	{
		ui.lblInputState3->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState3->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input4
	if (inputvalue & 0x08)
	{
		ui.lblInputState4->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState4->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input5
	if (inputvalue & 0x10)
	{
		ui.lblInputState5->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState5->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input6
	if (inputvalue & 0x20)
	{
		ui.lblInputState6->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState6->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input7
	if (inputvalue & 0x40)
	{
		ui.lblInputState7->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState7->setStyleSheet("background-color: rgb(128,128,128)");
	}

//input8
	if (inputvalue & 0x80)
	{
		ui.lblInputState8->setStyleSheet("background-color: rgb(0,255,0)");
	}
	else
	{
		ui.lblInputState8->setStyleSheet("background-color: rgb(128,128,128)");
	}
}


void TestForm1::OnbtnPullLiqiud()
{
	int nDistance1 = 5000;
	double dVelocity1 = 10;
	double dAccel1 = 5;
	double dDecel1 = 5;

	int nDistance2 = 2000;
	double dVelocity2 = 10;
	double dAccel2 = 5;
	double dDecel2 = 5;

//1. 1号电机和2号电机前进
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1, &dVelocity1, &dAccel1, &dDecel1);
//	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2, &dVelocity2, &dAccel2, &dDecel2);
//	Sleep(10);

//2. 等待1号电机，2号电机停止
	while ((p_MotorManager->IsInAlarmCWLimit(MOTOR_1_INDEX) == true)
		&& (p_MotorManager->IsInAlarmCCWLimit(MOTOR_1_INDEX) == true)
		)
	{
		Sleep(4);
	}

//3. 等待0.5s
	Sleep(500);


//4. 后退
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1*(-1), &dVelocity1, &dAccel1, &dDecel1);
}


void TestForm1::OnbtnPullLiqiud_2()
{
	int i = 0;

	int nDistance1 = 5000;
	double dVelocity1 = 10;
	double dAccel1 = 5;
	double dDecel1 = 5;

	int nDistance2 = 2000;
	double dVelocity2 = 10;
	double dAccel2 = 5;
	double dDecel2 = 5;

	int n_testTime = ui.spbMotorTime->text().toInt();
	int n_testDis = ui.spbMotorDis->text().toInt();

	nDistance1 = n_testDis;

	for (i = 0; i < n_testTime; i++)
	{
		//1. 1号电机和2号电机前进
		p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1, &dVelocity1, &dAccel1, &dDecel1);
		//	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2, &dVelocity2, &dAccel2, &dDecel2);
		//	Sleep(10);
		Sleep(500);
		//2. 等待1号电机，2号电机停止
//		while ((p_MotorManager->IsStopping(MOTOR_1_INDEX) == true))
		while((p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
		{
			Sleep(4);
		}
/*
		while ((p_MotorManager->IsInAlarmCWLimit(MOTOR_1_INDEX) == true)
			&& (p_MotorManager->IsInAlarmCCWLimit(MOTOR_1_INDEX) == true)
			)
		{
			Sleep(4);
		}
*/

		//3. 等待0.5s
		Sleep(500);


		//4. 后退
		p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1*(-1), &dVelocity1, &dAccel1, &dDecel1);
		Sleep(1000);
		while ((p_MotorManager->IsStopping(MOTOR_1_INDEX) == true))
		{
			Sleep(4);
		}
	}
}

