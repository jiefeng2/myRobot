#include "frmReadFormula.h"
#include "App.h"
#include "QSqlRecord"
#include "GlobalParam.h"
#include "QMessageBox"

frmReadFormula::frmReadFormula(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("��ҩ����1 ---��ȡ�䷽"));
//	setWindowModality(Qt::ApplicationModal);
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	ui.tbvwFormula->setEditTriggers(QAbstractItemView::NoEditTriggers);

	formulamodel = new QSqlTableModel(this);
	formulamodel->setTable("formulatable");
	formulamodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//ѡȡ�������������
	formulamodel->select();
	formulamodel->removeColumn(0);
//	formulamodel->setHeaderData(0, Qt::Horizontal, tr("���")); //�޸�����
	formulamodel->setHeaderData(0, Qt::Horizontal, tr("���")); //�޸�����
	formulamodel->setHeaderData(1, Qt::Horizontal, tr("ҩ������"));
	formulamodel->setHeaderData(2, Qt::Horizontal, tr("ĸҺ����"));
	formulamodel->setHeaderData(3, Qt::Horizontal, tr("ҩƿ����"));
	formulamodel->setHeaderData(4, Qt::Horizontal, tr("����ƿ����"));
	formulamodel->setHeaderData(5, Qt::Horizontal, tr("ĸҺ��(ml)"));
	formulamodel->setHeaderData(6, Qt::Horizontal, tr("��ƿĸҺ��(ml)"));
	formulamodel->setHeaderData(7, Qt::Horizontal, tr("Ŀ������(g)"));

	formulamodel->setHeaderData(8, Qt::Horizontal, tr("ҡ�νǶȣ��ȣ�"));
	formulamodel->setHeaderData(9, Qt::Horizontal, tr("ҡ�δ������Σ�"));
	formulamodel->setHeaderData(10, Qt::Horizontal, tr("������g��"));
	formulamodel->setHeaderData(11, Qt::Horizontal, tr("��������ml��"));
	formulamodel->setHeaderData(12, Qt::Horizontal, tr("��Һ��������"));
	formulamodel->setHeaderData(13, Qt::Horizontal, tr("��Һ����Vf"));
	formulamodel->setHeaderData(14, Qt::Horizontal, tr("��Һ����Vg"));
	formulamodel->setHeaderData(15, Qt::Horizontal, tr("��Һ���F1"));
	formulamodel->setHeaderData(16, Qt::Horizontal, tr("��Һ�ƾ�G1"));

	formulamodel->setHeaderData(17, Qt::Horizontal, tr("��Һ���F2"));
	formulamodel->setHeaderData(18, Qt::Horizontal, tr("��Һ���G2"));
	formulamodel->setHeaderData(19, Qt::Horizontal, tr("���1����"));
	formulamodel->setHeaderData(20, Qt::Horizontal, tr("���2����"));
	formulamodel->setHeaderData(21, Qt::Horizontal, tr("���3����"));
	formulamodel->setHeaderData(22, Qt::Horizontal, tr("���4����"));
	
	
	formulamodel->setHeaderData(23, Qt::Horizontal, tr("���5����"));
	formulamodel->setHeaderData(24, Qt::Horizontal, tr("��������"));


	ui.tbvwFormula->setModel(formulamodel);

	connect(ui.btnGoNext, SIGNAL(clicked()), this, SLOT(OnbtnGoNext()));
	connect(ui.btnGoBack, SIGNAL(clicked()), this, SLOT(OnbtnGoBack()));
	connect(ui.btnReadFormula, SIGNAL(clicked()), this, SLOT(OnbtnReadFormula()));
}

frmReadFormula::~frmReadFormula()
{

}

void frmReadFormula::OnbtnGoNext()
{
	emit  this->btnClickedSignal(FRM_READ_FORMULA, GO_NEXT_BTN_TYPE);
}

void frmReadFormula::OnbtnGoBack()
{
	emit  this->btnClickedSignal(FRM_READ_FORMULA, GO_BACK_BTN_TYPE);
}



