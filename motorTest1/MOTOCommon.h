#pragma once

//电机1回零参数

int nDistance1;			//正方向 单位mm
int Offset1;			//反方向行程
double dVelocity1;		//速度
double dAccel1;			//加速度
double dDecel1;			//减速比

//电机2回零参数

int nDistance2;			//正行程
int Offset2_1;			//反行程
int Offset2_2;
double dVelocity2;		//速度
double dAccel2;			//加速度
double dDecel2;			//减速比

//电机3回零参数
int nDistance3;			//正行程
int Offset0;
double Offset3;			//反行程
double dVelocity3;		//速度
double dAccel3;			//加速度
double dDecel3;			//减速比

//电机4回零参数
int nDistance4;			//正行程
double Offset4;			//反行程
double dVelocity4;		//速度
double dAccel4;			//加速度
double dDecel4;			//减速比

//电机5回零参数
int nDistance5;			//正行程
int Offset5;			//反行程
double dVelocity5;		//速度
double dAccel5;			//加速度
double dDecel5;			//减速比


double VoltagetoQuality = (4.38 / 226);

//质量和距离转换系数
double Qualitytomm =(1 / 0.31);


//每个电机脉冲与行程或者距离的转换比例
//int MOTO_1_Coe = (20000);
//int MOTO_2_Coe = (20000);
//double MOTO_3_Coe = (20000 / 360);
//double MOTO_4_Coe = (20000.0 / 360.0*27.0*30.0 / 30.8*90.0 / 86.0*120.0 / 119.6);
//double MOTO_5_Coe = (4000);

//每个电机脉冲与行程或者距离的转换比例
int MOTO_1_Coe = 20000;
int MOTO_2_Coe = 20000;
double MOTO_3_Coe = 20000 / 360;
double MOTO_4_Coe = 20000 / 360;
int MOTO_5_Coe = 4000;

/*
int C1 = 17;  //从母液袋抽出的母液量ml
float A1 = 24;//往西林瓶注射母液中针筒前进深度mm
float A2 = 24;//从西林瓶抽取混合液针筒前进深度mm
float A3 = 31;//针筒插入母液袋时前进深度 mm
float C2 = 18;//单瓶母液注射量（假设整瓶抽注）mm
int B1 = 90;  //晃一半的角度
int B2 = 10;  //晃的次数
float M1 = 0; //目标重量
float dm = 1.0; //称重容许的误差
uint Cali = 0;  //传感器标定值，每V对应g
int C3 = 0; //抽混合液前称重时A面接触后退至C3  //抽气量
int C4 = 0; //针筒初始一次推拉行程mm
int F1 = 14; //气液交换中第一次拉A面后退距离
int G1 = 14; //气液交换中第一次推B面前进距离
int Vg = 3;  //气液交换中推A面前进速度
int F2 = 14; //气液交换中第一次拉A面后退距离
int G2 = 14;//气液交换中第一次推B面前进距离
int Vf = 3;//气液交换中推A面前进速度
int F3 = 14; //气液交换中第一次拉A面后退距离
int G3 = 14;//气液交换中第一次推B面前进距离
int Velo = 3;//气液交换中推A面前进速度
int C5 = 20;//注液阶段气液交换的行程
double C6 = 262;//在从母液带抽液和注液的时候电机5的行程
*/