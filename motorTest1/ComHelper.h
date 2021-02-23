#pragma once

#include <QObject>

class ComHelper : public QObject
{
	Q_OBJECT

public:
	ComHelper(QObject *parent);
	~ComHelper();

	static bool changeUserRightStrToInt(QString s_userright, int *n_userright);



};
