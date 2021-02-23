#include "frmRecipeSetting.h"
#include "common.h"
#include "QMessageBox"


frmRecipeSetting::frmRecipeSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnGoExit()));
}

frmRecipeSetting::~frmRecipeSetting()
{
}

void frmRecipeSetting::OnbtnGoExit()
{
	emit  this->btnClickedSignal(FRM_RECIPE_SETTING, GO_EXIT_BTN_TYPE);
}


void frmRecipeSetting::closeEvent(QCloseEvent *event)
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