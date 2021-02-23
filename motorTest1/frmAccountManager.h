#pragma once

#include <QWidget>
#include "ui_frmAccountManager.h"
#include "qtableview.h"
#include "qsqltablemodel.h"
#include "qstring.h"
#include "QCloseEvent"

class frmAccountManager : public QWidget
{
	Q_OBJECT

public:
	frmAccountManager(QWidget *parent = Q_NULLPTR);
	~frmAccountManager();

	QSqlTableModel *usrmodel;    //Êý¾Ý¿â²Ù×÷model

	QString m_username;
	QString m_usernum;
	QString m_userpsword;
	QString m_userright;

	private slots:
	void OnbtnExit();
	void OnbtnNewUser();
	void OnbtnModifyUser();
	void OnbtnDelUser();
	void OnTableViewClicked();


private:
	Ui::frmAccountManager ui;
	void closeEvent(QCloseEvent *event);

signals:
	void btnClickedSignal(int widgetindex, int btntype);

};
