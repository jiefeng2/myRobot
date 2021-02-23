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

	//����Ϊ���ݲ��ɱ༭�������п���ѡ��
	ui.tbwUserManager->setEditTriggers(QAbstractItemView::NoEditTriggers);

	usrmodel = new QSqlTableModel(this);
	usrmodel->setTable("usrnametable");
	usrmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//ѡȡ�������������
	usrmodel->select();
	usrmodel->removeColumn(0);  //ɾ����Ҫ��
//    usrmodel->removeColumn(0);
	usrmodel->removeColumn(2);
	usrmodel->setHeaderData(0, Qt::Horizontal, tr("����")); //�޸�����
	usrmodel->setHeaderData(1, Qt::Horizontal, tr("�û���")); //�޸�����
	usrmodel->setHeaderData(2, Qt::Horizontal, tr("Ȩ��")); //�޸�����

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
	//1. �ж�ϵͳ���Ƿ��Ѿ�������û�
	bool ret = false;
	QString  username = ui.txtUserName->text();
	QString  userright = ui.cmdUserType->currentText();
	QString  userpassword = ui.txtUserPassword->text();
	int  usernum = ui.txtUserNum->text().toInt();
	QSqlQuery query;
	ret = query.exec(QString("select * from usrnametable where usrid = %1").arg(usernum));

	//����Ѿ�����
	if (query.next())
	{
		QMessageBox::information(this, tr("�ù����û��Ѿ�����"), tr("�ù����û��Ѿ�����"), QMessageBox::Ok);
	} 
	else
	{
//		query.exec(QString("insert into usrnametable values (NULL, '%2', '%3', '%4', '%5')").arg(usernum).arg(username).arg(userpassword).arg(userright));
		query.exec(QString("insert into usrnametable values (NULL, '%1', '%2', '%3', '%4')").arg(usernum).arg(username).arg(userpassword).arg(userright));
		usrmodel->select();
	}
}

//���޸��û���ʱ��Ա���Ĺ����ǲ����޸ĵġ�
void frmAccountManager::OnbtnModifyUser()
{
	bool ret;
	QSqlQuery query;
	int  tempusernum = ui.txtUserNum->text().toInt();
	QString tempusername = ui.txtUserName->text();
	QString tempuserright = ui.cmdUserType->currentText();
	if (tempusernum == m_usernum.toInt())
	{
//������Ҫ�����Ƿ�Ҫ�޸�����
		//������������û�����ݣ����޸�����
		if (ui.txtUserPassword->text().isEmpty())
		{
			ret = query.exec(QString("update usrnametable set usrname = '%1', rights = '%2' where usrid = %3").arg(tempusername).arg(tempuserright).arg(tempusernum));
		}
		//����ҲҪ�޸�
		else
		{
			QString temppsword = ui.txtUserPassword->text();
			ret = query.exec(QString("update usrnametable set usrname = '%1', psword = '%2' rights = '%3' where usrid = %4").arg(tempusername).arg(temppsword).arg(tempuserright).arg(tempusernum));
		}
		usrmodel->select();
	}
	else 
	{
//		QMessageBox::information(this, tr("�ù����û��Ѿ�����"), tr("�ù����û��Ѿ�����"), QMessageBox::Ok);
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


//������ʱ�������ԱߵĶԻ�������ʾѡ�е�����
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
	switch (QMessageBox::information(this, tr("��ʾ"), tr("��ȷ���˳������?"), tr("ȷ��"), tr("ȡ��"), 0, 1))
	{
		//�ر����
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




