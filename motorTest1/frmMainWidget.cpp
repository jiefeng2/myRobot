#include "frmMainWidget.h"
#include "App.h"
#include "dbconnection.h"
#include "GlobalParam.h"
#include "QMessageBox"
#include "common.h"
#include "motofun.h"
#include "QDebug.h"

frmMainWidget::frmMainWidget(QWidget *parent)
	: QWidget(parent)
{
	bool ret = false;


	ui.setupUi(this);

	g_formula_manager = new FormulaManager(this);


	systimer = new QTimer();
	systimer->setInterval(1);

	ret = createConnection();


	InitChlidWidget();

	connect(ui.btnSystemSet, SIGNAL(clicked()), this, SLOT(OnbtnSystemSet()));
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));
	connect(ui.btnDispense, SIGNAL(clicked()), this, SLOT(OnbtnDispense()));
	connect(ui.btnRecipeSet, SIGNAL(clicked()), this, SLOT(OnbtnRecipeSet()));

//	connect(pfrmReadFormula, SIGNAL(btnClickedSignal1(int widgetindex, int btntype)), this, SLOT(OnChangeWidget1(int widgetindex, int btntype)));
	connect(this->pfrmReadFormula, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmSelfTest, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmPrepareDrug, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmDispenseProcess, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmDispenseFinish, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmRecipeSetting, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmSystemSetting, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmAccountManager, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmFormulaSetting, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
	connect(this->pfrmWorkLog, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
//	connect(this->pfrmSystemParamSetting, SIGNAL(btnClickedSignal(int, int)), this, SLOT(OnChangeWidget(int, int)));
//	connect(this->systimer, SIGNAL(timerout()), this, SLOT(OnsystimerTimeOut()));
//	systimer->start();

//测试界面
//	this->hide();
//	pTestForm1->show();

//	pfrmLogin->show();
//	this->hide();


}

frmMainWidget::~frmMainWidget()
{

}



void frmMainWidget::OnbtnDispense()
{
	this->hide();
	pfrmReadFormula->UpdateFormulaDisplay();
	pfrmReadFormula->show();
}

void frmMainWidget::OnbtnRecipeSet()
{
	this->hide();
//	pfrmRecipeSetting->show();
	pfrmFormulaSetting->show();
}
	
void frmMainWidget::OnbtnSystemSet()
{
	this->hide();
	pfrmSystemSetting->show();
}
	
void frmMainWidget::OnbtnExit()
{
	this->close();
}

//初始化控件
void frmMainWidget::InitChlidWidget()
{
	pMotorManager = new MotorManager(this);
	pForceSensorModule = new ForceSensorModule(this);
	pMOTOFun = new MOTOFun(pMotorManager, pForceSensorModule, this);

	pmyThread = new myThread(pMOTOFun, this);

	pfrmSystemParamSetting = new frmSystemParamSetting(pMotorManager, pForceSensorModule, this);
	pfrmSystemParamSetting->hide();

	pfrmReadFormula = new frmReadFormula(this);
	pfrmReadFormula->hide();
	pfrmSelfTest = new frmSelfTest(pMOTOFun, this);
	pfrmSelfTest->hide();
	pfrmPrepareDrug = new frmPrepareDrug(pMOTOFun, this);
	pfrmPrepareDrug->hide();
	pfrmDispenseProcess = new frmDispenseProcess(pmyThread, pForceSensorModule, this);
	pfrmDispenseProcess->hide();
	pfrmDispenseFinish = new frmDispenseFinish(pMOTOFun, this);
	pfrmDispenseFinish->hide();

	pfrmRecipeSetting  = new frmRecipeSetting(this);
	pfrmRecipeSetting->hide();
	pfrmSystemSetting = new frmSystemSetting(this);
	pfrmSystemSetting->hide();
	pfrmAccountManager = new frmAccountManager(this);
	pfrmAccountManager->hide();
	pfrmFormulaSetting = new frmFormulaSetting(this);
	pfrmFormulaSetting->hide();
	pfrmWorkLog = new frmWorkLog(this);
	pfrmWorkLog->hide();

//	pfrmLogin = new frmLogin(this);
//	pfrmLogin->show();

	pTestForm1 = new TestForm1(pMotorManager, pForceSensorModule);
	pTestForm1->hide();
}


void frmMainWidget::OnChangeWidget(int widgetindex, int btntype)
{
	switch (widgetindex)
	{
	case FRM_READ_FORMULA:
		if (GO_NEXT_BTN_TYPE == btntype)
		{
			pfrmReadFormula->hide();
			pfrmSelfTest->show();
		}
		else if (GO_BACK_BTN_TYPE == btntype)
		{
			pfrmReadFormula->hide();
			this->show();
		}
		break;

	case FRM_SELF_TEST:
		if (GO_NEXT_BTN_TYPE == btntype)
		{
//			pfrmReadFormula->hide();
			pfrmSelfTest->hide();
			pfrmPrepareDrug->show();
		}
		else if (GO_BACK_BTN_TYPE == btntype)
		{
			pfrmReadFormula->show();
			pfrmSelfTest->hide();
		}
		break;

	case FRM_PREPARE_DRUG:
		if (GO_NEXT_BTN_TYPE == btntype)
		{
			//			pfrmReadFormula->hide();
			pfrmPrepareDrug->hide();
			pfrmDispenseProcess->show();
		}
		else if (GO_BACK_BTN_TYPE == btntype)
		{
			pfrmSelfTest->show();
			pfrmPrepareDrug->hide();
		}
		break;

	case FRM_DISPENSE_PROCESS:
		if (GO_NEXT_BTN_TYPE == btntype)
		{
			pfrmDispenseProcess->hide();
			pfrmDispenseFinish->show();
		}
		break;

	case FRM_DISPENSE_FINISH:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmDispenseFinish->hide();
			this->show();
		}
		break;

	case FRM_RECIPE_SETTING:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmRecipeSetting->hide();
			this->show();
		}
		break;

	case FRM_SYSTEMSETTING:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmSystemSetting->hide();
			this->show();
		}
		else if (SYSTEM_PARAM_SETTING_BTN_TYPE == btntype)
		{
	//		pfrmSystemSetting->hide();
			pfrmSystemParamSetting->show();
		}
		else if (ACCOUNT_MANAGEMENT_BTN_TYPE == btntype)
		{
			pfrmSystemSetting->hide();
//添加账户管理界面----------------------------------------------------
			pfrmAccountManager->show();
		}
		else if (GO_FORMULA_SETTING == btntype)
		{
			pfrmSystemSetting->hide();
			pfrmFormulaSetting->show();
		}
		else if (GO_WORK_LOG_BROWSE == btntype)
		{
			pfrmSystemSetting->hide();
			pfrmWorkLog->show();
		}
		break;

	case FRM_ACCOUNTMANAGER:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmAccountManager->hide();
			pfrmSystemSetting->show();
		}
		break;

	case FRM_FORMULA_SETTING:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmFormulaSetting->hide();
			this->show();
		}
		break;

	case FRM_WORK_LOG:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmWorkLog->hide();
			pfrmSystemSetting->show();
		}
		break;

	case FRM_SYSTEMPARAM_SETTING:
		if (GO_EXIT_BTN_TYPE == btntype)
		{
			pfrmSystemParamSetting->hide();
			pfrmSystemSetting->show();
		}
		break;

	default:
		break;
	}

}


void frmMainWidget::OnsystimerTimeOut()
{
	
}

void frmMainWidget::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, tr("提示"), tr("你确定退出该软件?"), tr("确定"), tr("取消"), 0, 1))
	{
		//关闭软件
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


