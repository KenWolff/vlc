#include "stdafx.h"
#include "Log.h"

Qso const * Log::FindCloseQso(Qso const * q) const
{
	int bestDiff(INT_MAX);
	Qso * bestQso(Q_NULLPTR);
	int count(0);
	for (auto rq : _qsos)
	{
		QString str = rq->ToString();
		if (rq->Band().Name() == q->Band().Name())
		{
			int diff = abs(rq->DateTime().secsTo(q->DateTime()));
			if (diff < bestDiff)
			{
				bestDiff = diff;;
				bestQso = rq;
			}
		}
		count++;
	}
	return bestQso;
}

void Log::AppendQso(Qso *q) { _qsos.append(q); }

void Log::ReadLogFile(QString fileName)
{
	QFile inFile(fileName);
	inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream inStrm(&inFile);

	int row(0);
	while (!inStrm.atEnd())
	{
		QString line = inStrm.readLine().simplified();
		if (line.startsWith("QSO:"))
		{
			AppendQso(new Qso(this, line, row));
			row++;
		}
	}
}

void Log::Clear()
{
	for (auto q : _qsos)
		delete q;
	_qsos.clear();
}

Log::Log(QObject *parent) {}
Log::Log(QObject *parent, QString fileName) 
{
	ReadLogFile(fileName);
}

Log::~Log() {}

