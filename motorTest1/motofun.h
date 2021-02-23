#pragma once
#include <QObject>
#include "ForceSensorModule.h"
#include "MotorManager.h"


class MOTOFun : public QObject {
	Q_OBJECT

public:
	MOTOFun(MotorManager *pMotorManager, ForceSensorModule *pForceSensorModule, QWidget *parent = Q_NULLPTR);
	~MOTOFun();

public:
	MotorManager *p_MotorManager;
	ForceSensorModule *p_ForceSensorModule;

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

	static int n ;//已经上瓶的个数

	//扎针函数
	void PushNeedle(int a);

	//拔针函数
	void PullNeedle(int b);


	//回零 五轴
	void OnbtnZeroAll();

	//不需要单个回零
	//回零 MOTO3
	//void OnbtnMOTO3toZERO();
	//回零 MOTO4
	//void OnbtnMOTO4toZERO();
	
	
	
	//上瓶
	void OnbtnUpBottle();

	//从母液袋中抽液
	void OnbtnPullLiqiud();


	//西林瓶注液
	void OnbtnPushLiqiud();

	//摇晃溶解
	void OnbtnDissolved();

	//抽气
	void OnbtnPullAir();

	//从西林瓶中抽液
	void OnbtnPullLiqiud_2();

	//称重函数
	void OnbtnWeight();

	//注液2函数
	void OnbtnPushLiqiud2();

	//去瓶函数
	void OnbtnDownBottle();

    //测试函数
	void test();

private slots:
//	void Onreadweight();


private:


	signals :
		void ReadWeight0();
		void SendDisMOTO2(int);
		void ReadWeight();

	
};
