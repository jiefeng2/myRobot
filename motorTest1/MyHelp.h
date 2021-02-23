#pragma once

#include <QObject>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>

class MyHelp : public QObject
{
	Q_OBJECT

public:
	MyHelp(QObject *parent);
	~MyHelp();

	static int GetMotorPortNum(QString portname)
	{
		int ret = 0;
		ret = portname.remove("COM", Qt::CaseInsensitive).toInt();
		return ret;
	}

	static QStringList TraverseSerialPort()
	{
		QStringList ProtNameList;
		QList <QSerialPortInfo> list_info = QSerialPortInfo::availablePorts();

		foreach(const QSerialPortInfo &info, list_info)
		{
			ProtNameList << info.portName();
		}
		return ProtNameList;
	}
};
