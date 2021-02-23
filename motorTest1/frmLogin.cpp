#include "frmLogin.h"
#include "QMessageBox"
#include <QtWidgets/QApplication>
#include "User.h"
#include "UserManager.h"


frmLogin::frmLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnLogin, SIGNAL(clicked()), this, SLOT(OnbtnLogin()));
	connect(ui.btnExit, SIGNAL(clicked()), this, SLOT(OnbtnExit()));

}

frmLogin::~frmLogin()
{

}


void frmLogin::OnbtnLogin()
{
	bool ret = false;
	if ((ui.txtUsr->text().isEmpty())||(ui.txtPassWord->text().isEmpty()))
	{
		QMessageBox::information(this, tr("请输入用户名"), tr("请输入用户名和密码"), QMessageBox::Ok);
		ui.txtUsr->setFocus();
	}
	else
	{
		QString usrname1 = ui.txtUsr->text();
		QString psword1 = ui.txtPassWord->text();

		ret = UserManager::searchUser(usrname1, psword1);
		if (true == ret)
		{
			ui.txtUsr->clear();
			ui.txtPassWord->clear();
			ui.txtUsr->setFocus();
			this->hide();
			accept();
		} 
		else
		{
			QMessageBox::warning(this, tr("Warning"), tr("用户名或者密码错误"), QMessageBox::Yes);
			ui.txtUsr->clear();
			ui.txtPassWord->clear();
			ui.txtUsr->setFocus();
		}

#if 0
		//查找数据库

		//        usrname,psword
		query.exec(QString("select usrname, psword from usrnametable where usrname = '%1'").arg(usrname1));
		query.next();

		//        qDebug()<<""<<query.value(1).toString();
		if ((ui.usrLineEdit->text() == g_system_user.s_) && ui.pwdLineEdit->text() == tr(""))
			//        if(query.value(1).toString() == ui->pwdLineEdit->text())
		{
			QString text1 = "登陆";
			QString text2 = "用户<" + ui->usrLineEdit->text() + ">登陆";
			LoginName = ui->usrLineEdit->text();    //保存登录名
			QDateTime temptime = QDateTime::currentDateTime();
			QString text3 = temptime.toString("yyyy-MM-dd hh:mm:ss");

			//将需要发送的数据填充到发送缓冲区中
			//            g_SyslogDataStu.FrameType =
			//            g_SyslogDataStu.LoginState =
			ChangeQStrToQuint8(ui->usrLineEdit->text(), &g_SyslogDataStu.UsrName[0]);
			ChangeQStrToQuint8(text3, &g_SyslogDataStu.DataTimeBuff[0]);



			//登陆成功之后，系统日志数据表中添加记录
			query.exec(QString("insert into syslogtable values (NULL, '%2', '%3','%4')").arg(text1).arg(text2).arg(text3));

			//将数据填充到发送缓冲区中
			AddSysLogToGPRSSendBuff(0, LoginName);

			this->hide();       //隐藏登陆窗口
			qDebug() << "login sucess";
			ui->usrLineEdit->clear();
			ui->pwdLineEdit->clear();
			emit this->custSignal(1);
			accept();
		}
		else
		{
			QMessageBox::warning(this, tr("Warning"), tr("用户名或者密码错误"), QMessageBox::Yes);
			ui->usrLineEdit->clear();
			ui->pwdLineEdit->clear();
			ui->usrLineEdit->setFocus();
		}
#endif


	}
}


void frmLogin::OnbtnExit()
{
	this->close();

}


void frmLogin::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, tr("提示"), tr("你确定退出该软件?"), tr("确定"), tr("取消"), 0, 1))
	{
	//关闭软件
	case 0:
		event->accept();
		qApp->quit();
		break;
	case 1:	
	default:
		event->ignore();
		break;
	}
}




