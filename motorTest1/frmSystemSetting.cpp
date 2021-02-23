#include "frmSystemSetting.h"
#include "common.h"
#include "QMessageBox"


frmSystemSetting::frmSystemSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	connect(ui.btnParamSetting, SIGNAL(clicked()), this, SLOT(OnbtnParamSetting()));
	connect(ui.btnAccountManagement, SIGNAL(clicked()), this, SLOT(OnbtnAccountManagement()));
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));
	connect(ui.btnFormulaSetting, SIGNAL(clicked()), this, SLOT(OnbtnFormulaSetting()));
	connect(ui.btnWorkLog, SIGNAL(clicked()), this, SLOT(OnbtnWorkLog()));
}

frmSystemSetting::~frmSystemSetting()
{
}


void frmSystemSetting::OnbtnParamSetting()
{
	emit  this->btnClickedSignal(FRM_SYSTEMSETTING, SYSTEM_PARAM_SETTING_BTN_TYPE);
}

void frmSystemSetting::OnbtnAccountManagement()
{
	emit  this->btnClickedSignal(FRM_SYSTEMSETTING, ACCOUNT_MANAGEMENT_BTN_TYPE);
}

void frmSystemSetting::OnbtnFormulaSetting()
{
	emit  this->btnClickedSignal(FRM_SYSTEMSETTING, GO_FORMULA_SETTING);
}


void frmSystemSetting::OnbtnWorkLog()
{
	emit  this->btnClickedSignal(FRM_SYSTEMSETTING, GO_WORK_LOG_BROWSE);
}



void frmSystemSetting::OnbtnExit()
{
	emit  this->btnClickedSignal(FRM_SYSTEMSETTING, GO_EXIT_BTN_TYPE);
}


void frmSystemSetting::closeEvent(QCloseEvent *event)
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
