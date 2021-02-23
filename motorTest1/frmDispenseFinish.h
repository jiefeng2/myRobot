#pragma once

#include <QWidget>
#include "ui_frmDispenseFinish.h"
#include "QCloseEvent"
#include "motofun.h"

class frmDispenseFinish : public QWidget
{
	Q_OBJECT

public:
	frmDispenseFinish(MOTOFun *pMOTOFun, QWidget *parent = Q_NULLPTR);
	~frmDispenseFinish();

	private slots:
	void OnbtnGoExit();
	void OnbtndBottle();
	void OnbtndMoliquorbag();
	void OnbtndInjector();

private:
	Ui::frmDispenseFinish ui;
	void closeEvent(QCloseEvent *event);

	MOTOFun *p_MOTOFun;

signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
