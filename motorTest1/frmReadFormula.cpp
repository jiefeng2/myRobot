#include "frmReadFormula.h"
#include "App.h"
#include "QSqlRecord"
#include "GlobalParam.h"
#include "QMessageBox"

frmReadFormula::frmReadFormula(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("配药界面1 ---读取配方"));
//	setWindowModality(Qt::ApplicationModal);
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	ui.tbvwFormula->setEditTriggers(QAbstractItemView::NoEditTriggers);

	formulamodel = new QSqlTableModel(this);
	formulamodel->setTable("formulatable");
	formulamodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//选取整个表的所有行
	formulamodel->select();
	formulamodel->removeColumn(0);
//	formulamodel->setHeaderData(0, Qt::Horizontal, tr("序号")); //修改列名
	formulamodel->setHeaderData(0, Qt::Horizontal, tr("编号")); //修改列名
	formulamodel->setHeaderData(1, Qt::Horizontal, tr("药剂名称"));
	formulamodel->setHeaderData(2, Qt::Horizontal, tr("母液名称"));
	formulamodel->setHeaderData(3, Qt::Horizontal, tr("药瓶名称"));
	formulamodel->setHeaderData(4, Qt::Horizontal, tr("西林瓶数量"));
	formulamodel->setHeaderData(5, Qt::Horizontal, tr("母液量(ml)"));
	formulamodel->setHeaderData(6, Qt::Horizontal, tr("单瓶母液量(ml)"));
	formulamodel->setHeaderData(7, Qt::Horizontal, tr("目标重量(g)"));

	formulamodel->setHeaderData(8, Qt::Horizontal, tr("摇晃角度（度）"));
	formulamodel->setHeaderData(9, Qt::Horizontal, tr("摇晃次数（次）"));
	formulamodel->setHeaderData(10, Qt::Horizontal, tr("称重误差（g）"));
	formulamodel->setHeaderData(11, Qt::Horizontal, tr("抽气量（ml）"));
	formulamodel->setHeaderData(12, Qt::Horizontal, tr("气液交换次数"));
	formulamodel->setHeaderData(13, Qt::Horizontal, tr("气液抽速Vf"));
	formulamodel->setHeaderData(14, Qt::Horizontal, tr("气液推速Vg"));
	formulamodel->setHeaderData(15, Qt::Horizontal, tr("气液抽距F1"));
	formulamodel->setHeaderData(16, Qt::Horizontal, tr("气液推距G1"));

	formulamodel->setHeaderData(17, Qt::Horizontal, tr("气液抽距F2"));
	formulamodel->setHeaderData(18, Qt::Horizontal, tr("气液抽距G2"));
	formulamodel->setHeaderData(19, Qt::Horizontal, tr("电机1串口"));
	formulamodel->setHeaderData(20, Qt::Horizontal, tr("电机2串口"));
	formulamodel->setHeaderData(21, Qt::Horizontal, tr("电机3串口"));
	formulamodel->setHeaderData(22, Qt::Horizontal, tr("电机4串口"));
	
	
	formulamodel->setHeaderData(23, Qt::Horizontal, tr("电机5串口"));
	formulamodel->setHeaderData(24, Qt::Horizontal, tr("力传感器"));


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

	     GlobalParam::N = g_formula_manager->s_vial_bottle_num.toInt();    //西林瓶的数量
		 GlobalParam::Q = g_formula_manager->s_change_timer.toInt();       //气液交换次数
		 GlobalParam::C1 = g_formula_manager->s_mother_liquor_cap.toInt(); //从母液袋抽出的母液量ml
		 GlobalParam::Cc = 9.6 + GlobalParam::N *GlobalParam::C1;          //针筒抽母液袋距离
		 GlobalParam::A1 = 24;                                             //往西林瓶注射母液中针筒前进深度mm
		 GlobalParam::A2 = 22;                                             //从西林瓶抽取混合液针筒前进深度mm
		 GlobalParam::A3 = 31;                                             //针筒插入母液袋时前进深度 mm
		 GlobalParam::C2 = g_formula_manager->s_single_mother_liquor_cap.toFloat();  //单瓶母液注射量（假设整瓶抽注）mm
		 GlobalParam::B1 = g_formula_manager->s_sShakeAngle.toInt();                   //晃一半的角度
		 GlobalParam::B2 = g_formula_manager->s_sShakeTimes.toInt();                   //晃的次数
		 GlobalParam::M1 = g_formula_manager->s_target_weight.toFloat();  //目标重量
		 GlobalParam::dm = g_formula_manager->s_sWeighingError.toFloat(); //称重容许的误差
		 GlobalParam::Cali = 0;//传感器标定值，每V对应g
		 GlobalParam::C3 = 0; //抽混合液前称重时A面接触后退至C3
		 GlobalParam::C4 = 0; //针筒初始一次推拉行程mm
		 GlobalParam::F1 = g_formula_manager->s_change_param_F1.toInt();//气液交换中第一次拉A面后退距离
		 GlobalParam::G1 = g_formula_manager->s_change_param_G1.toInt();//气液交换中第一次推B面前进距离
		 GlobalParam::Vg = g_formula_manager->s_change_param_Vg.toInt();//气液交换中推A面前进速度
		 GlobalParam::F2 = g_formula_manager->s_change_param_F2.toInt();//气液交换中第二次拉A面后退距离
		 GlobalParam::G2 = g_formula_manager->s_change_param_G2.toInt();//气液交换中第二次推B面前进距离
		 GlobalParam::Vf = g_formula_manager->s_change_param_Vf.toInt();//气液交换中推A面前进速度

		 GlobalParam::com1 = g_formula_manager->s_change_param_F3.toInt();
		 GlobalParam::com2 = g_formula_manager->s_change_param_G3.toInt();		
		 GlobalParam::com3 = g_formula_manager->s_change_param_F4.toInt();
		 GlobalParam::com4 = g_formula_manager->s_change_param_G4.toInt();
		 GlobalParam::com5 = g_formula_manager->s_change_param_F5.toInt();
		 GlobalParam::com6 = g_formula_manager->s_change_param_G5;


		 GlobalParam::Velo = 3;  //气液交换中推A面前进速度
		 GlobalParam::C5 = 20;   //注液阶段气液交换的行程
		 GlobalParam::C6 = 241;//在从母液带抽液和注液的时候电机5的行程 
	}
	else
	{
		QMessageBox::information(this, tr("请选择药方"), tr("请选择药方"), QMessageBox::Ok);
	}
}


//更新药方表格显示
void frmReadFormula::UpdateFormulaDisplay()
{
	//选取整个表的所有行
	formulamodel->select();
}


void frmReadFormula::closeEvent(QCloseEvent *event)
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






