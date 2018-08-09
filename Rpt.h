#pragma once
#include "qobject.h"
class Rpt :	public QObject
{
	Q_OBJECT
public:
	Rpt(QObject *parent);
	Rpt(QObject *parent, QString path);
	~Rpt();

	QString	ReadRptFile(QString);


private:
	QString _data;
};

