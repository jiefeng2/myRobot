#include "frmFormulaSetting.h"
#include "qmessagebox.h"
#include "QMessageBox"
#include "QSqlRecord"
#include "QModelIndex"
#include "QSqlTableModel"
#include <QSqlDatabase>
#include "QSqlQuery"
#include "QTableView"
#include "QSqlError"
#include "frmMainWidget.h"

frmFormulaSetting::frmFormulaSetting(QWidget *parent)
	: QDialog(parent)
{
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinMaxButtonsHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);

	ui.setupUi(this);

	m_pFParam = new CFormulaParam(this);

	ui.tbvwFormula->setEditTriggers(QAbstractItemView::NoEditTriggers);

	usrmodel = new QSqlTableModel(this);
	usrmodel->setTable("formulatable");
	usrmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//ѡȡ�������������
	usrmodel->select();

	usrmodel->removeColumn(0);  //ɾ����Ҫ��

	usrmodel->setHeaderData(0, Qt::Horizontal, tr("���")); //�޸�����
	usrmodel->setHeaderData(1, Qt::Horizontal, tr("ҩ������")); 
	usrmodel->setHeaderData(2, Qt::Horizontal, tr("ĸҺ����")); 
	usrmodel->setHeaderData(3, Qt::Horizontal, tr("ҩƿ����")); 
	usrmodel->setHeaderData(4, Qt::Horizontal, tr("����ƿ����")); 
	usrmodel->setHeaderData(5, Qt::Horizontal, tr("ĸҺ����ml��")); 
	usrmodel->setHeaderData(6, Qt::Horizontal, tr("��ƿĸҺ����ml��")); 
	usrmodel->setHeaderData(7, Qt::Horizontal, tr("Ŀ��������g��")); 
	usrmodel->setHeaderData(8, Qt::Horizontal, tr("ҡ�νǶȣ��ȣ�"));
	usrmodel->setHeaderData(9, Qt::Horizontal, tr("ҡ�δ������Σ�"));
	usrmodel->setHeaderData(10, Qt::Horizontal, tr("������g��"));
	usrmodel->setHeaderData(11, Qt::Horizontal, tr("��������ml��"));
	usrmodel->setHeaderData(12, Qt::Horizontal, tr("��Һ��������")); 
	usrmodel->setHeaderData(13, Qt::Horizontal, tr("����Vf")); 
	usrmodel->setHeaderData(14, Qt::Horizontal, tr("����Vg")); 
	usrmodel->setHeaderData(15, Qt::Horizontal, tr("�������F1")); 
	usrmodel->setHeaderData(16, Qt::Horizontal, tr("�����ƾ�G1")); 

	usrmodel->setHeaderData(17, Qt::Horizontal, tr("�������F2")); 
	usrmodel->setHeaderData(18, Qt::Horizontal, tr("�����ƾ�G2")); 
	usrmodel->setHeaderData(19, Qt::Horizontal, tr("���1����")); 
	usrmodel->setHeaderData(20, Qt::Horizontal, tr("���2����")); 
	usrmodel->setHeaderData(21, Qt::Horizontal, tr("���3����")); 
	usrmodel->setHeaderData(22, Qt::Horizontal, tr("���4����"));
	usrmodel->setHeaderData(23, Qt::Horizontal, tr("���5����")); 
	usrmodel->setHeaderData(24, Qt::Horizontal, tr("��������"));

	ui.tbvwFormula->setModel(usrmodel);

	connect(ui.btnNew, SIGNAL(clicked()), this, SLOT(OnbtnNew()));
	connect(ui.btnModify, SIGNAL(clicked()), this, SLOT(OnbtnModify()));
	connect(ui.btnDel, SIGNAL(clicked()), this, SLOT(OnbtnDel()));
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));
	connect(ui.tbvwFormula, SIGNAL(clicked(QModelIndex)), this, SLOT(OntbvwFormulaClicked()));
}

frmFormulaSetting::~frmFormulaSetting()
{
}

  //����µ��䷽ʱ����ҪУ���ţ���ͬ���䷽����Ų�����ͬ
