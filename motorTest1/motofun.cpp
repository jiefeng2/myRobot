#include "motofun.h"
#include "GlobalParam.h"
#include "MOTOCommon.h"
#include <QMessageBox>
#include <QString>
//#include"frmReadFormula.h"

int MOTOFun::n = 0;
MOTOFun::MOTOFun(MotorManager *pMotorManager, ForceSensorModule *pForceSensorModule, QWidget *parent) : QObject(parent)

{
	p_MotorManager = pMotorManager;
	p_ForceSensorModule = pForceSensorModule;

	//connect(this, SIGNAL(ReadWeight()), this, SLOT(Onreadweight()));

}

MOTOFun::~MOTOFun() {
	
}

//MOTO4绝对坐标转换函数
int MOTOFun::Distance(int i, int j)  //i 为第i点的方向，j 为第j个工位
{
	int reaDis = 0;
	reaDis = Dis[i][j] - Distance_Change;
	Distance_Change = Distance_Change + reaDis;
	return reaDis;
}
//MOTO3绝对坐标转换函数
double MOTOFun::Distance3(int i)
{
	double reaDis = 0.0;
	//重力角度修正
	if (i >= 6 && i <= 12)
		reaDis = (double)Fun3Table(i, 6) + (i - 6) / 6.0 * Gravitycoefficient - Distance_Change3;
		//reaDis = (double)Fun3Table(i, 6) - Distance_Change3 +1;
	else
		reaDis = (double)Fun3Table(i, 6) + (18 - i) / 6.0 * Gravitycoefficient - Distance_Change3;
		//reaDis = (double)Fun3Table(i, 6) - Distance_Change3+1;
	Distance_Change3 = Distance_Change3 + reaDis;
	return reaDis;
}

//MOTO3函数表
double MOTOFun::Fun3Table(int a, int Zero)
{
	double reaDis = 0;
	reaDis = (a - Zero) * 30 - Distance_Change;
	if (-200 <= reaDis <= 80)
		return reaDis;
	else
		return NULL;
}

//扎针子程序
void MOTOFun::PushNeedle(int a)
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
void MOTOFun::PullNeedle(int b)
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

