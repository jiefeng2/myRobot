#include "GlobalParam.h"


FormulaManager *g_formula_manager;

//int N = 0;
double Distance_Change3 = 0.0;
int Distance_Change = 0;



int GlobalParam::N = 0;
int GlobalParam::Q = 0;
int GlobalParam::C1 = 0;
float GlobalParam::Cc = 0;
float GlobalParam::A1 = 24;                                           //往西林瓶注射母液中针筒前进深度mm
float GlobalParam::A2 = 24;                                           //从西林瓶抽取混合液针筒前进深度mm
float GlobalParam::A3 = 31;                                           //针筒插入母液袋时前进深度 mm
float GlobalParam::C2 = 0;
int GlobalParam::B1 = 0;
int GlobalParam::B2 = 0;
float GlobalParam::M1 = 0;
float GlobalParam::dm = 0;
uint GlobalParam::Cali = 0;//传感器标定值，每V对应g
int GlobalParam::C3 = 0; //抽混合液前称重时A面接触后退至C3
int GlobalParam::C4 = 0; //针筒初始一次推拉行程mm
int GlobalParam::F1 = 0;
int GlobalParam::G1 = 0;
int GlobalParam::Vg = 0;
int GlobalParam::F2 = 0;
int GlobalParam::G2 = 0;
int GlobalParam::Vf = 0;
int GlobalParam::com1  = 0;
int GlobalParam::com2 = 0;

int GlobalParam::com3 = 0;
int GlobalParam::com4= 0;
int GlobalParam::com5 = 0;
QString GlobalParam::com6 = 0;

int GlobalParam::Velo = 0;
int GlobalParam::C5 = 0;
double GlobalParam::C6 = 262;//在从母液带抽液和注液的时候电机5的行程


/*
int nDistance1;		//正方向 单位mm
int Offset1;			//反方向行程
double dVelocity1;		//速度
double dAccel1;			//加速度
double dDecel1;			//减速比


int nDistance2;		//正行程
int Offset2_1;			//反行程
int Offset2_2;
double dVelocity2;		//速度
double dAccel2;			//加速度
double dDecel2;			//减速比

						//电机3回零参数
int nDistance3;			//正行程
int Offset0;
double Offset3;					//反行程
double dVelocity3;			//速度
double dAccel3;					//加速度
double dDecel3;					//减速比

								//电机4回零参数
int nDistance4;				//正行程
double Offset4;				//反行程
double dVelocity4;				//速度
double dAccel4;					//加速度
double dDecel4;					//减速比

								//电机5回零参数
int nDistance5;			//正行程
int Offset5;					//反行程
double dVelocity5;			//速度
double dAccel5;					//加速度
double dDecel5;					//减速比
*/


GlobalParam::GlobalParam(MotorManager *pMotorManager, QWidget *parent)
	: QObject(parent)
{
	p_MotorManager = pMotorManager;
}

GlobalParam::~GlobalParam()
{
}


//MOTO4绝对坐标转换函数
int GlobalParam::Distance(int i, int j)  //i 为第i点的方向，j 为第j个工位
{
	int reaDis = 0;
	reaDis = Dis[i][j] - Distance_Change;
	Distance_Change = Distance_Change + reaDis;
	return reaDis;
}
//MOTO3绝对坐标转换函数
double GlobalParam::Distance3(int i)
{
	double reaDis = 0.0;
	//重力角度修正
	if (i >= 6 && i <= 12)
		reaDis = (double)Fun3Table(i, 6) + (i - 6) / 6.0 * Gravitycoefficient - Distance_Change3;
	else
		reaDis = (double)Fun3Table(i, 6) + (18 - i) / 6.0 * Gravitycoefficient - Distance_Change3;
	Distance_Change3 = Distance_Change3 + reaDis;
	return reaDis;
}

//MOTO3函数表
double GlobalParam::Fun3Table(int a, int Zero)
{
	double reaDis = 0;
	reaDis = (a - Zero) * 30 - Distance_Change;
	if (-200 <= reaDis <= 80)
		return reaDis;
	else
		return NULL;
}



//扎针子程序
void GlobalParam::PushNeedle(int a)
{
	//扎针:MOTO1、MOTO2

	int nDistance1;		//正行程方向 单位mm
	double dVelocity1 = 5;			//速度
	double dAccel1 = 20;       //加速度
	double dDecel1 = 20;		 //减速比

	int nDistance2;		//正行程
	double dVelocity2 = 5;			//速度
	double dAccel2 = 20;				//加速度
	double dDecel2 = 20;				//减速比

	int MOTO_1_Coe = (20000);
	int MOTO_2_Coe = (20000);


	nDistance1 = nDistance2 = a;

	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1*(-1) * MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);		//针筒运行至指定位置
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(500);

	//检查电机1、2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
	{
		Sleep(4);
	}

}

//拔针子程序
void GlobalParam::PullNeedle(int b)
{
	//扎针:MOTO1、MOTO2

	int nDistance1;		//正行程方向 单位mm
	double dVelocity1 = 5;     //速度
	double dAccel1 = 20;       //加速度
	double dDecel1 = 20;		 //减速比

	int nDistance2;		//正行程
	int Offset2 = 10;			//反行程
	double dVelocity2 = 5;			//速度
	double dAccel2 = 20;				//加速度
	double dDecel2 = 20;				//减速比

	int MOTO_1_Coe = (20000);
	int MOTO_2_Coe = (20000);

	nDistance1 = nDistance2 = b;
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1 * MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);		//针筒运行至指定位置
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(500);

	//检查电机1、2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
	{
		Sleep(4);
	}
}