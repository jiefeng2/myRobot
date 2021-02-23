#pragma once

#include <QWidget>
#include "ui_frmMainWidget.h"
#include "frmReadFormula.h"
#include "frmSelfTest.h"
#include "frmPrepareDrug.h"
#include "frmDispenseProcess.h"
#include "frmDispenseFinish.h"
#include "qtimer.h"
#include "frmRecipeSetting.h"
#include "frmSystemSetting.h"
#include "frmSystemParamSetting.h"
#include "frmAccountManager.h"
#include "MotorManager.h"
#include "TestForm1.h"
#include "ForceSensorModule.h"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QTableView"
#include "QSqlTableModel"
#include "QSqlError"
#include "QDateTime"
#include "QHeaderView"
#include "frmLogin.h"
#include "frmFormulaSetting.h"
#include "frmWorkLog.h"
#include "QCloseEvent"
#include "mythread.h"



class frmMainWidget : public QWidget
{
	Q_OBJECT

public:
	frmMainWidget(QWidget *parent = Q_NULLPTR);
	~frmMainWidget();



private:
	Ui::frmMainWidget ui;

	frmSystemParamSetting *pfrmSystemParamSetting;
	frmReadFormula * pfrmReadFormula;
	frmSelfTest * pfrmSelfTest;
	frmPrepareDrug* pfrmPrepareDrug;
	frmDispenseProcess *pfrmDispenseProcess;
	frmDispenseFinish *pfrmDispenseFinish;
	frmRecipeSetting *pfrmRecipeSetting;
	frmSystemSetting *pfrmSystemSetting;
	frmAccountManager *pfrmAccountManager;
	frmFormulaSetting *pfrmFormulaSetting;
	frmWorkLog *pfrmWorkLog;


//	frmLogin *pfrmLogin;

	TestForm1 *pTestForm1;

    MotorManager *pMotorManager;
	ForceSensorModule *pForceSensorModule;
	MOTOFun *pMOTOFun;

	myThread *pmyThread;


	QTimer *systimer;

	void InitChlidWidget();

private slots:
	void OnbtnDispense();
	void OnbtnRecipeSet();
	void OnbtnSystemSet();
	void OnbtnExit();
		
	void OnChangeWidget(int widgetindex, int btntype);

	void OnsystimerTimeOut();

	void closeEvent(QCloseEvent *event);
};