/*回零函数：先碰到限位开关，然后再以限位为基准行进一段距离*/
void MOTOFun::OnbtnZeroAll()
{

	//电机1回零参数

	nDistance1 = 250;				//正方向 单位mm
	Offset1 = 40;					//反方向行程
	dVelocity1 = 5;				//速度
	dAccel1 = 2;					//加速度
	dDecel1 = 2;					//减速比

									//电机2回零参数						 
	nDistance2 = 250;				//正行程
	Offset2_1 = 40;				//电机2前进一段距离以供电机1安全回零
								// Offset2_2 = 50;
	Offset2_2 = 57;//电机2碰到限位开关之后运动50mm
	dVelocity2 = 5;				//速度
	dAccel2 = 2;					//加速度
	dDecel2 = 2;					//减速比

									//电机3回零参数
	nDistance3 = 360;				//正行程    
									//Offset3 = 69.3;
									//Offset3 = 74.5;
									//Offset3 = 76.5;//碰到限位之后转动的角度
									//Offset3 = 77.5;
									//Offset3 = 77.2;
									// Offset3 = 76.6;
									//Offset3 = 74.35;
	Offset3 = 77.1;
	dVelocity3 = 0.05;				//速度
	dAccel3 = 1;					//加速度
	dDecel3 = 1;					//减速比

									//电机4回零参数
	nDistance4 = 360;				//正行程
									//Offset4 = 71.55;	
									//Offset4 = 76;//碰到限位之后转动的角度
	Offset4 = 74;
	dVelocity4 = 0.05;				//速度
	dAccel4 = 1;					//加速度
	dDecel4 = 1;					//减速比

									//电机5回零参数
	nDistance5 = 2000;				//正行程
	Offset5 = 20;					//碰到限位之后移动的距离
	dVelocity5 = 4;				//速度
	dAccel5 = 1;					//加速度
	dDecel5 = 1;					//减速比


									/*电推杆回零*/

									//电推杆上升
	p_MotorManager->WriteOutput(1, 2, false);
	p_MotorManager->WriteOutput(2, 2, false);
	p_MotorManager->WriteOutput(3, 2, false);

	Sleep(3000);
	//电推杆保持
	p_MotorManager->WriteOutput(2, 2, true);
	p_MotorManager->WriteOutput(3, 2, true);

	Sleep(1000);

	/*电推杆回零结束*/

	/*电机5回零*/

	//电机5运行至CCW处
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance5*(-1)* MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);

	Sleep(500);

	//2. 等待5号电机限位信号
	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_5_INDEX) == false))
	{
		Sleep(4);
	}

	Sleep(500);

	//电机5反行程运行至10mm处
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, Offset5*MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);
	Sleep(500);
	//判断电机5是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_5_INDEX) == true))
	{
		Sleep(4);
	}

	/*电机5回零结束*/


	/*电机1、2一起回零：电机2先碰到CCW限位，前进40mm,电机1运动碰到CCW限位，后退40mm;电机2再次触碰CCW限位，电机2前进50mm*/

	//电机2运行至CCW
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1)*MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);

	//2. 等待2号电机CCW限位信号
	Sleep(500);

	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_2_INDEX) == false))
	{
		Sleep(4);
	}

	//电机2返回40mm

	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, Offset2_1 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);

	//判断电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}


	//电机1到达CCW限位
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, nDistance1*(-1) * MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);

	Sleep(500);

	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_1_INDEX) == false))
	{
		Sleep(4);
	}
	//电机1回零35mm
	p_MotorManager->SetMotorMove(MOTOR_1_INDEX, Offset1* MOTO_1_Coe, &dVelocity1, &dAccel1, &dDecel1);
	Sleep(500);
	//判断电机是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_1_INDEX) == true))
	{
		Sleep(4);
	}

	//电机2到CCW限位
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1)*MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);

	//2. 等待2号电机CW限位信号
	Sleep(500);

	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_2_INDEX) == false)
		)
	{
		Sleep(4);
	}

	//电机2回零至25mm处
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, Offset2_2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);
	Sleep(500);

	//判断电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}

	/*电机1、2回零结束*/



	/*电机4回零*/
	Sleep(500);
	//电机4运行至CCW限位
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4*(-1)*MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);

	Sleep(500);

	//2. 等待4号电机限位信号
	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_4_INDEX) == false))
	{
		Sleep(4);
	}

	Sleep(500);


	//电机4顺时针运行至6°处
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, 3*MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);

	Sleep(500);

	//判断电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
	Sleep(4);
	}

	Sleep(1000);

	//电机4减速
	dVelocity4 = 0.01;

	//电机4逆时针运行至CCW处
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, 4*(-1)*MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);

	//2. 等待4号电机限位信号
	while ((p_MotorManager->IsInAlarmCCWLimit(MOTOR_4_INDEX) == false))
	{
	Sleep(4);
	}

	Sleep(500);

	//电机4速度还原
	dVelocity4 = 0.03;

	//1号工位运行至6点钟位置
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Offset4*MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);

	Sleep(500);

	//判断电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(500);
	/*电机4回零结束*/

	/*电机3回零*/

	//电机3运行至CW处
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, nDistance3*MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(500);

	//2. 等待3号电机限位信号
	while ((p_MotorManager->IsInAlarmCWLimit(MOTOR_3_INDEX) == false))
	{
		Sleep(4);
	}
	Sleep(500);


	dVelocity3 = 0.03;
	//电机3逆时针运行至6°处
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, 3 * (-1)*MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(500);
	//判断电机3是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(500);

	//电机3速度减小
	dVelocity3 = 0.01;
	//电机3顺时针运行至CW限位
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, 4 * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

	Sleep(500);
	//等待3号电机限位信号
	while ((p_MotorManager->IsInAlarmCWLimit(MOTOR_3_INDEX) == false))
	{
		Sleep(4);
	}

	Sleep(500);

	//电机3速度还原
	dVelocity3 = 0.03;

	//针筒指向六点钟位置
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Offset3*(-1)*MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

	Sleep(500);
	//判断电机3是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	/*电机3回零结束*/

	//坐标转换参数清零(一个保护措施，不是必须需要的)
	Distance_Change = Distance_Change3 = 0.0;

}

