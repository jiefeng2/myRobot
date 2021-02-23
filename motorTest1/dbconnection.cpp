#include "dbconnection.h"
#include "QDebug.h"

QSqlDatabase db;


bool createConnection()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../DB");
	if (!db.open())
	{
		qDebug() << "open DB error";
		return false;
	}

	qDebug() << "open DB suceess";

	QSqlQuery query;

	//因为使用了中文，所以要使用QString 进行转换
	/*创建一个操作员表。主键， 用户ID，用户名，密码，权限*/
	query.exec(QString("create table usrnametable (id integer primary key autoincrement, usrid int, usrname vchar, psword vchar, rights vchar)"));
	query.exec(QString("insert into usrnametable values (1, '0001', 'admin', '111111', '超级管理员')"));
	//    query.exec(QString("insert into usrnametable values (NULL, '0001', 'admin', '111111', '管理员')"));
	//    query.exec(QString("insert into usrnametable values (NULL, '0001', 'admin', '111111', '操作员')"));


	//配方表
	query.exec(QString("create table formulatable (id integer primary key autoincrement,    \
	  s_serial_num vchar,		\
	  s_grug_name vchar,		\
	  s_mother_liquor_name vchar,		\
	  s_bottle_name vchar,		\
	  s_vial_bottle_num vchar,		\
	  s_mother_liquor_cap vchar,		\
	  s_single_mother_liquor_cap vchar,		\
	  s_target_weight vchar, \
	  s_shake_angle vchar, \
	  s_shake_times vchar, \
	  s_weighing_error vchar, \
	  s_pump_capacity vchar, \
	  s_change_timer vchar, \
	  s_change_param_Vf vchar, \
	  s_change_param_Vg vchar, \
	  s_change_param_F1 vchar, \
	  s_change_param_G1 vchar, \
	  s_change_param_F2 vchar, \
	  s_change_param_G2 vchar, \
	  s_change_param_F3 vchar, \
	  s_change_param_G3 vchar, \
	  s_change_param_F4 vchar, \
	  s_change_param_G4 vchar, \
	  s_change_param_F5 vchar, \
	  s_change_param_G5 vchar)"));
	query.exec(QString("insert into formulatable values (1,\
		'20181223001',\
		'药剂A',\
		'母液A',\
		'药品A',\
		'3',\
		'15',\
		'5',\
		'20',\
		'14',\
		'13',\
		'12',\
		'11',\
		'3',\
		'5',\
		'5',\
		'10',\
		'10',\
		'10',\
		'10',\
		'10',\
		'10',\
		'0',\
		'0',\
		'0',\
		'0')"));


	return true;
}



