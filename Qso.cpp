#include "stdafx.h"
#include "Qso.h"

Qso::Qso(QObject *parent, QString line)
{
	int idx = line.indexOf(':');							// split() and section() don't work because some lines have multiple ':'
	if (idx == -1)											// must have at least one ':' for token
		return;
	//QString token = line.left(idx).toUpper();						// before the colon -- all tokens are upper case
	QString data = line.right(line.length() - idx - 1).trimmed();	// the rest of the line without white space at ends
	//if (token != "QSO")
	//	return;

	QStringList parts = data.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
	if (parts.size() > 0) _qrg		= parts[0].toInt();
	if (parts.size() > 1) _mode		= parts[1];
	if (parts.size() > 3) _dateTime = QDateTime(QDate::fromString(parts[2], "yyyy-MM-dd"), QTime::fromString(parts[3], "hhmm"));
	if (parts.size() > 4) _callSent = parts[4];
	if (parts.size() > 5) _rstSent	= parts[5];
	if (parts.size() > 6) _exchSent = parts[6];
	if (parts.size() > 7) _callRcvd = parts[7];
	if (parts.size() > 8) _rstRcvd	= parts[8];
	if (parts.size() > 9) _exchRcvd = parts[9];
}

QVariant Qso::GetData(int idx)
{
	switch (idx)
	{
	case 0: return _qrg; break;
	case 1: return _mode; break;
	case 2: return _dateTime.toString("yyyy-MM-dd hhmm"); break;
	case 3: return _callSent; break;
	case 4: return _exchSent; break;
	case 5: return _callRcvd; break;
	case 6: return _exchRcvd; break;
	}

	return QVariant();
}

void Qso::SetQrg(int qrg)			{ _qrg		= qrg;	}
void Qso::SetMode(QString mode)		{ _mode		= mode; }
void Qso::SetDateTime(QDateTime dt) { _dateTime = dt;	}
void Qso::SetCallSent(QString call) { _callSent = call; }
void Qso::SetExchSent(QString exch) { _exchSent = exch; }
void Qso::SetCallRcvd(QString call) { _callRcvd = call; }
void Qso::SetExchRcvd(QString exch) { _exchRcvd = exch; }

Qso::Qso(QObject *parent) : 
	QObject(parent), 
	_dateTime(QDateTime::currentDateTime()), 
	_qrg(7015), 
	_callSent("K1EA"), 
	_exchSent("05"), 
	_callRcvd("F6BEE"),
	_exchRcvd("14"){}

Qso::~Qso(){}
