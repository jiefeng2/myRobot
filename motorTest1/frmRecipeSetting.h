#pragma once

#include <QWidget>
#include "ui_frmRecipeSetting.h"
#include "QCloseEvent"


class frmRecipeSetting : public QWidget
{
	Q_OBJECT

public:
	frmRecipeSetting(QWidget *parent = Q_NULLPTR);
	~frmRecipeSetting();

	private slots:
	void OnbtnGoExit();

private:
	Ui::frmRecipeSetting ui;
	void closeEvent(QCloseEvent *event);

signals:
	void btnClickedSignal(int widgetindex, int btntype);
};