//上瓶函数
void MOTOFun::OnbtnUpBottle()
{
	dVelocity4 = 0.03;		//速度
	dAccel4 = 0.5;			//加速度
	dDecel4 = 0.5;			//减速度

							//int a;

	dVelocity3 = 0.1;
	dAccel3 = 3;
	dDecel3 = 3;

//电机运动
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, n)*(MOTO_4_Coe), &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(6)*(MOTO_3_Coe), &dVelocity3, &dAccel3, &dDecel3);
	Sleep(300);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))   //
	{
		Sleep(4);
	}

	
	int photoswitch = 0;
	//循环装N瓶西林瓶
	while (n < GlobalParam::N)
	{
		while ((photoswitch == 0))  //ReadInput()中的值为电机编号
		{
			Sleep(400);
			if (p_MotorManager->ReadInput(3) & 0x04)
				photoswitch = 0;
			else
				photoswitch = 1;
		}
		n++;
		photoswitch = 0;
		//第n个工位转到六点钟位置
		if (n < GlobalParam::N)
		{
			Sleep(300);
			p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, n)*(MOTO_4_Coe), &dVelocity4, &dAccel4, &dDecel4);
			p_MotorManager->SetMotorMove(MOTOR_3_INDEX, (Distance3(6))*(MOTO_3_Coe), &dVelocity3, &dAccel3, &dDecel3);
			Sleep(300);
			//检查电机4是否到位
			while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
			{
				Sleep(4);
			}

		}

	}

	//西林瓶上瓶完毕，发送提示信息
	
	
}

//从母液袋中抽液
void MOTOFun::OnbtnPullLiqiud()
{
	//电机1、电机2、电机3、电机4、电机5参数

	nDistance2 = 60;
	dVelocity2 = 6;
	dAccel2 = 2;
	dDecel2 = 2;

	nDistance3 = 60;
	dVelocity3 = 0.05;
	dAccel3 = 1;
	dDecel3 = 1;

	nDistance4 = 48;
	dVelocity4 = 0.2;
	dAccel4 = 0.5;
	dDecel4 = 0.5;

	nDistance5 = 50;
	dVelocity5 = 10;
	dAccel5 = 5;
	dDecel5 = 5;

	//1号工位转至11点，并且针筒跟随至11点：MOTO4
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	dVelocity3 = 0.1;  //让修正过程变得平缓
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(300);

	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);
	nDistance5 = GlobalParam::C6;

	dVelocity3 = 0.04;
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(13) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);				//针筒到1点钟位置
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance5 * MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);					//母液袋指定位置
	Sleep(300);

	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_5_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(300);



	//扎针
	PushNeedle(GlobalParam::A3);
	Sleep(300);

	//抽母液，A面接触至Cml
	nDistance2 = GlobalParam::Cc;
	
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);	
	emit this->SendDisMOTO2(GlobalParam::Cc);	//针栓运行至指定位置
    Sleep(300);
	
	

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);

	//退针
	PullNeedle(GlobalParam::A3);

	Sleep(300);

	//母液袋回复
	nDistance5 = (-1)*GlobalParam::C6;
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance5 * MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);		//母液袋到达指定位置
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11)* MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到11点钟位置
	while ((p_MotorManager->IsInPosition(MOTOR_5_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);

	//针筒和1号工位都指向6点钟位置，为后续操作做准备
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(6) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(300);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

}

//西林瓶注液函数
void MOTOFun::OnbtnPushLiqiud()
{

	int i = 1;  //已经完成注液的瓶子数
	
	dVelocity1 = 5;   //速度
	dAccel1 = 3;      //加速度
	dDecel1 = 3;		 //减速度

	dVelocity2 = 5;   //速度
	dAccel2 = 3;      //加速度
	dDecel2 = 3;		 //减速度

	dVelocity3 = 0.1;   //速度
	dAccel3 = 1;      //加速度
	dDecel3 = 1;		 //减速度

	nDistance4 = 360; //正方向
	dVelocity4 = 0.1;   //速度
	dAccel4 = 0.5;      //加速度
	dDecel4 = 0.5;		 //减速度

						 //扎针
	PushNeedle(GlobalParam::A1);

	//注液过程采用气液交换
	//nDistance2 =( GlobalParam::C5)+1; // C2=10
	nDistance2 = GlobalParam::C5;
	emit this->SendDisMOTO2(GlobalParam::C5);
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉针栓
	Sleep(300);
	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);


	nDistance2 = GlobalParam::C5;
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放针栓
	emit this->SendDisMOTO2(-GlobalParam::C5);
	Sleep(300);
	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);



	//拔针，针筒后退A1深：MOTO1、MOTO2
	PullNeedle(GlobalParam::A1);

	Sleep(300);

	while (i < GlobalParam::N)
	{
		//换瓶
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, i) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		//新西林瓶转至6点钟的工位
		p_MotorManager->SetMotorMove(MOTOR_3_INDEX, (Distance3(6)) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒运行到6点钟的工位

		Sleep(300);

		//检查电机3、4是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
		{
			Sleep(4);
		}

		Sleep(300);
		//扎针，针筒推入A1深：MOTO1、MOTO2
		PushNeedle(GlobalParam::A1);

		//注液，活塞前进C2ml:MOTO2
		Sleep(300);


		nDistance2 = GlobalParam::C5; // C2=10
		emit this->SendDisMOTO2(GlobalParam::C5 );
		Sleep(300);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉针栓
		Sleep(300);
		//检查电机2是否到位
		while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
		{
			Sleep(4);
		}
		Sleep(300);


		nDistance2 = GlobalParam::C5;
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放针栓
		emit this->SendDisMOTO2(-GlobalParam::C5);
		Sleep(300);
		//检查电机2是否到位
		while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
		{
			Sleep(4);
		}
		Sleep(300);

		i++;
		//如果是最后一瓶，把针筒剩余的液体都注射到瓶子中
		if (i == GlobalParam::GlobalParam::N)
		{
			nDistance2 = 20; // C2=10
			emit this->SendDisMOTO2(20);
			Sleep(300);
			p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉针栓
			Sleep(300);
			//检查电机2是否到位
			while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
			{
				Sleep(4);
			}

			Sleep(300);

			p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放针栓
			emit this->SendDisMOTO2(-20);
			Sleep(300);
			//检查电机2是否到位
			while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
			{
				Sleep(4);
			}

			Sleep(300);
		}

		//拔针，针筒后退A1深：MOTO1、MOTO2
		PullNeedle(GlobalParam::A1);
		Sleep(300);
	}


	//针筒和1号工位运行至9点钟位置，为后续操作做准备
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(8, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(9) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(300);
	//检查电机4是否运行到指定位置
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(300);

}

