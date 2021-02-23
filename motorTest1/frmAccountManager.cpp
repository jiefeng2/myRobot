#include "frmAccountManager.h"
#include "common.h"
#include "QMessageBox"
#include "frmMainWidget.h"
#include "QSqlRecord"
#include "QModelIndex"
#include "QSqlTableModel"
#include <QSqlDatabase>


frmAccountManager::frmAccountManager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_ShowModal, true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint | Qt::Dialog);

	//设置为内容不可编辑，但是行可以选择
	ui.tbwUserManager->setEditTriggers(QAbstractItemView::NoEditTriggers);

	usrmodel = new QSqlTableModel(this);
	usrmodel->setTable("usrnametable");
	usrmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//选取整个表的所有行
	usrmodel->select();
	usrmodel->removeColumn(0);  //删除不要列
//    usrmodel->removeColumn(0);
	usrmodel->removeColumn(2);
	usrmodel->setHeaderData(0, Qt::Horizontal, tr("工号")); //修改列名
	usrmodel->setHeaderData(1, Qt::Horizontal, tr("用户名")); //修改列名
	usrmodel->setHeaderData(2, Qt::Horizontal, tr("权限")); //修改列名

	ui.tbwUserManager->setModel(usrmodel);

	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));
	connect(ui.btnNewUser, SIGNAL(clicked()), this, SLOT(OnbtnNewUser()));
	connect(ui.btnModifyUser, SIGNAL(clicked()), this, SLOT(OnbtnModifyUser()));
	connect(ui.btnDelUser, SIGNAL(clicked()), this, SLOT(OnbtnDelUser()));
	connect(ui.tbwUserManager, SIGNAL(clicked(QModelIndex)), this, SLOT(OnTableViewClicked()));
}

frmAccountManager::~frmAccountManager()
{

}


void frmAccountManager::OnbtnExit()
{
	emit  this->btnClickedSignal(FRM_ACCOUNTMANAGER, GO_EXIT_BTN_TYPE);
}

void frmAccountManager::OnbtnNewUser()
{
	//1. 判断系统中是否已经有这个用户
	bool ret = false;
	QString  username = ui.txtUserName->text();
	QString  userright = ui.cmdUserType->currentText();
	QString  userpassword = ui.txtUserPassword->text();
	int  usernum = ui.txtUserNum->text().toInt();
	QSqlQuery query;
	ret = query.exec(QString("select * from usrnametable where usrid = %1").arg(usernum));

	//如果已经存在
	if (query.next())
	{
		QMessageBox::information(this, tr("该工号用户已经存在"), tr("该工号用户已经存在"), QMessageBox::Ok);
	} 
	else
	{
//		query.exec(QString("insert into usrnametable values (NULL, '%2', '%3', '%4', '%5')").arg(usernum).arg(username).arg(userpassword).arg(userright));
		query.exec(QString("insert into usrnametable values (NULL, '%1', '%2', '%3', '%4')").arg(usernum).arg(username).arg(userpassword).arg(userright));
		usrmodel->select();
	}
}

//在修改用户的时候，员工的工号是不能修改的。
void frmAccountManager::OnbtnModifyUser()
{
	bool ret;
	QSqlQuery query;
	int  tempusernum = ui.txtUserNum->text().toInt();
	QString tempusername = ui.txtUserName->text();
	QString tempuserright = ui.cmdUserType->currentText();
	if (tempusernum == m_usernum.toInt())
	{
//这里需要区分是否要修改密码
		//如果密码输入框没有内容，则不修改密码
		if (ui.txtUserPassword->text().isEmpty())
		{
			ret = query.exec(QString("update usrnametable set usrname = '%1', rights = '%2' where usrid = %3").arg(tempusername).arg(tempuserright).arg(tempusernum));
		}
		//密码也要修改
		else
		{
			QString temppsword = ui.txtUserPassword->text();
			ret = query.exec(QString("update usrnametable set usrname = '%1', psword = '%2' rights = '%3' where usrid = %4").arg(tempusername).arg(temppsword).arg(tempuserright).arg(tempusernum));
		}
		usrmodel->select();
	}
	else 
	{
//		QMessageBox::information(this, tr("该工号用户已经存在"), tr("该工号用户已经存在"), QMessageBox::Ok);
	}

//	query.prepare(QString("select * from usrnametable where usrid = %1").arg(usernum));
//	query.prepare(QString("update usrnametable set usrname = %1, rights = %2 where usrid = %1").arg(usernum));
//	query.bindValue(0, 70000);
}


#if 1
void frmAccountManager::OnbtnDelUser()
{
	int curRow = ui.tbwUserManager->currentIndex().row();

	QSqlRecord record = usrmodel->record(curRow);
	int usernum = record.value(0).toInt();
	QSqlQuery query;
	bool ret = query.exec(QString("DELETE FROM usrnametable where usrid = %1").arg(usernum));

	usrmodel->select();
}
#endif


//点击表格时，会在旁边的对话框中显示选中的内容
void frmAccountManager::OnTableViewClicked()
{
	int curRow = ui.tbwUserManager->currentIndex().row();

	QSqlRecord record = usrmodel->record(curRow);
	ui.txtUserName->setText(record.value(1).toString());
	ui.txtUserNum->setText(record.value(0).toString());
//	ui.cmdUserType->setItemText(record.value(4).toString());


//	ui.cmdUserType->setCurrentText("niho");
	ui.cmdUserType->setCurrentText(record.value(2).toString());

	m_username = record.value(1).toString();
	m_usernum = record.value(0).toString();
//	m_userpsword = ;
	m_userright = record.value(2).toString();

}


void frmAccountManager::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, tr("提示"), tr("你确定退出该软件?"), tr("确定"), tr("取消"), 0, 1))
	{
		//关闭软件
	case 0:
		event->accept();
		qApp->quit();
		break;
	case 1:
	default:
		event->ignore();
		break;
	}
}




