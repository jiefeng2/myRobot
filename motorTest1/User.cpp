#include "User.h"

User::User(QObject *parent)
	: QObject(parent)
{
}

User::User(QString _name, QString _password, int _right)
{
	s_user_name = _name;
	s_user_password = _password;
	n_user_right = _right;
}

User::~User()
{
}

void User::setUserName(QString usr_name)
{
	this->s_user_name = usr_name;
}

QString  User::getUserName()
{
	return s_user_name;
}

void User::setUserPassword(QString usr_password)
{
	this->s_user_password;
}

QString User::getUserPassword()
{
	return s_user_password;
}

void User::setUserRight(int usr_right)
{
	this->n_user_right = usr_right;
}

int User::getUserRight()
{
	return n_user_right;
}







