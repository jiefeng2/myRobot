#pragma once

#include <QWidget>
#include "ui_frmDispenseProcess.h"
#include "QCloseEvent"
#include "motofun.h"
#include "mythread.h"
#include <QThread>
#include "cthermometer.h"


class frmDispenseProcess : public QWidget
{
	Q_OBJECT

public:
	frmDispenseProcess(myThread *pmyThread, ForceSensorModule *pForceSensorModule, QWidget *parent = Q_NULLPTR);
	~frmDispenseProcess();

	ForceSensorModule *p_ForceSensorModule;

	int weight0, weight1;
	
	int sum = 0; //��˨��λ�ñ�ʾ

	private slots:
	void OnbtnGoNext();
	void OnbtnProcess();
	void Uisetfun();
	void dealSignal();
	void UiDisMOTO2(int value);
	void ReadForceSensor0();
	void ReadForceSensor();

private:
	Ui::frmDispenseProcess ui;
	void closeEvent(QCloseEvent *event);
	myThread *MyT;

	MOTOFun *p_MOTOFun;

	CThermometer* thermometer;//��Ͳ�̶���ʾ

signals:
	void startThread();//�������̵߳��ź�
	void btnClickedSignal(int widgetindex, int btntype);
};
