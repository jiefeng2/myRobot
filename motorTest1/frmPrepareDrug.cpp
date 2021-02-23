#include "frmPrepareDrug.h"
#include "common.h"
#include "QMessageBox"
#include"GlobalParam.h"




frmPrepareDrug::frmPrepareDrug(MOTOFun *pMOTOFun, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("配药界面3 ---配药准备"));
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);
	p_MOTOFun = pMOTOFun;
	connect(ui.btnGoNext, SIGNAL(clicked()), this, SLOT(OnbtnGoNext()));
	connect(ui.btnGoBack, SIGNAL(clicked()), this, SLOT(OnbtnGoBack()));
	connect(ui.btnInjector, SIGNAL(clicked()), this, SLOT(OnbtnInjector()));
	connect(ui.btnMoliquorbag, SIGNAL(clicked()), this, SLOT(OnbtnMoliquorbag()));
	connect(ui.btnBottle, SIGNAL(clicked()), this, SLOT(OnbtnBottle()));
}

frmPrepareDrug::~frmPrepareDrug()
{
}

void frmPrepareDrug::OnbtnGoNext()
{
	emit  this->btnClickedSignal(FRM_PREPARE_DRUG, GO_NEXT_BTN_TYPE);
}

void frmPrepareDrug::OnbtnGoBack()
{
	emit  this->btnClickedSignal(FRM_PREPARE_DRUG, GO_BACK_BTN_TYPE);
}

void frmPrepareDrug::OnbtnInjector()
{
	ui.btnInjector->setText("已安装");
	ui.btnInjector->setDisabled(true);
}

void frmPrepareDrug::OnbtnMoliquorbag()
{
	ui.btnMoliquorbag->setText("已安装");
	ui.btnMoliquorbag->setDisabled(true);

}

void frmPrepareDrug::OnbtnBottle()
{
    //static int n = 0;
	int photoswitch = 0;
	int n1 = 1;
	int n2 = 0;

	while (n1)
	{
		QString str = QString("您正在安装第%1个药瓶").arg(MOTOFun::n +1);
		//QString str = QString("您正在安装第%1个药瓶").arg((p_MOTOFun->n)+1);

		while ((photoswitch == 0))  //ReadInput()中的值为电机编号
		{
			Sleep(400);
			if (p_MOTOFun->p_MotorManager->ReadInput(3) & 0x04)
				photoswitch = 0;
			else
				photoswitch = 1;
		}
		photoswitch = 0;
		MOTOFun::n++;
		//n++;
		
		switch (QMessageBox::information(this, tr("提示"), str, tr("安装完毕"), tr("继续安装"), 0, 1))
		{
			//关闭软件
		case 0:
			n1 = 0;
			break;
		case 1:
			p_MOTOFun->OnbtnUpBottle();
			break;
		}

		//多瓶警告
	/*	if (MOTOFun::n < GlobalParam::N)
		{
			switch (QMessageBox::information(this, tr("提示"), str, tr("安装完毕"), tr("继续安装"), 0, 1))
			{
				//关闭软件
			case 0:
				n1 = 0;
				break;
			case 1:
				p_MOTOFun->OnbtnUpBottle();
				break;
			}
		}
		else
		    QMessageBox::warning(this, tr("警告"), tr("数量超出！"), QMessageBox::Yes );
			*/
		




		QString str1 = QString("第%2个药瓶").arg(++n2);

		ui.label_3->setText(str1);
	}


}


void frmPrepareDrug::closeEvent(QCloseEvent *event)
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