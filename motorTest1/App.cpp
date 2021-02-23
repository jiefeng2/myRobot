#include "App.h"
#include "qfile.h"
#include "qsettings.h"
#include "qdir.h"
#include "qstring.h"

int App::Motor1PortNum = 1;
int App::Motor2PortNum = 2;
int App::Motor3PortNum = 3;
int App::Motor4PortNum = 4;
int App::Motor5PortNum = 5; 
QString App::ForceSensorPortName = "COM6";

//各个电机的参数
float  App::Motor1SpeedVal = 10;
float  App::Motor1ACVal = 1;
float  App::Motor1ReRate = 1;

float  App::Motor2SpeedVal = 10;
float  App::Motor2ACVal = 1;
float  App::Motor2ReRate = 1;

float  App::Motor3SpeedVal = 10;
float  App::Motor3ACVal = 1;
float  App::Motor3ReRate = 1;

float  App::Motor4SpeedVal = 10;
float  App::Motor4ACVal = 1;
float  App::Motor4ReRate = 1;

float  App::Motor5SpeedVal = 10;
float  App::Motor5ACVal = 1;
float  App::Motor5ReRate = 1;

QString App::AppName = "DispensingSystem";
QString App::AppPath = "";

User App::g_current_user = {"张三", "123", 1};
User App::g_system_user = { "admin", "111111", 7 };

App::App(QObject *parent)
	: QObject(parent)
{
}

App::~App()
{
}

void App::ReadConfig()
{
	QString path;
	QDir dir;
	App::AppPath = dir.currentPath();

	QString fileName = QString("%1/%2_Config.ini").arg(App::AppPath).arg(App::AppName);

	//如果配置文件大小为0,则以初始值继续运行,并生成配置文件
	QFile file(fileName);
	if (file.size() == 0) {
		WriteConfig();
		return;
	}

	QSettings set(fileName, QSettings::IniFormat);

	set.beginGroup("AppConfig");
	App::Motor1PortNum = set.value("Motor1PortNum").toInt();
	App::Motor2PortNum = set.value("Motor2PortNum").toInt();
	App::Motor3PortNum = set.value("Motor3PortNum").toInt();
	App::Motor4PortNum = set.value("Motor4PortNum").toInt();
	App::Motor5PortNum = set.value("Motor5PortNum").toInt();
	App::ForceSensorPortName = set.value("ForceSensorPortName").toString();

	App::Motor1SpeedVal = set.value("Motor1SpeedVal").toFloat();
	App::Motor1ACVal = set.value("Motor1ACVal").toFloat();
	App::Motor2SpeedVal = set.value("Motor2SpeedVal").toFloat();
	App::Motor2ACVal = set.value("Motor2ACVal").toFloat();
	App::Motor3SpeedVal = set.value("Motor3SpeedVal").toFloat();
	App::Motor3ACVal = set.value("Motor3ACVal").toFloat();
	App::Motor4SpeedVal = set.value("Motor4SpeedVal").toFloat();
	App::Motor4ACVal = set.value("Motor4ACVal").toFloat();
	App::Motor5SpeedVal = set.value("Motor5SpeedVal").toFloat();
	App::Motor5ACVal = set.value("Motor5ACVal").toFloat();

	/*
	App::UseTray = set.value("UseTray").toBool();
	App::SaveLog = set.value("SaveLog").toBool();
	App::UseStyle = set.value("UseStyle").toBool();
	App::StyleName = set.value("StyleName").toString();
	App::FontSize = set.value("FontSize").toInt();
	App::FontName = set.value("FontName").toString();
	*/

	set.endGroup();
}

void App::WriteConfig()
{
	QString fileName = QString("%1/%2_Config.ini").arg(App::AppPath).arg(App::AppName);
	QSettings set(fileName, QSettings::IniFormat);

	set.beginGroup("AppConfig");

	set.setValue("Motor1PortNum", App::Motor1PortNum);
	set.setValue("Motor2PortNum", App::Motor2PortNum);
	set.setValue("Motor3PortNum", App::Motor3PortNum);
	set.setValue("Motor4PortNum", App::Motor4PortNum);
	set.setValue("Motor5PortNum", App::Motor5PortNum);
	set.setValue("ForceSensorPortName", App::ForceSensorPortName);

	set.setValue("Motor1SpeedVal", App::Motor1SpeedVal);
	set.setValue("Motor1ACVal", App::Motor1ACVal);
	set.setValue("Motor2SpeedVal", App::Motor2SpeedVal);
	set.setValue("Motor2ACVal", App::Motor2ACVal);
	set.setValue("Motor3SpeedVal", App::Motor3SpeedVal);
	set.setValue("Motor3ACVal", App::Motor3ACVal);
	set.setValue("Motor4SpeedVal", App::Motor4SpeedVal);
	set.setValue("Motor4ACVal", App::Motor4ACVal);
	set.setValue("Motor5SpeedVal", App::Motor5SpeedVal);
	set.setValue("Motor5ACVal", App::Motor5ACVal);

	/*
	set.setValue("UseTray", App::UseTray);
	set.setValue("SaveLog", App::SaveLog);
	set.setValue("UseStyle", App::UseStyle);
	set.setValue("StyleName", App::StyleName);
	set.setValue("FontSize", App::FontSize);
	set.setValue("FontName", App::FontName);
	*/
	set.endGroup();
}

