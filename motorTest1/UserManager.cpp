#include "UserManager.h"
#include "frmMainWidget.h"
#include "App.h"
#include "qsqlrecord.h"
#include "qsqlfield.h"



UserManager::UserManager(QObject *parent)
	: QObject(parent)
{

	g_user = new User(this);
	g_system_user = new User(this);
	g_system_user->setUserName("Admin");
	g_system_user->setUserPassword("888888");
	g_system_user->setUserRight(SYSTEM_RIGHT);
}

UserManager::~UserManager()
{
}



//�����û�
bool UserManager::searchUser(User c_user)
{
	QString username = c_user.getUserName();
	QString userpsword = c_user.getUserPassword();

	bool ret = false;
	QSqlQuery query;
	ret = query.exec(QString("select usrname, psword from usrnametable where usrname = '%1'and psword = '%2'").arg(username).arg(userpsword));
	
	if (true == ret)
	{

	}
	
	query.next();





	return ret;
}


//�����û�
bool UserManager::searchUser(QString username, QString userpassword)
{
	bool ret = false;

//�����ж��ǲ��ǹ���Ա�˻�
	if ((username == App::g_system_user.getUserName()) &&(userpassword == App::g_system_user.getUserPassword()))
	{
		App::g_current_user.setUserName(username);
		App::g_current_user.setUserRight(7);
		return true;
	}
//���ǹ���Ա���������ݿ�
	else
	{
		QSqlQuery query;
		ret = query.exec(QString("select * from usrnametable where usrname = '%1'and psword = '%2'").arg(username).arg(userpassword));
		if (query.next())
		{
			GetUsrInfo(query);
			return true;
		}
		return false;
	}
}

//��ȡ�û���Ϣ
bool UserManager::GetUsrInfo(QSqlQuery query)
{
	bool ret;
	QSqlRecord rec = query.record();
	int cols = rec.count();


	for (int r = 0; query.next(); r++)
	{
		App::g_current_user.setUserName(query.value(usrname).toString());
		QString username = query.value(rights).toString();
		if (username == "����Ա")
		{
			App::g_current_user.setUserRight(3);
		}
		else if (username == "����Ա")
		{
			App::g_current_user.setUserRight(1);
		}
	}

	return ret;
}


