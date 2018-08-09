#include "stdafx.h"
#include "Log.h"

void Log::AppendQso(Qso *q) { _qsos.append(q); }

void Log::ReadLogFile(QString fileName)
{
	QFile inFile(fileName);
	inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream inStrm(&inFile);

	while (!inStrm.atEnd())
	{
		QString line = inStrm.readLine().simplified();
		if (line.startsWith("QSO:"))
			AppendQso(new Qso(this, line));
	}
}

Log::Log(QObject *parent) {}
Log::Log(QObject *parent, QString fileName) 
{
	ReadLogFile(fileName);
}

Log::~Log() {}

