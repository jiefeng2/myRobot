#pragma once

#include <QWidget>
#include "ui_frmSystemParamSetting.h"
#include "MyHelp.h"
#include "QCloseEvent"
#include "MotorManager.h"
#include "qstring.h"
#include "qstringlist.h"
#include "common.h"
#include "App.h"
#include "ForceSensorModule.h"
#include "motofun.h"

class frmSystemParamSetting : public QWidget
{
	Q_OBJECT

public:
	frmSystemParamSetting(MotorManager *pMotorManager, ForceSensorModule *pForceSensorModule, QWidget *parent = Q_NULLPTR);
	~frmSystemParamSetting();

	

private:
	Ui::frmSystemParamSetting ui;
	void closeEvent(QCloseEvent *event);
	QStringList  SerialPortNameList;

	void SetPortNameCmb();
	void InitPortCmb();
	void Initspb();
	void OpenMotorPort1(int motorindex, int portnum);


	bool IsMotor1Open;
	bool IsMotor2Open;
	bool IsMotor3Open;
	bool IsMotor4Open;
	bool IsMotor5Open;

	bool IsForceSensorOpen;

	MotorManager *p_MotorManager;
	ForceSensorModule *p_ForceSensorModule;

	

public slots:
	void OnbtnSaveParam();
	void OnbtnExit();
	void OnbtnOpenMotor1();
	void OnbtnOpenMotor2();
	void OnbtnOpenMotor3();
	void OnbtnOpenMotor4();
	void OnbtnOpenMotor5();
	
	

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
	
	void OnbtnSetOutputLow();
	void OnbtnSetOutputHigh();


signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