//摇晃溶解函数
void MOTOFun::OnbtnDissolved()
{
	//设置摇晃次数
	int i = 0;
	//电机4的参数
	dVelocity4 = 0.2;   //速度
	dAccel4 = 0.5;      //加速度
	dDecel4 = 0.5;		//减速比

	//圆盘顺时针B1度：MOTO4
	nDistance4 = GlobalParam::B1;
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4 * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);

	//检查电机4是否运行到位
	//while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)   
	{
		Sleep(4);
	}

	//开始摇晃
	while (i < GlobalParam::B2)
	{
		//圆盘逆时针2*B1°：MOTO4
		nDistance4 = 2 * GlobalParam::B1;
		Sleep(500);
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4 * (-1) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
		
		Sleep(500);


		//检查电机4是否运行到位
		while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))		
		{
			Sleep(4);
		}
		i++;

		Sleep(500);

		//圆盘顺时针2*B1°：MOTO4
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4 * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		
		Sleep(500);

		//检查电机4是否运行到位
		while(p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
		{
			Sleep(4);
		}
	}

	Sleep(500);

	nDistance4 = GlobalParam::B1;
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4 * (-1) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	
	Sleep(500);

	//检查电机4是否运行到位

	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(500);
	//继电器4上电：力传感器供电，继电器4由电机2的驱动器控制
	p_MotorManager->WriteOutput(1, 1, false);


}

