#include "frmDispenseFinish.h"
#include "common.h"
#include "QMessageBox"


frmDispenseFinish::frmDispenseFinish(MOTOFun *pMOTOFun, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("��ҩ����5 ---������ҩ"));
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
//ȥ��ƿ�Ӽ��о�
void frmDispenseFinish::OnbtndBottle()
{
	p_MOTOFun->OnbtnDownBottle();
	ui.btndBottle->setText("���ж��");
}


void frmDispenseFinish::OnbtndMoliquorbag()
{
	ui.btndMoLiquorbag->setText("���ж��");
}

void frmDispenseFinish::OnbtndInjector()
{

	ui.btndInjector->setText("���ж��");
}

void frmDispenseFinish::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, tr("��ʾ"), tr("��ȷ���˳������?"), tr("ȷ��"), tr("ȡ��"), 0, 1))
	{
		//�ر����
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

