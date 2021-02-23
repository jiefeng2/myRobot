#include "frmDispenseFinish.h"
#include "common.h"
#include "QMessageBox"


frmDispenseFinish::frmDispenseFinish(MOTOFun *pMOTOFun, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("配药界面5 ---结束配药"));
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);
	
	p_MOTOFun = pMOTOFun;
	
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnGoExit()));
	connect(ui.btndBottle, SIGNAL(clicked()), this, SLOT(OnbtndBottle()));
	connect(ui.btndInjector, SIGNAL(clicked()), this, SLOT(OnbtndInjector()));
	connect(ui.btndMoLiquorbag, SIGNAL(clicked()), this, SLOT(OnbtndMoliquorbag()));

}

frmDispenseFinish::~frmDispenseFinish()
{
}

void frmDispenseFinish::OnbtnGoExit()
{
	emit  this->btnClickedSignal(FRM_DISPENSE_FINISH, GO_EXIT_BTN_TYPE);
}
//去除瓶子及夹具
void frmDispenseFinish::OnbtndBottle()
{
	p_MOTOFun->OnbtnDownBottle();
	ui.btndBottle->setText("完成卸载");
}


void frmDispenseFinish::OnbtndMoliquorbag()
{
	ui.btndMoLiquorbag->setText("完成卸载");
}

void frmDispenseFinish::OnbtndInjector()
{

	ui.btndInjector->setText("完成卸载");
}

void frmDispenseFinish::closeEvent(QCloseEvent *event)
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