//抽气函数
void MOTOFun::OnbtnPullAir()
{
	//电机2、3、4参数

	dVelocity2 = 6;   //速度
	dAccel2 = 2;      //加速度
	dDecel2 = 2;		 //减速比



	dVelocity3 = 0.1;   //速度
	dAccel3 = 0.5;      //加速度
	dDecel3 = 0.5;		 //减速比

	dVelocity4 = 0.1;   //速度
	dAccel4 = 0.5;      //加速度
	dDecel4 = 0.5;		 //减速比

	Sleep(300);
	//针筒和1号工位转至11点位置
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	dVelocity3 = 0.02; //修正过程变得平缓
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

	Sleep(300);

	//检查电机3、4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);

	//针筒指向12点钟位置
	dVelocity3 = 0.06;
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(12) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针栓运行至指定位置

	Sleep(300);

	//检查电机3是否到位
	while (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
		Sleep(4);
	}


	//针筒抽取一定量的气体
	nDistance2 = GlobalParam::C3;
	emit this->SendDisMOTO2(GlobalParam::C3);
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 *(-1)*MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(300);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	//称重：作为称重的初始值，后续的测量值要减去该值
	//称量需要保证针栓完全不接触

	nDistance2 = 5;
	emit this->SendDisMOTO2(-5);
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 *MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(300);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

//	Weight3 = p_ForceSensorModule->Gross_Weight;
	emit this->ReadWeight0();

	//称量好之后需要复位
	nDistance2 = -5;
	emit this->SendDisMOTO2(5);
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 *MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(300);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

}

//从西林瓶中抽液
void MOTOFun::OnbtnPullLiqiud_2()
{
	//设置抽取的瓶数N，已抽取的瓶数k
	int  k = 1, i = 0;

	dVelocity1 = 5;		//速度
	dAccel1 = 2;		//加速度
	dDecel1 = 2;		//减速比

	dVelocity2 = 5;		//速度
	dAccel2 = 2;		//加速度
	dDecel2 = 2;		//减速比

	dVelocity3 = 0.1;   //速度
	dAccel3 = 0.5;		//加速度
	dDecel3 = 0.5;		//减速比

	dVelocity4 = 0.2;	//速度
	dAccel4 = 0.5;		//加速度
	dDecel4 = 0.5;		//减速比

	Sleep(300);
	dVelocity3 = 0.1;
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(300);
	//检查电机3、4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	
	//针筒和1号工位到达6点位置
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(6) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(500);

	//检查电机3、4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);
	PushNeedle(GlobalParam::A2);

	//1号工位回到11点位置
	Sleep(300);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		//1号工位的11点位置
	Sleep(300);

	//检查电机3、4是否到位
	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);

	int j;//气液交换次数
	for (j = 0; j < GlobalParam::Q; j++)
	{
		//气液交换：
		//拉1：A面接触，活塞后退F1，以Vf速度
		nDistance2 = GlobalParam::F1;
		emit this->SendDisMOTO2(GlobalParam::F1);
		dVelocity2 = GlobalParam::Vf;
		Sleep(300);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 *(-1)* MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

		Sleep(300);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}

		//放1：A面接触，活塞前进G1，以Vg速度
		nDistance2 = GlobalParam::G1;
		dVelocity2 = GlobalParam::Vg;
		Sleep(300);
		emit this->SendDisMOTO2(-GlobalParam::G1);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

		Sleep(300);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}
	}


	/*
	//拉2：A面接触，活塞后退F2，以Vf速度
	nDistance2 = GlobalParam::F2;
	emit this->SendDisMOTO2(GlobalParam::F2);
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * (-1)*MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

	Sleep(500);

	//检查电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}
	//放2：A面接触，活塞前进G2，以Vg速度
	nDistance2 = GlobalParam::G2;
	emit this->SendDisMOTO2(-GlobalParam::G2);
	dVelocity2 = GlobalParam::Vg;
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

	Sleep(500);

	//检查电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}
	//拉3：A面接触，活塞后退F3，以Vf速度
	nDistance2 = GlobalParam::F3;
	emit this->SendDisMOTO2(GlobalParam::F3);
	dVelocity2 = GlobalParam::Vf;
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 *(-1)* MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

	Sleep(500);

	//检查电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}
	//放3：A面接触，活塞前进G3，以Vg速度
	nDistance2 = GlobalParam::G3;
	emit this->SendDisMOTO2(-GlobalParam::G3);
	dVelocity2 = GlobalParam::Vg;
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

	Sleep(500);

	//检查电机2是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
	{
		Sleep(4);
	}
	*/

	//拔针针筒后退A2深：MOTO1、MOTO2
	Sleep(300);
	PullNeedle(GlobalParam::A2);

	Sleep(300);

	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到11点位置

	Sleep(300);

	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
	{
		Sleep(4);
	}

	while (k < GlobalParam::N)
	{
		//针筒指向6点钟位置，k号工位指向6点钟位置
		Sleep(300);
		dVelocity3 = 0.1;
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(5, k) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
		p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(6) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

		Sleep(300);

		//检查电机3、4是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
		{
			Sleep(4);
		}

		Sleep(300);

		//扎针，针筒推进A2深
		PushNeedle(GlobalParam::A2);

		Sleep(300);

		//k号工位运行至11点位置
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, k) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);

		Sleep(300);

		//检查电机4是否到位
		while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
		{
			Sleep(4);
		}

		//气液交换：MOTO2
		int s;//气液交换次数
		for (s = 0; s < GlobalParam::Q; s++)
		{	//拉1：A面接触，活塞后退F1，以Vf速度
			nDistance2 = GlobalParam::F1;
			emit this->SendDisMOTO2(GlobalParam::F1);
			p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

			Sleep(300);

			//检查电机2是否到位
			while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
			{
				Sleep(4);
			}

			//放1：A面接触，活塞前进G1，以Vg速度
			nDistance2 = GlobalParam::G1;
			emit this->SendDisMOTO2(-GlobalParam::G1);
			p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

			Sleep(300);

			//检查电机2是否到位
			while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
			{
				Sleep(4);
			}
		}

	/*	//拉2：A面接触，活塞后退F2，以Vf速度
		nDistance2 = GlobalParam::F2;
		emit this->SendDisMOTO2(GlobalParam::F2);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

		Sleep(500);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}
		//放2：A面接触，活塞前进G2，以Vg速度
		nDistance2 = GlobalParam::G2;
		emit this->SendDisMOTO2(-GlobalParam::G2);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

		Sleep(500);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}
		//拉3：A面接触，活塞后退F3，以Vf速度
		nDistance2 = GlobalParam::F3;
		emit this->SendDisMOTO2(GlobalParam::F3);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2*(-1) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//拉

		Sleep(500);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}
		//放3：A面接触，活塞后退G3，以Vg速度
		nDistance2 = GlobalParam::G3;
		emit this->SendDisMOTO2(-GlobalParam::G3);
		p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);			//放

		Sleep(500);

		//检查电机2是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true))
		{
			Sleep(4);
		}
*/
		//拔针针筒后退A2深：MOTO1、MOTO2
		PullNeedle(GlobalParam::A2);
		Sleep(300);

		k++;


		Sleep(300);
		dVelocity3 = 0.02; //修正过程平滑化
		p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到11点位置

		Sleep(300);

		while (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
		{
			Sleep(4);
		}
		Sleep(300);
	}

	//1号工位先回11点
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		//圆盘工位1运行至11点工位
	Sleep(300);
	//检查电机4是否到位
	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);



}

