#pragma once

#include <QObject>
#include <QString>

enum {
	OPERA_RIGHT,
	MANAGER_RIGHT,
	SYSTEM_RIGHT,
};

class User : public QObject
{
	Q_OBJECT

public:
	User(QObject *parent);
	User(QString _name,	QString _password,int _right);
	~User();

	void setUserName(QString usr_name);
	QString  getUserName();
	void setUserPassword(QString usr_password);
	QString getUserPassword();
	void setUserRight(int usr_right);
	int getUserRight();

	QString s_user_name;
	QString s_user_password;
	int n_user_right;

private:
//	QString s_user_name;
//	QString s_user_password;
//	int n_user_right;


};
