#pragma once
#include "qstring.h"
#include "FsmState2.h"

#ifdef WIN32 
#pragma execution_character_set("utf-8") 
#endif

#define  DISTANCE_RATE		(100)

//Ȩ�޶���
#define		SYS_USR_RIGHT		(7)		//��������ԱȨ��
#define		USR_RIGHT			(3)		//����ԱȨ��
#define		OPERATOR_RIGHT		(1)		//����ԱȨ��




//������
enum
{
	FRM_READ_FORMULA = 1,
	FRM_SELF_TEST,
	FRM_PREPARE_DRUG,
	FRM_DISPENSE_PROCESS,
	FRM_DISPENSE_FINISH,
	FRM_RECIPE_SETTING,
	FRM_SYSTEMSETTING,
	FRM_ACCOUNTMANAGER,
	FRM_LOGIN,
	FRM_FORMULA_SETTING,
	FRM_WORK_LOG,
	FRM_SYSTEMPARAM_SETTING,
};


//�¼����
enum
{
	GO_NEXT_BTN_TYPE = 1,
	GO_BACK_BTN_TYPE,
	GO_EXIT_BTN_TYPE,
	SYSTEM_PARAM_SETTING_BTN_TYPE,
	ACCOUNT_MANAGEMENT_BTN_TYPE,
	CLOSE_WIGDET,
	LOGIN_SUCESS,
	GO_FORMULA_SETTING,				//ҩ������
	GO_WORK_LOG_BROWSE					//������־���
};

//������
enum
{
	MOTOR_1_INDEX = 0,
	MOTOR_2_INDEX,
	MOTOR_3_INDEX,
	MOTOR_4_INDEX,
	MOTOR_5_INDEX,

};

//��������ź�����
enum 
{
	SENSOR_GET_VALUE = 0,
	SENSOR_SET_FILTER,
	SENSOR_SET_ZERO,
};


//���ݿ�user��Ӧ������
enum
{
	ID = 0,
	usrid,
	usrname,
	psword,
	rights
};










