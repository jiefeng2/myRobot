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

	//获取用户信息
	static bool GetUsrInfo(QSqlQuery query);

	//搜索用户
	bool searchUser(User c_user);
	static bool searchUser(QString username, QString userpassword);

	User *g_user;						//用户变量
	User *g_system_user;				//管理员

};
