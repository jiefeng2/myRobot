#pragma once

#include <QWidget>
#include "ui_frmWorkLog.h"
#include "QCloseEvent"


class frmWorkLog : public QDialog
{
	Q_OBJECT

public:
	frmWorkLog(QWidget *parent = Q_NULLPTR);
	~frmWorkLog();



private:
	Ui::frmWorkLog ui;
	void closeEvent(QCloseEvent *event);

private slots:
	void OnbtnExit();

signals:
	void btnClickedSignal(int widgetindex, int btntype);



};
