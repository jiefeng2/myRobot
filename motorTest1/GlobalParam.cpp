#include "GlobalParam.h"


FormulaManager *g_formula_manager;

//int N = 0;
double Distance_Change3 = 0.0;
int Distance_Change = 0;



int GlobalParam::N = 0;
int GlobalParam::Q = 0;
int GlobalParam::C1 = 0;
float GlobalParam::Cc = 0;
float GlobalParam::A1 = 24;                                           //������ƿע��ĸҺ����Ͳǰ�����mm
float GlobalParam::A2 = 24;                                           //������ƿ��ȡ���Һ��Ͳǰ�����mm
float GlobalParam::A3 = 31;                                           //��Ͳ����ĸҺ��ʱǰ����� mm
float GlobalParam::C2 = 0;
int GlobalParam::B1 = 0;
int GlobalParam::B2 = 0;
float GlobalParam::M1 = 0;
float GlobalParam::dm = 0;
uint GlobalParam::Cali = 0;//�������궨ֵ��ÿV��Ӧg
int GlobalParam::C3 = 0; //����Һǰ����ʱA��Ӵ�������C3
int GlobalParam::C4 = 0; //��Ͳ��ʼһ�������г�mm
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
double GlobalParam::C6 = 262;//�ڴ�ĸҺ����Һ��עҺ��ʱ����5���г�


/*
int nDistance1;		//������ ��λmm
int Offset1;			//�������г�
double dVelocity1;		//�ٶ�
double dAccel1;			//���ٶ�
double dDecel1;			//���ٱ�


int nDistance2;		//���г�
int Offset2_1;			//���г�
int Offset2_2;
double dVelocity2;		//�ٶ�
double dAccel2;			//���ٶ�
double dDecel2;			//���ٱ�

						//���3�������
int nDistance3;			//���г�
int Offset0;
double Offset3;					//���г�
double dVelocity3;			//�ٶ�
double dAccel3;					//���ٶ�
double dDecel3;					//���ٱ�

								//���4�������
int nDistance4;				//���г�
double Offset4;				//���г�
double dVelocity4;				//�ٶ�
double dAccel4;					//���ٶ�
double dDecel4;					//���ٱ�

								//���5�������
int nDistance5;			//���г�
int Offset5;					//���г�
double dVelocity5;			//�ٶ�
double dAccel5;					//���ٶ�
double dDecel5;					//���ٱ�
*/


GlobalParam::GlobalParam(MotorManager *pMotorManager, QWidget *parent)
	: QObject(parent)
{
	p_MotorManager = pMotorManager;
}

GlobalParam::~GlobalParam()
{
}


//MOTO4��������ת������
int GlobalParam::Distance(int i, int j)  //i Ϊ��i��ķ���j Ϊ��j����λ
{
	int reaDis = 0;
	reaDis = Dis[i][j] - Distance_Change;
	Distance_Change = Distance_Change + reaDis;
	return reaDis;
}
//MOTO3��������ת������
double GlobalParam::Distance3(int i)
{
	double reaDis = 0.0;
	//�����Ƕ�����
	if (i >= 6 && i <= 12)
		reaDis = (double)Fun3Table(i, 6) + (i - 6) / 6.0 * Gravitycoefficient - Distance_Change3;
	else
		reaDis = (double)Fun3Table(i, 6) + (18 - i) / 6.0 * Gravitycoefficient - Distance_Change3;
	Distance_Change3 = Distance_Change3 + reaDis;
	return reaDis;
}

//MOTO3������
double GlobalParam::Fun3Table(int a, int Zero)
{
	double reaDis = 0;
	reaDis = (a - Zero) * 30 - Distance_Change;
	if (-200 <= reaDis <= 80)
		return reaDis;
	else
		return NULL;
}



//�����ӳ���
void GlobalParam::PushNeedle(int a)
{
	//����:MOTO1��MOTO2

	int nDistance1;		//���г̷��� ��λmm
	double dVelocity1 = 5;			//�ٶ�
	double dAccel1 = 20;       //���ٶ�
	double dDecel1 = 20;		 //���ٱ�

	int nDistance2;		//���г�
	double dVelocity2 = 5;			//�ٶ�
	double dAccel2 = 20;				//���ٶ�
	double dDecel2 = 20;				//���ٱ�

	int MOTO_1_Coe = (20000);
	int MOTO_2_Coe = (20000);


	nDistance1 = nDistance2 = a;

	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1*(-1) * MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);		//��Ͳ������ָ��λ��
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//��˨������ָ��λ��

	Sleep(500);

	//�����1��2�Ƿ�λ
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
	{
		Sleep(4);
	}

}

//�����ӳ���
void GlobalParam::PullNeedle(int b)
{
	//����:MOTO1��MOTO2

	int nDistance1;		//���г̷��� ��λmm
	double dVelocity1 = 5;     //�ٶ�
	double dAccel1 = 20;       //���ٶ�
	double dDecel1 = 20;		 //���ٱ�

	int nDistance2;		//���г�
	int Offset2 = 10;			//���г�
	double dVelocity2 = 5;			//�ٶ�
	double dAccel2 = 20;				//���ٶ�
	double dDecel2 = 20;				//���ٱ�

	int MOTO_1_Coe = (20000);
	int MOTO_2_Coe = (20000);

	nDistance1 = nDistance2 = b;
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1 * MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);		//��Ͳ������ָ��λ��
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//��˨������ָ��λ��

	Sleep(500);

	//�����1��2�Ƿ�λ
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
	{
		Sleep(4);
	}
}