void frmFormulaSetting::OnbtnNew()
{
	bool ret;
	//��ȡ�û����
	QString tempnum = ui.txtNum->text();
	
	QSqlQuery query;
	ret = query.exec(QString("select * from formulatable where s_serial_num = '%1'").arg(tempnum));

	//����Ѿ�����
	if (query.next())
	{
		QMessageBox::information(this, tr("�ñ���Ѿ�����"), tr("�ñ���Ѿ�����"), QMessageBox::Ok);
	}
	else
	{
		GetUiConText();
		query.exec(QString("INSERT INTO formulatable values (NULL, '%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24', '%25')") \
			.arg(m_pFParam->m_sNum)
			.arg(m_pFParam->m_sPharName)
			.arg(m_pFParam->m_sLiquorName)
			.arg(m_pFParam->m_sPillName)
			.arg(m_pFParam->m_sVialNum)
			.arg(m_pFParam->m_sLiquorVol)
			.arg(m_pFParam->m_sSingleLiquorVol)
			.arg(m_pFParam->m_sTargetWeight)
			.arg(m_pFParam->m_sShakeAngle)
			.arg(m_pFParam->m_sShakeTimes)
			.arg(m_pFParam->m_sWeighingError)
			.arg(m_pFParam->m_sPumpCapacity)
			.arg(m_pFParam->m_sExchangeTime)
			.arg(m_pFParam->m_sVf)
			.arg(m_pFParam->m_sVg)
			.arg(m_pFParam->m_sVF1)
			.arg(m_pFParam->m_sVG1)
			.arg(m_pFParam->m_sVF2)
			.arg(m_pFParam->m_sVG2)
			.arg(m_pFParam->m_com1)
			.arg(m_pFParam->m_com2)
			.arg(m_pFParam->m_com3)
			.arg(m_pFParam->m_com4)
			.arg(m_pFParam->m_com5)
			.arg(m_pFParam->m_com6));
		usrmodel->select();
	}
}

void frmFormulaSetting::OnbtnModify()
{
	bool ret;
	//��ȡ�û����
	QString stempnum = ui.txtNum->text();

	QSqlQuery query;
	ret = query.exec(QString("select * from formulatable where s_serial_num = '%1'").arg(stempnum));

	//����Ѿ�����
	if (query.next())
	{
		GetUiConText();
//		query.exec(QString("update usrnametable set usrname = '%1', psword = '%2' rights = '%3' where usrid = %4").arg(tempusername).arg(temppsword).arg(tempuserright).arg(tempusernum));
	
	
		query.exec(QString("update formulatable set s_grug_name = '%1', s_mother_liquor_name = '%2', s_bottle_name = '%3', s_vial_bottle_num = '%4', s_mother_liquor_cap = '%5', s_single_mother_liquor_cap = '%6', s_target_weight = '%7', s_shake_angle = '%8', s_shake_times = '%9', s_weighing_error = '%10', s_pump_capacity = '%11',					\
			s_change_timer = '%12', s_change_param_Vf = '%13', s_change_param_Vg = '%14', s_change_param_F1 = '%15', s_change_param_G1 = '%16', s_change_param_F2 = '%17', s_change_param_G2 = '%18', s_change_param_F3 = '%19',				\
			s_change_param_G3 = '%20', s_change_param_F4 = '%21', s_change_param_G4 = '%22', s_change_param_F5 = '%23', s_change_param_G5 = '%24' where s_serial_num = '%25'")					\
			.arg(m_pFParam->m_sPharName)
			.arg(m_pFParam->m_sLiquorName)
			.arg(m_pFParam->m_sPillName)
			.arg(m_pFParam->m_sVialNum)
			.arg(m_pFParam->m_sLiquorVol)
			.arg(m_pFParam->m_sSingleLiquorVol)
			.arg(m_pFParam->m_sTargetWeight)
			.arg(m_pFParam->m_sShakeAngle)
			.arg(m_pFParam->m_sShakeTimes)
			.arg(m_pFParam->m_sWeighingError)
			.arg(m_pFParam->m_sPumpCapacity)
			.arg(m_pFParam->m_sExchangeTime)
			.arg(m_pFParam->m_sVf)
			.arg(m_pFParam->m_sVg)
			.arg(m_pFParam->m_sVF1)
			.arg(m_pFParam->m_sVG1)
			.arg(m_pFParam->m_sVF2)
			.arg(m_pFParam->m_sVG2)
			.arg(m_pFParam->m_com1)
			.arg(m_pFParam->m_com2)
			.arg(m_pFParam->m_com3)
			.arg(m_pFParam->m_com4)
			.arg(m_pFParam->m_com5)
			.arg(m_pFParam->m_com6)
			.arg(stempnum));
	

	usrmodel->select();
	}
	else
	{
		QMessageBox::information(this, tr("�ñ���䷽������"), tr("�ñ���䷽������"), QMessageBox::Ok);
	}
}

