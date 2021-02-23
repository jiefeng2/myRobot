#pragma once

#include <QObject>
#include "qstring.h"

class CFormulaParam : public QObject
{
	Q_OBJECT

public:
	CFormulaParam(QObject *parent);
	~CFormulaParam();

	QString m_sNum;
	QString m_sPharName;
	QString m_sLiquorName;
	QString m_sPillName;
	QString m_sVialNum;
	QString m_sLiquorVol;
	QString m_sSingleLiquorVol;
	QString m_sTargetWeight;
	QString m_sShakeAngle; 
	QString m_sShakeTimes;
	QString m_sWeighingError;
	QString m_sPumpCapacity;
	QString m_sExchangeTime;
	QString m_sVf;
	QString m_sVg;
	QString m_sVF1;
	QString m_sVF2;
	QString m_sVG1;
    QString m_sVG2;

	QString m_com1;
	QString m_com2;
	QString m_com3;
	QString m_com4;
	QString m_com5;
	QString m_com6;

};
