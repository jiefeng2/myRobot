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

//����
	QString  s_serial_num;			//���
	QString  s_grug_name;			//ҩ������
	QString  s_mother_liquor_name;		//ĸҺ����
	QString  s_bottle_name;			//ҩƿ����
	QString  s_vial_bottle_num;		//����ƿ����
	QString   s_mother_liquor_cap;		//ĸҺ��
	QString  s_single_mother_liquor_cap;		//��ƿĸҺ��
	QString  s_target_weight;					//Ŀ������
	QString  s_sShakeAngle;//ҡ�νǶ�
	QString  s_sShakeTimes;//ҡ�δ���
	QString  s_sWeighingError;//�������
	QString  s_sPumpCapacity;//������
	QString  s_change_timer;					//��������
	QString  s_change_param_Vf;					//��Һ��������
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
