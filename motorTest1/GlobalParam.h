#pragma once

#include <QObject>
#include "FormulaManager.h"

extern FormulaManager  *g_formula_manager;

//����任����ֵ
extern int Distance_Change;
extern double Distance_Change3;

//�������
/*
extern int nDistance1;		//������ ��λmm
extern int Offset1;			//�������г�
extern double dVelocity1;		//�ٶ�
extern double dAccel1;			//���ٶ�
extern double dDecel1;			//���ٱ�


extern int nDistance2;		//���г�
extern int Offset2_1;			//���г�
extern int Offset2_2;
extern double dVelocity2;		//�ٶ�
extern double dAccel2;			//���ٶ�
extern double dDecel2;			//���ٱ�

						//���3�������
extern int nDistance3 ;			//���г�
extern int Offset0 ;
extern double Offset3 ;					//���г�
extern double dVelocity3 ;			//�ٶ�
extern double dAccel3 ;					//���ٶ�
extern double dDecel3 ;					//���ٱ�

									//���4�������
extern int nDistance4 ;				//���г�
extern double Offset4 ;				//���г�
extern double dVelocity4 ;				//�ٶ�
extern double dAccel4 ;					//���ٶ�
extern double dDecel4 ;					//���ٱ�

									//���5�������
extern int nDistance5 ;			//���г�
extern int Offset5 ;					//���г�
extern double dVelocity5 ;			//�ٶ�
extern double dAccel5 ;					//���ٶ�
extern double dDecel5 ;					//���ٱ�

*/

class GlobalParam : public QObject
{
	Q_OBJECT

public:
	GlobalParam(MotorManager *pMotorManager, QWidget *parent = Q_NULLPTR);  //  QObject *parent
	~GlobalParam();



public:	
//ȫ�ֱ���
	static int N;
	static int Q;//��Һ��������
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
	static uint Cali; //�������궨ֵ��ÿV��Ӧg
	static int C3;   //����Һǰ����ʱA��Ӵ�������C3
	static int C4;   //��Ͳ��ʼһ�������г�mm
	static int Velo;  //��Һ��������A��ǰ���ٶ�
	static int C5;   //עҺ�׶���Һ�������г�
	static double C6;//�ڴ�ĸҺ����Һ��עҺ��ʱ����5���г�

	//���ŵ��
	int Dis3[12] = { 210, NULL, NULL, -60,-30, 0 ,30, 60, 90, 120, 150, 180 };

	//���ŵ��������
	double Fun3Table(int a, int Zero);

	//���ŵ������ϵ��
	double Gravitycoefficient = 0.6;
	//�ĺŵ��
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


	//���뺯��
	void PushNeedle(int a);

	//���뺯��
	void PullNeedle(int b);

private:
	MotorManager *p_MotorManager;
	
};
