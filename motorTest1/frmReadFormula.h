#pragma once

#include <QWidget>
#include "ui_frmReadFormula.h"
#include "common.h"
#include "QSqlTableModel"
#include "QCloseEvent"





class frmReadFormula : public QWidget
{
	Q_OBJECT

public:
	frmReadFormula(QWidget *parent = Q_NULLPTR);
	~frmReadFormula();

	QSqlTableModel *formulamodel;    //���ݿ����model

	void UpdateFormulaDisplay();		//����ҩ�������ʾ

private:
	Ui::frmReadFormula ui;
	void closeEvent(QCloseEvent *event);

private slots:
	void OnbtnGoNext();
	void OnbtnGoBack();
	void OnbtnReadFormula();

signals:
	void btnClickedSignal(int widgetindex, int btntype);

};
