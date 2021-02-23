#pragma once

#include <QWidget>
#include "ui_frmSystemSetting.h"
#include "QCloseEvent"

class frmSystemSetting : public QWidget
{
	Q_OBJECT

public:
	frmSystemSetting(QWidget *parent = Q_NULLPTR);
	~frmSystemSetting();

	private slots:
	void OnbtnParamSetting();
	void OnbtnAccountManagement();
	void OnbtnExit();
	void OnbtnWorkLog();
	void OnbtnFormulaSetting();

private:
	Ui::frmSystemSetting ui;
	void closeEvent(QCloseEvent *event);
signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
