#pragma once

#include <QObject>
#include"App.h"

class AppInit : public QObject
{
	Q_OBJECT

public:
	AppInit(QObject *parent);
	AppInit();
	~AppInit();
	void Load();
};