//称重函数
void MOTOFun::OnbtnWeight()
{
	int i = 1;

	//电机1、2、3、4参数

	dVelocity1 = 5;   //速度
	dAccel1 = 2;      //加速度
	dDecel1 = 2;		 //减速比

	dVelocity2 = 5;   //速度
	dAccel2 = 2;      //加速度
	dDecel2 = 2;		 //减速比



	dVelocity3 = 0.1;   //速度
	dAccel3 = 0.5;      //加速度
	dDecel3 = 0.5;		 //减速比

	dVelocity4 = 0.1;   //速度
	dAccel4 = 0.5;      //加速度
	dDecel4 = 0.5;		 //减速比


						 //针筒到12点位置：MOTO3
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(12) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

	Sleep(300);

	//检查电机3是否到位
	while (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
		Sleep(4);
	}

	//力传感器称重
	//Weight4 = p_ForceSensorModule->Gross_Weight;
	emit this->ReadWeight();
	//m4 = QString("%1").arg(abs(VoltagetoQuality*(Weight4 - Weight3)));
	//ui->lblForceSensorVal_m4->setText(m4);


	/*

	while (abs(VoltagetoQuality*(Weight4-Weight3)-M1)>dm)    //abs(Weight4 - Weight3 - Weight1) > dm
	{
	//排液预处理:MOTO3、MOTO4
	///如果要到7点钟位置那么，distance就要判断了
	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒运行至11点工位

	Sleep(500);

	//检查电机3是否到位
	while (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
	Sleep(4);
	}

	Sleep(500);

	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(6, N - 1) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		//圆盘工位3运行至7点工位

	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(7) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒运行至7点工位
	Sleep(500);

	//检查电机4是否到位
	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true|| p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
	Sleep(4);
	}

	Sleep(500);



	//扎针，针筒前进A1深
	PushNeedle(A1);

	Sleep(500);

	//排液：MOTO2
	nDistance2 = ((Weight4-Weight3)*VoltagetoQuality-M1-dm)*Qualitytomm;    //往最后一个西林瓶中注入多余的液体
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, nDistance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);

	Sleep(500);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
	Sleep(4);
	}

	Sleep(500);

	//拔针，针筒前进A1深
	PullNeedle(A1);

	Sleep(500);

	//针筒回12点称重
	//1号工位先回11点
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);		//圆盘工位1运行至11点工位

	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(7) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒运行至11点工位
	Sleep(500);

	//检查电机4是否到位
	while (p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true || p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
	Sleep(4);
	}

	Sleep(500);



	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(12) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	//检查电机3是否到位

	Sleep(500);
	while (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true)
	{
	Sleep(4);
	}

	//力传感器称重
	//		Weight4 = QString("%1").arg(p_ForceSensorModule->Gross_Weight);
	//m4 = Weight4.toDouble;
	Weight4 = p_ForceSensorModule->Gross_Weight;
	nDistance3 = -150;
	}

	*/

	//继电器掉电
	p_MotorManager->WriteOutput(1, 1, true);
}

