#pragma once

//���1�������

int nDistance1;			//������ ��λmm
int Offset1;			//�������г�
double dVelocity1;		//�ٶ�
double dAccel1;			//���ٶ�
double dDecel1;			//���ٱ�

//���2�������

int nDistance2;			//���г�
int Offset2_1;			//���г�
int Offset2_2;
double dVelocity2;		//�ٶ�
double dAccel2;			//���ٶ�
double dDecel2;			//���ٱ�

//���3�������
int nDistance3;			//���г�
int Offset0;
double Offset3;			//���г�
double dVelocity3;		//�ٶ�
double dAccel3;			//���ٶ�
double dDecel3;			//���ٱ�

//���4�������
int nDistance4;			//���г�
double Offset4;			//���г�
double dVelocity4;		//�ٶ�
double dAccel4;			//���ٶ�
double dDecel4;			//���ٱ�

//���5�������
int nDistance5;			//���г�
int Offset5;			//���г�
double dVelocity5;		//�ٶ�
double dAccel5;			//���ٶ�
double dDecel5;			//���ٱ�


double VoltagetoQuality = (4.38 / 226);

//�����;���ת��ϵ��
double Qualitytomm =(1 / 0.31);


//ÿ������������г̻��߾����ת������
//int MOTO_1_Coe = (20000);
//int MOTO_2_Coe = (20000);
//double MOTO_3_Coe = (20000 / 360);
//double MOTO_4_Coe = (20000.0 / 360.0*27.0*30.0 / 30.8*90.0 / 86.0*120.0 / 119.6);
//double MOTO_5_Coe = (4000);

//ÿ������������г̻��߾����ת������
int MOTO_1_Coe = 20000;
int MOTO_2_Coe = 20000;
double MOTO_3_Coe = 20000 / 360;
double MOTO_4_Coe = 20000 / 360;
int MOTO_5_Coe = 4000;

/*
int C1 = 17;  //��ĸҺ�������ĸҺ��ml
float A1 = 24;//������ƿע��ĸҺ����Ͳǰ�����mm
float A2 = 24;//������ƿ��ȡ���Һ��Ͳǰ�����mm
float A3 = 31;//��Ͳ����ĸҺ��ʱǰ����� mm
float C2 = 18;//��ƿĸҺע������������ƿ��ע��mm
int B1 = 90;  //��һ��ĽǶ�
int B2 = 10;  //�εĴ���
float M1 = 0; //Ŀ������
float dm = 1.0; //������������
uint Cali = 0;  //�������궨ֵ��ÿV��Ӧg
int C3 = 0; //����Һǰ����ʱA��Ӵ�������C3  //������
int C4 = 0; //��Ͳ��ʼһ�������г�mm
int F1 = 14; //��Һ�����е�һ����A����˾���
int G1 = 14; //��Һ�����е�һ����B��ǰ������
int Vg = 3;  //��Һ��������A��ǰ���ٶ�
int F2 = 14; //��Һ�����е�һ����A����˾���
int G2 = 14;//��Һ�����е�һ����B��ǰ������
int Vf = 3;//��Һ��������A��ǰ���ٶ�
int F3 = 14; //��Һ�����е�һ����A����˾���
int G3 = 14;//��Һ�����е�һ����B��ǰ������
int Velo = 3;//��Һ��������A��ǰ���ٶ�
int C5 = 20;//עҺ�׶���Һ�������г�
double C6 = 262;//�ڴ�ĸҺ����Һ��עҺ��ʱ����5���г�
*/