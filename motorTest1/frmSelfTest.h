#pragma once

#include <QWidget>
#include "ui_frmSelfTest.h"
#include "common.h"
#include "motofun.h"
#include "QCloseEvent"

class frmSelfTest : public QWidget
{
	Q_OBJECT

public:
	frmSelfTest(MOTOFun *pMOTOFun, QWidget *parent = Q_NULLPTR);
	~frmSelfTest();

	bool IsMotorOpen = false;

private slots:
	void OnbtnGoNext();
	void OnbtnGoBack();

	void OnbtnOpenPort();


	void OnbtnStartSelfTest();

private:
	Ui::frmSelfTest ui;
	void closeEvent(QCloseEvent *event);

	MOTOFun *p_MOTOFun;

signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
