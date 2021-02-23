#pragma once
#include <QThread>
#include "motofun.h"
class myThread :public QThread
{
	Q_OBJECT
public:
	explicit myThread(MOTOFun *pMOTOFun, QObject *parent = nullptr);
	MOTOFun *p_MOTOFun;
protected:
	void run();
private:
	
};