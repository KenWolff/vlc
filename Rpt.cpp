#include "stdafx.h"
#include "Rpt.h"


Rpt::Rpt(QObject *parent) {}

Rpt::Rpt(QObject *parent, QString fileName)
{
//	ReadRptFile(fileName);
}

Rpt::~Rpt()
{
}

QString Rpt::ReadRptFile(QString fileName)
{
	QFile inFile(fileName);
	inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream inStrm(&inFile);

	_data = inStrm.readAll();
	return _data;
}
