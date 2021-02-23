#include "ComHelper.h"
#include "common.h"

ComHelper::ComHelper(QObject *parent)
	: QObject(parent)
{
}

ComHelper::~ComHelper()
{
}

//将用户权限改成数字
bool ComHelper::changeUserRightStrToInt(QString s_userright, int *n_userright)
{
	if (s_userright == "超级管理员")
	{
		*n_userright = SYS_USR_RIGHT;
	}
	else if (s_userright == "管理员")
	{
		*n_userright = USR_RIGHT;
	}
	else if (s_userright == "操作员")
	{
		*n_userright = OPERATOR_RIGHT;
	}
	else
	{
		return false;
	}
	return true;
}