//注液到母液袋中
void MOTOFun::OnbtnPushLiqiud2()
{
	//电机1、电机2、电机3、电机4、电机5参数
	dVelocity1 = 5;
	dAccel1 = 5;
	dDecel1 = 5;

	dVelocity2 = 5;
	dAccel2 = 5;
	dDecel2 = 5;


	dVelocity3 = 0.04;
	dAccel3 = 2;
	dDecel3 = 2;

	dVelocity4 = 0.1;
	dAccel4 = 2;
	dDecel4 = 2;

	dVelocity5 = 6;
	dAccel5 = 3;
	dDecel5 = 3;

	Sleep(300);

	//1号工位转至11点，并且针筒转至11点：MOTO4
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, 0) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(300);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(300);

	/*
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);
	Sleep(500);

	//检查电机3是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
	Sleep(4);
	}

	*/

	/*p_MotorManager->SetMotorMove(MOTOR_4_INDEX, 1.3* MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
	Sleep(4);
	}
	Sleep(500);

	*/

	//上母液袋，同时针筒联动至1点：MOTO5、MOTO3
	nDistance5 = GlobalParam::C6;
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance5 * MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);		//母液袋指定位置
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(13)* MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到1点钟位置

	Sleep(300);

	//检查电机5、3是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_5_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);



	//扎针:MOTO1、MOTO2

	PushNeedle(GlobalParam::A3);

	Sleep(300);

	//注液，A面接触至Cml：MOTO2
	//double Distance2 = GlobalParam::C1 + GlobalParam::C3 + 6.5;
	//double Distance2 = GlobalParam::C1 + GlobalParam::C3 + 7.5;
	//double Distance2 = GlobalParam::C1 + GlobalParam::C3 + 14;
	double Distance2 = GlobalParam::Cc + GlobalParam::C3 + 13.4;
	emit this->SendDisMOTO2(-GlobalParam::Cc- GlobalParam::C3);
	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, Distance2 * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(300);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);

	p_MotorManager->SetMotorMove(MOTOR_2_INDEX, (-1.61) * MOTO_2_Coe, &dVelocity2, &dAccel2, &dDecel2);		//针栓运行至指定位置

	Sleep(300);

	//检查电机2是否到位
	while (p_MotorManager->IsInPosition(MOTOR_2_INDEX) == true)
	{
		Sleep(4);
	}

	Sleep(300);



	//针撤出母液袋-A3深：MOTO1、MOTO2

	PullNeedle(GlobalParam::A3);

	Sleep(300);
	//针筒回11点（归零）同时母液袋退回：MOTO3、MOTO5
	nDistance5 = -GlobalParam::C6;

	/*	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, (-1.3)* MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
	Sleep(4);
	}
	Sleep(500);
	*/



	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到11点钟位置
	p_MotorManager->SetMotorMove(MOTOR_5_INDEX, nDistance5 * MOTO_5_Coe, &dVelocity5, &dAccel5, &dDecel5);		//母液袋退回

	Sleep(300);

	//检查电机5、3是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_5_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}

	Sleep(300);

	/*	//园盘转至7点钟的位置：MOTO4
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, nDistance4 * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
	{
	Sleep(4);
	}*/

}

