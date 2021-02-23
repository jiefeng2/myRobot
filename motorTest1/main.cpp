#include "motorTest1.h"
#include <QtWidgets/QApplication>
#include <QLibrary>
#include <QDebug>
#include "stdio.h"
#include<Windows.h>  
#include<iostream>
#include "qapplication.h"
#include "AppInit.h"
#include "frmSystemParamSetting.h"
#include "frmMainWidget.h"
#include "TestForm1.h"
#include "frmLogin.h"
#include "qobject.h"
#include "frmAccountManager.h"
#include "frmSystemParamSetting.h"


using namespace std;


# pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
//	HINSTANCE  m_hDll;

//	const char* dllName = "SCLLib_x86.dll";
	QApplication a(argc, argv);

	a.setApplicationName("App::AppName");
	a.setApplicationVersion("1.00");

	AppInit *init = new AppInit();
	init->Load();

//	motorTest1 w;
//	frmSystemParamSetting  w;
	frmMainWidget  frmMainW;
	frmMainW.hide();
	frmLogin frmlogin;

//	frmAccountManager w;
//	w.show();


	if (frmlogin.exec() == QDialog::Accepted)
	{
		frmMainW.show();
		return a.exec();
	}
	else
	{
		return 0;
	}

}
