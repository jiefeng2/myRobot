#include "frmWorkLog.h"
#include "common.h"
#include "QMessageBox"
#include "GlobalParam.h"

frmWorkLog::frmWorkLog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));
}

frmWorkLog::~frmWorkLog()
{

}

void frmWorkLog::OnbtnExit()
{
	emit  this->btnClickedSignal(FRM_WORK_LOG, GO_EXIT_BTN_TYPE);


}


void frmWorkLog::closeEvent(QCloseEvent *event)
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