//去瓶函数
void MOTOFun::OnbtnDownBottle()
{


	//电机1、电机2、电机3、电机4、电机5参数
	int g = 1;

	dVelocity1 = 5;
	dAccel1 = 5;
	dDecel1 = 5;

	dVelocity2 = 10;
	dAccel2 = 5;
	dDecel2 = 5;


	dVelocity3 = 0.04;
	dAccel3 = 2;
	dDecel3 = 2;

	dVelocity4 = 0.04;
	dAccel4 = 2;
	dDecel4 = 2;

	dVelocity5 = 8;
	dAccel5 = 3;
	dDecel5 = 3;

	//去瓶预动作
	//园盘工位1转至11点钟的位置：MOTO4


	Sleep(500);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, (double)(Distance(10, GlobalParam::N - 1) - 2.2) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(11) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);		//针筒到11点钟位置
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}


	//让电机4多走7度
		Sleep(1000);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, -7 * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(1000);



	//去夹具电推杆处于工作位置：去夹具电推杆继电器2得电,继电器4失电
	//p_MotorManager->WriteOutput(1, 1, true);//电推杆1失电
	Sleep(500);
	p_MotorManager->WriteOutput(3, 2, false);//电推杆2得电
	Sleep(500);
	p_MotorManager->WriteOutput(1, 2, true);//电推杆2下放
	Sleep(5000);

	p_MotorManager->WriteOutput(3, 2, true);//电推杆2失电

											//去瓶正负行程

											//继电器1得电
	p_MotorManager->WriteOutput(2, 2, false); //电推杆1得电下行程

											  //p_MotorManager->WriteOutput(3, 2, false); //
	Sleep(2000);
	//继电器1失电
	p_MotorManager->WriteOutput(2, 2, true); //电推杆1停止
	Sleep(1000);
	//继电器2得电
	p_MotorManager->WriteOutput(2, 2, false); //电推杆1停止
	Sleep(500);
	p_MotorManager->WriteOutput(1, 2, false); //电推杆1上行程
	Sleep(4000);

	p_MotorManager->WriteOutput(2, 2, true); //电推杆1停止

	while (g < GlobalParam::N)
	{

		//第g+1个工位转至11点位置
		Sleep(3000);
		p_MotorManager->SetMotorMove(MOTOR_4_INDEX, Distance(10, GlobalParam::N - g - 1) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
		Sleep(500);
		//检查电机4是否到位
		while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true))
		{
			Sleep(4);
		}
		Sleep(1000);
		//去瓶正负行程
		//继电器1得电
		p_MotorManager->WriteOutput(2, 2, false); //电推杆1向下
		p_MotorManager->WriteOutput(1, 2, true);
		Sleep(2000);
		//继电器1失电
		p_MotorManager->WriteOutput(2, 2, true); //停止
		Sleep(1000);
		//继电器2得电
		p_MotorManager->WriteOutput(2, 2, false); //上行程
		p_MotorManager->WriteOutput(1, 2, false);

		Sleep(2000);
		p_MotorManager->WriteOutput(2, 2, true); //电推杆1失电
		g++;

	}

	dVelocity4 = 0.09;
	//圆盘复位
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, (Distance(5, 0) + 2) * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	p_MotorManager->SetMotorMove(MOTOR_3_INDEX, Distance3(6) * MOTO_3_Coe, &dVelocity3, &dAccel3, &dDecel3);

	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}


	//让电机4回走7度
	dVelocity4 = 0.01;
	Sleep(1000);
	p_MotorManager->SetMotorMove(MOTOR_4_INDEX, 7 * MOTO_4_Coe, &dVelocity4, &dAccel4, &dDecel4);
	Sleep(500);
	//检查电机4是否到位
	while ((p_MotorManager->IsInPosition(MOTOR_4_INDEX) == true) || (p_MotorManager->IsInPosition(MOTOR_3_INDEX) == true))
	{
		Sleep(4);
	}
	Sleep(1000);



	//电推杆2复位
	p_MotorManager->WriteOutput(3, 2, false);

	Sleep(3000);

	p_MotorManager->WriteOutput(3, 2, true);//继电器3失电
	Sleep(3000);

}


