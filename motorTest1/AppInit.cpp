#include "AppInit.h"

AppInit::AppInit(QObject *parent)
	: QObject(parent)
{
	;
}

AppInit::AppInit()
	: QObject()
{
	;
}

AppInit::~AppInit()
{
}

void AppInit::Load()
{
	App::ReadConfig();
}


