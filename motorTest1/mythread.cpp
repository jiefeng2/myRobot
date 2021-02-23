#include "mythread.h"
#include <QDebug>
#include "GlobalParam.h"
myThread::myThread(MOTOFun *pMOTOFun, QObject *parent) : QThread(parent)
{
	p_MOTOFun = pMOTOFun;
}



void myThread::run()
{

	p_MOTOFun->OnbtnPullLiqiud();
	p_MOTOFun->OnbtnPushLiqiud();
	p_MOTOFun->OnbtnDissolved();
	p_MOTOFun->OnbtnPullAir();
	p_MOTOFun->OnbtnPullLiqiud_2();
	p_MOTOFun->OnbtnWeight();
	p_MOTOFun->OnbtnPushLiqiud2();

}