#pragma once
#include "qstring.h"
#include "FsmState2.h"

#ifdef WIN32 
#pragma execution_character_set("utf-8") 
#endif

#define  DISTANCE_RATE		(100)

//权限定义
#define		SYS_USR_RIGHT		(7)		//超级管理员权限
#define		USR_RIGHT			(3)		//管理员权限
#define		OPERATOR_RIGHT		(1)		//操作员权限




//界面编号
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


//事件编号
enum
{
	GO_NEXT_BTN_TYPE = 1,
	GO_BACK_BTN_TYPE,
	GO_EXIT_BTN_TYPE,
	SYSTEM_PARAM_SETTING_BTN_TYPE,
	ACCOUNT_MANAGEMENT_BTN_TYPE,
	CLOSE_WIGDET,
	LOGIN_SUCESS,
	GO_FORMULA_SETTING,				//药方设置
	GO_WORK_LOG_BROWSE					//工作日志浏览
};

//电机编号
enum
{
	MOTOR_1_INDEX = 0,
	MOTOR_2_INDEX,
	MOTOR_3_INDEX,
	MOTOR_4_INDEX,
	MOTOR_5_INDEX,

};

//传感类的信号类型
enum 
{
	SENSOR_GET_VALUE = 0,
	SENSOR_SET_FILTER,
	SENSOR_SET_ZERO,
};


//数据库user对应的列名
enum
{
	ID = 0,
	usrid,
	usrname,
	psword,
	rights
};










