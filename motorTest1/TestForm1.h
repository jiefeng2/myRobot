#pragma once

#include <QWidget>
#include "ui_TestForm1.h"
#include "MotorManager.h"
#include "qstring.h"
#include "qstringlist.h"
#include "MyHelp.h"
#include "common.h"
#include "App.h"
#include "ForceSensorModule.h"



class TestForm1 : public QWidget
{
	Q_OBJECT

public:
	TestForm1(MotorManager *pMotorManager, ForceSensorModule *pForceSensorModule, QWidget *parent = Q_NULLPTR);
	~TestForm1();

	MotorManager *p_MotorManager;
	ForceSensorModule *p_ForceSensorModule;

	private slots:
	void OnbtnOpenMotor1();
	void OnbtnOpenMotor2();
	void OnbtnOpenMotor3();
	void OnbtnOpenMotor4();
	void OnbtnOpenMotor5();
	void OnbtnSaveParam();
	void OnbtnGoFrm2();

	void OnbtnGoRight1();
	void OnbtnGoRight2();
	void OnbtnGoRight3();
	void OnbtnGoRight4();
	void OnbtnGoRight5();
	
	void OnbtnGoLeft1();
	void OnbtnGoLeft2();
	void OnbtnGoLeft3();
	void OnbtnGoLeft4();
	void OnbtnGoLeft5();

	void OnbtnReadInput();
	void OnbtnOpenForceSensor();
	void OnbtnReadForceSensor();
	void OnbtnPullLiqiud();
	void OnbtnPullLiqiud_2();

	void OnbtnSetOutputLow();
	void OnbtnSetOutputHigh();
//----------------------------------------------------------------------------------------------------------------------------------------//




private:
	void InitPortCmb();
	void Initspb();
	void OpenMotorPort1(int motorindex, int portnum);

	QStringList SerialPortNameList;

	bool IsMotor1Open;
	bool IsMotor2Open;
	bool IsMotor3Open;
	bool IsMotor4Open;
	bool IsMotor5Open;

	bool IsForceSensorOpen;



private:
	Ui::TestForm1 ui;
};
