#include "frmPrepareDrug.h"
#include "common.h"
#include "QMessageBox"
#include"GlobalParam.h"




frmPrepareDrug::frmPrepareDrug(MOTOFun *pMOTOFun, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("��ҩ����3 ---��ҩ׼��"));
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
	ui.btnInjector->setText("�Ѱ�װ");
	ui.btnInjector->setDisabled(true);
}

void frmPrepareDrug::OnbtnMoliquorbag()
{
	ui.btnMoliquorbag->setText("�Ѱ�װ");
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
		QString str = QString("�����ڰ�װ��%1��ҩƿ").arg(MOTOFun::n +1);
		//QString str = QString("�����ڰ�װ��%1��ҩƿ").arg((p_MOTOFun->n)+1);

		while ((photoswitch == 0))  //ReadInput()�е�ֵΪ������
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
		
		switch (QMessageBox::information(this, tr("��ʾ"), str, tr("��װ���"), tr("������װ"), 0, 1))
		{
			//�ر����
		case 0:
			n1 = 0;
			break;
		case 1:
			p_MOTOFun->OnbtnUpBottle();
			break;
		}

		//��ƿ����
	/*	if (MOTOFun::n < GlobalParam::N)
		{
			switch (QMessageBox::information(this, tr("��ʾ"), str, tr("��װ���"), tr("������װ"), 0, 1))
			{
				//�ر����
			case 0:
				n1 = 0;
				break;
			case 1:
				p_MOTOFun->OnbtnUpBottle();
				break;
			}
		}
		else
		    QMessageBox::warning(this, tr("����"), tr("����������"), QMessageBox::Yes );
			*/
		




		QString str1 = QString("��%2��ҩƿ").arg(++n2);

		ui.label_3->setText(str1);
	}


}


void frmPrepareDrug::closeEvent(QCloseEvent *event)
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