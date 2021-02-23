#pragma once

#include <QObject>
#include "frmMainWidget.h"
#include "CFormulaParam.h"

class FormulaManager : public QObject
{
	Q_OBJECT

public:
	FormulaManager(QObject *parent);
	~FormulaManager();

//	CFormulaParam m_pFormulaParam;

//参数
	QString  s_serial_num;			//编号
	QString  s_grug_name;			//药剂名称
	QString  s_mother_liquor_name;		//母液名称
	QString  s_bottle_name;			//药瓶名称
	QString  s_vial_bottle_num;		//西林瓶数量
	QString   s_mother_liquor_cap;		//母液量
	QString  s_single_mother_liquor_cap;		//单瓶母液量
	QString  s_target_weight;					//目标重量
	QString  s_sShakeAngle;//摇晃角度
	QString  s_sShakeTimes;//摇晃次数
	QString  s_sWeighingError;//称重误差
	QString  s_sPumpCapacity;//抽气量
	QString  s_change_timer;					//交换次数
	QString  s_change_param_Vf;					//气液交换参数
	QString  s_change_param_Vg;
	QString  s_change_param_F1;
	QString  s_change_param_G1;
	QString  s_change_param_F2;
	QString  s_change_param_G2;
	QString  s_change_param_F3;
	QString  s_change_param_G3;
	QString  s_change_param_F4;
	QString  s_change_param_G4;
	QString  s_change_param_F5;
	QString  s_change_param_G5;

};