void frmReadFormula::OnbtnReadFormula()
{
	int curRow = ui.tbvwFormula->currentIndex().row();

	if (curRow >=0)
	{
		QSqlRecord record = formulamodel->record(curRow);

		g_formula_manager->s_serial_num = record.value(0).toString();
		g_formula_manager->s_grug_name = record.value(1).toString();
		g_formula_manager->s_mother_liquor_name = record.value(2).toString();
		g_formula_manager->s_bottle_name = record.value(3).toString();
		g_formula_manager->s_vial_bottle_num = record.value(4).toString();
		g_formula_manager->s_mother_liquor_cap = record.value(5).toString();
		g_formula_manager->s_single_mother_liquor_cap = record.value(6).toString();
		g_formula_manager->s_target_weight = record.value(7).toString();
		g_formula_manager->s_sShakeAngle = record.value(8).toString();
		g_formula_manager->s_sShakeTimes = record.value(9).toString();
		g_formula_manager->s_sWeighingError = record.value(10).toString();
		g_formula_manager->s_sPumpCapacity = record.value(11).toString();
		g_formula_manager->s_change_timer = record.value(12).toString();
		g_formula_manager->s_change_param_Vf = record.value(13).toString();
		g_formula_manager->s_change_param_Vg = record.value(14).toString();
		g_formula_manager->s_change_param_F1 = record.value(15).toString();
		g_formula_manager->s_change_param_G1 = record.value(16).toString();
		g_formula_manager->s_change_param_F2 = record.value(17).toString();
		g_formula_manager->s_change_param_G2 = record.value(18).toString();
		g_formula_manager->s_change_param_F3 = record.value(19).toString();
		g_formula_manager->s_change_param_G3 = record.value(20).toString();
		g_formula_manager->s_change_param_F4 = record.value(21).toString();
		g_formula_manager->s_change_param_G4 = record.value(22).toString();
		g_formula_manager->s_change_param_F5 = record.value(23).toString();
		g_formula_manager->s_change_param_G5 = record.value(24).toString();

	     GlobalParam::N = g_formula_manager->s_vial_bottle_num.toInt();    //����ƿ������
		 GlobalParam::Q = g_formula_manager->s_change_timer.toInt();       //��Һ��������
		 GlobalParam::C1 = g_formula_manager->s_mother_liquor_cap.toInt(); //��ĸҺ�������ĸҺ��ml
		 GlobalParam::Cc = 9.6 + GlobalParam::N *GlobalParam::C1;          //��Ͳ��ĸҺ������
		 GlobalParam::A1 = 24;                                             //������ƿע��ĸҺ����Ͳǰ�����mm
		 GlobalParam::A2 = 22;                                             //������ƿ��ȡ���Һ��Ͳǰ�����mm
		 GlobalParam::A3 = 31;                                             //��Ͳ����ĸҺ��ʱǰ����� mm
		 GlobalParam::C2 = g_formula_manager->s_single_mother_liquor_cap.toFloat();  //��ƿĸҺע������������ƿ��ע��mm
		 GlobalParam::B1 = g_formula_manager->s_sShakeAngle.toInt();                   //��һ��ĽǶ�
		 GlobalParam::B2 = g_formula_manager->s_sShakeTimes.toInt();                   //�εĴ���
		 GlobalParam::M1 = g_formula_manager->s_target_weight.toFloat();  //Ŀ������
		 GlobalParam::dm = g_formula_manager->s_sWeighingError.toFloat(); //������������
		 GlobalParam::Cali = 0;//�������궨ֵ��ÿV��Ӧg
		 GlobalParam::C3 = 0; //����Һǰ����ʱA��Ӵ�������C3
		 GlobalParam::C4 = 0; //��Ͳ��ʼһ�������г�mm
		 GlobalParam::F1 = g_formula_manager->s_change_param_F1.toInt();//��Һ�����е�һ����A����˾���
		 GlobalParam::G1 = g_formula_manager->s_change_param_G1.toInt();//��Һ�����е�һ����B��ǰ������
		 GlobalParam::Vg = g_formula_manager->s_change_param_Vg.toInt();//��Һ��������A��ǰ���ٶ�
		 GlobalParam::F2 = g_formula_manager->s_change_param_F2.toInt();//��Һ�����еڶ�����A����˾���
		 GlobalParam::G2 = g_formula_manager->s_change_param_G2.toInt();//��Һ�����еڶ�����B��ǰ������
		 GlobalParam::Vf = g_formula_manager->s_change_param_Vf.toInt();//��Һ��������A��ǰ���ٶ�

		 GlobalParam::com1 = g_formula_manager->s_change_param_F3.toInt();
		 GlobalParam::com2 = g_formula_manager->s_change_param_G3.toInt();		
		 GlobalParam::com3 = g_formula_manager->s_change_param_F4.toInt();
		 GlobalParam::com4 = g_formula_manager->s_change_param_G4.toInt();
		 GlobalParam::com5 = g_formula_manager->s_change_param_F5.toInt();
		 GlobalParam::com6 = g_formula_manager->s_change_param_G5;


		 GlobalParam::Velo = 3;  //��Һ��������A��ǰ���ٶ�
		 GlobalParam::C5 = 20;   //עҺ�׶���Һ�������г�
		 GlobalParam::C6 = 241;//�ڴ�ĸҺ����Һ��עҺ��ʱ����5���г� 
	}
	else
	{
		QMessageBox::information(this, tr("��ѡ��ҩ��"), tr("��ѡ��ҩ��"), QMessageBox::Ok);
	}
}


//����ҩ�������ʾ
void frmReadFormula::UpdateFormulaDisplay()
{
	//ѡȡ�������������
	formulamodel->select();
}


void frmReadFormula::closeEvent(QCloseEvent *event)
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






