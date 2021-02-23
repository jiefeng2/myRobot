#pragma once
#include "common.h"

#include <QWidget>
#include "QDialog"
#include "ui_frmLogin.h"
#include "QCloseEvent"

//class frmLogin : public QWidget
class frmLogin : public QDialog
{
	Q_OBJECT

public:
	frmLogin(QWidget *parent = Q_NULLPTR);
	~frmLogin();

private:
	Ui::frmLogin ui;

	void closeEvent(QCloseEvent *event);

	private slots:
	void OnbtnLogin();
	void OnbtnExit();


//signals:
//	void btnClickedSignal(int widgetindex, int btntype);

};