void frmFormulaSetting::OnbtnDel()
{
	int curRow = ui.tbvwFormula->currentIndex().row();

	QSqlRecord record = usrmodel->record(curRow);
	QString stempusernum = record.value(0).toString();
	QSqlQuery query;
	bool ret = query.exec(QString("DELETE FROM formulatable where s_serial_num = '%1'").arg(stempusernum));

	usrmodel->select();
}

void frmFormulaSetting::OnbtnExit()
{
	emit  this->btnClickedSignal(FRM_FORMULA_SETTING, GO_EXIT_BTN_TYPE);
}

void frmFormulaSetting::OntbvwFormulaClicked()
{
	int curRow = ui.tbvwFormula->currentIndex().row();

	QSqlRecord record = usrmodel->record(curRow);

	ui.txtNum->setText(record.value(0).toString());
	ui.txtPharName->setText(record.value(1).toString());
	ui.txtLiquorName->setText(record.value(2).toString());
	ui.txtPillName->setText(record.value(3).toString());

//	ui.sboxVialNum->setValue(record.value(4).toInt());

	ui.sboxVialNum->setValue(record.value(4).toInt());
	ui.sboxLiquorVol->setValue(record.value(5).toInt());
	ui.sboxSingleLiquorVol->setValue(record.value(6).toInt());
	ui.sboxTargetWeight->setValue(record.value(7).toInt());

	ui.sboxShakeAngle->setValue(record.value(8).toInt());
	ui.sboxShakeTimes->setValue(record.value(9).toInt());
	ui.sboxWeighingError->setValue(record.value(10).toInt());
	ui.sboxPumpCapacity->setValue(record.value(11).toInt());

	ui.sboxExchangeTime->setValue(record.value(12).toInt());
	ui.sboxVf->setValue(record.value(13).toInt());
	ui.sboxVg->setValue(record.value(14).toInt());
	ui.sboxF1->setValue(record.value(15).toInt());
	ui.sboxG1->setValue(record.value(16).toInt());
	ui.sboxF2->setValue(record.value(17).toInt());
	ui.sboxG2->setValue(record.value(18).toInt());
	ui.sboxF3->setValue(record.value(19).toInt());
	ui.sboxG3->setValue(record.value(20).toInt());
	ui.sboxF4->setValue(record.value(21).toInt());
	ui.sboxG4->setValue(record.value(22).toInt());
	ui.sboxF5->setValue(record.value(23).toInt());
	ui.sboxG5->setText(record.value(0).toString());
}

//��ȡ�ؼ��ϵ�����
void frmFormulaSetting::GetUiConText()
{
	m_pFParam->m_sNum = ui.txtNum->text();
	m_pFParam->m_sPharName = ui.txtPharName->text();
	m_pFParam->m_sLiquorName = ui.txtLiquorName->text();
	m_pFParam->m_sPillName = ui.txtPillName->text();
	m_pFParam->m_sVialNum = ui.sboxVialNum->text();
	m_pFParam->m_sLiquorVol = ui.sboxLiquorVol->text();
	m_pFParam->m_sSingleLiquorVol = ui.sboxSingleLiquorVol->text();
	m_pFParam->m_sTargetWeight = ui.sboxTargetWeight->text();
	m_pFParam->m_sShakeAngle = ui.sboxShakeAngle->text();
	m_pFParam->m_sShakeTimes = ui.sboxShakeTimes->text();
	m_pFParam->m_sWeighingError = ui.sboxWeighingError->text();
	m_pFParam->m_sPumpCapacity = ui.sboxPumpCapacity->text();
	m_pFParam->m_sExchangeTime = ui.sboxExchangeTime->text();
	m_pFParam->m_sVf = ui.sboxVf->text();
	m_pFParam->m_sVg = ui.sboxVg->text();
	m_pFParam->m_sVF1 = ui.sboxF1->text();
	m_pFParam->m_sVF2 = ui.sboxF2->text();
	m_pFParam->m_sVG1 = ui.sboxG1->text();
	m_pFParam->m_sVG2 = ui.sboxG2->text();

	m_pFParam->m_com1 = ui.sboxF3->text();
	m_pFParam->m_com3 = ui.sboxF4->text();
	m_pFParam->m_com5 = ui.sboxF5->text();
	m_pFParam->m_com2 = ui.sboxG3->text();
	m_pFParam->m_com4 = ui.sboxG4->text();
	m_pFParam->m_com6 = ui.sboxG5->text();

}

void frmFormulaSetting::closeEvent(QCloseEvent *event)
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