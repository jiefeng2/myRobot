#pragma once

#include <QWidget>
#include "ui_frmPrepareDrug.h"
#include "QCloseEvent"
#include "motofun.h"

class frmPrepareDrug : public QWidget
{
	Q_OBJECT

public:
	frmPrepareDrug(MOTOFun *pMOTOFun, QWidget *parent = Q_NULLPTR);
	~frmPrepareDrug();
	MOTOFun *p_MOTOFun;


	private slots:
	void OnbtnGoNext();
	void OnbtnGoBack();

	void OnbtnInjector();
	void OnbtnMoliquorbag();
	void OnbtnBottle();

private:
	Ui::frmPrepareDrug ui;
	void closeEvent(QCloseEvent *event);

signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
