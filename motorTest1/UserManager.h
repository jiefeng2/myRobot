#pragma once

#include <QObject>
#include "User.h"
#include "qsqlquery.h"



class UserManager : public QObject
{
	Q_OBJECT

public:
	UserManager(QObject *parent);
	~UserManager();

	//��ȡ�û���Ϣ
	static bool GetUsrInfo(QSqlQuery query);

	//�����û�
	bool searchUser(User c_user);
	static bool searchUser(QString username, QString userpassword);

	User *g_user;						//�û�����
	User *g_system_user;				//����Ա

};
