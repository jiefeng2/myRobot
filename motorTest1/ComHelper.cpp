#include "ComHelper.h"
#include "common.h"

ComHelper::ComHelper(QObject *parent)
	: QObject(parent)
{
}

ComHelper::~ComHelper()
{
}

//���û�Ȩ�޸ĳ�����
bool ComHelper::changeUserRightStrToInt(QString s_userright, int *n_userright)
{
	if (s_userright == "��������Ա")
	{
		*n_userright = SYS_USR_RIGHT;
	}
	else if (s_userright == "����Ա")
	{
		*n_userright = USR_RIGHT;
	}
	else if (s_userright == "����Ա")
	{
		*n_userright = OPERATOR_RIGHT;
	}
	else
	{
		return false;
	}
	return true;
}





