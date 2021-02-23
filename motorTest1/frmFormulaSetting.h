#pragma once

#include <QDialog>
#include "ui_frmFormulaSetting.h"
#include "common.h"
#include "CFormulaParam.h"
#include "qtableview.h"
#include "qsqltablemodel.h"
#include "QCloseEvent"


class frmFormulaSetting : public QDialog
{
	Q_OBJECT

public:
	frmFormulaSetting(QWidget *parent = Q_NULLPTR);
	~frmFormulaSetting();

	QSqlTableModel *usrmodel;    //���ݿ����model
	CFormulaParam *m_pFParam;

	void GetUiConText();			//��ȡ�ؼ��ϵ�����

public slots:
	void OnbtnNew();
	void OnbtnModify();
	void OnbtnDel();
	void OnbtnExit();
	void OntbvwFormulaClicked();


signals:
	void btnClickedSignal(int widgetindex, int btntype);

private:
	Ui::frmFormulaSetting ui;
	void closeEvent(QCloseEvent *event);

};
