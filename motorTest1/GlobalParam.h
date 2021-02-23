#pragma once

#include <QObject>
#include "FormulaManager.h"

extern FormulaManager  *g_formula_manager;

//坐标变换保留值
extern int Distance_Change;
extern double Distance_Change3;

//电机参数
/*
extern int nDistance1;		//正方向 单位mm
extern int Offset1;			//反方向行程
extern double dVelocity1;		//速度
extern double dAccel1;			//加速度
extern double dDecel1;			//减速比


extern int nDistance2;		//正行程
extern int Offset2_1;			//反行程
extern int Offset2_2;
extern double dVelocity2;		//速度
extern double dAccel2;			//加速度
extern double dDecel2;			//减速比

						//电机3回零参数
extern int nDistance3 ;			//正行程
extern int Offset0 ;
extern double Offset3 ;					//反行程
extern double dVelocity3 ;			//速度
extern double dAccel3 ;					//加速度
extern double dDecel3 ;					//减速比

									//电机4回零参数
extern int nDistance4 ;				//正行程
extern double Offset4 ;				//反行程
extern double dVelocity4 ;				//速度
extern double dAccel4 ;					//加速度
extern double dDecel4 ;					//减速比

									//电机5回零参数
extern int nDistance5 ;			//正行程
extern int Offset5 ;					//反行程
extern double dVelocity5 ;			//速度
extern double dAccel5 ;					//加速度
extern double dDecel5 ;					//减速比

*/

class GlobalParam : public QObject
{
	Q_OBJECT

public:
	GlobalParam(MotorManager *pMotorManager, QWidget *parent = Q_NULLPTR);  //  QObject *parent
	~GlobalParam();



public:	
//全局变量
	static int N;
	static int Q;//气液交换次数
	static int C1;
	static float Cc;
	static float C2;
	static int B1;
	static int B2;
	static float M1;
	static float dm;
	static int F1;
	static int G1;
	static int Vg;
	static int F2;
	static int G2;
	static int Vf;
	
	static int com1;
	static int com2;

	static int com3;
	static int com4;
	static int com5;
	static QString com6;



	static float A1;
	static float A2;
	static float A3;
	static uint Cali; //传感器标定值，每V对应g
	static int C3;   //抽混合液前称重时A面接触后退至C3
	static int C4;   //针筒初始一次推拉行程mm
	static int Velo;  //气液交换中推A面前进速度
	static int C5;   //注液阶段气液交换的行程
	static double C6;//在从母液带抽液和注液的时候电机5的行程

	//三号电机
	int Dis3[12] = { 210, NULL, NULL, -60,-30, 0 ,30, 60, 90, 120, 150, 180 };

	//三号电机函数表
	double Fun3Table(int a, int Zero);

	//三号电机重力系数
	double Gravitycoefficient = 0.6;
	//四号电机
	int Dis[12][6] = { { 210, NULL, -78, -22, -14, 50 },
	{ NULL, NULL, -48, 8, 44, 80 },
	{ NULL, -54, -18, 38, 74, 110 },
	{ -60, -24, 12, 68, 104, 140 },
	{ -30, 6, 42, 98, 134, 170 },
	{ 0, 36, 72, 128, 164, 200 },
	{ 30, 66, 102, 158, 194, 230 },
	{ 60, 96, 132, 188, 224, NULL },
	{ 90, 126, 162, 218, NULL, -70 },
	{ 120, 156, 192, NULL, -76, -4 },
	{ 150, 186, 222, -82, -46, -10 },
	{ 180, 216, NULL, -52, -16, 20 }
	};


	double Distance3(int i);
	int Distance(int i, int j);


	int Weight0 = 0, Weight1, Weight2, Weight3, Weight4;
	QString m1, m2, m3, m4;


	//扎针函数
	void PushNeedle(int a);

	//拔针函数
	void PullNeedle(int b);

private:
	MotorManager *p_MotorManager;
	
};
