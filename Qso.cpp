#include "stdafx.h"

Qso::Qso(QObject *parent, QString line, int row) : _row(row)
{
	QString data = line.simplified();
	bool hasRst(false);
	if (line.startsWith("QSO:"))
		hasRst = true;

	QStringList parts = data.split(' ');
	if (hasRst && parts.size() >= 11)
	{
		_qrg		= parts[1].toInt();
		_mode		= parts[2];
		_dateTime	= QDateTime(QDate::fromString(parts[3], "yyyy-MM-dd"), QTime::fromString(parts[4], "hhmm"));
		_callSent	= parts[5];
		_rstSent	= parts[6];
		_exchSent	= parts[7];
		_callRcvd	= parts[8];
		_rstRcvd	= parts[9];
		_exchRcvd	= parts[10];
	}

	if (!hasRst && parts.size() < 9)
	{
		_qrg		= parts[0].toInt();
		_mode		= parts[1];
		_dateTime	= QDateTime(QDate::fromString(parts[2], "yyyy-MM-dd"), QTime::fromString(parts[3], "hhmm"));
		_callSent	= parts[4];
		_exchSent	= parts[5];
		_callRcvd	= parts[6];
		_exchRcvd	= parts[7];
	}

	if (_qrg >= B10.LowerEdge() && _qrg <= B10.UpperEdge())  _band = B10;	else
		if (_qrg >= B15.LowerEdge() && _qrg <= B15.UpperEdge())  _band = B15;	else
			if (_qrg >= B20.LowerEdge() && _qrg <= B20.UpperEdge())  _band = B20;	else
				if (_qrg >= B40.LowerEdge() && _qrg <= B40.UpperEdge())  _band = B40;	else
					if (_qrg >= B80.LowerEdge() && _qrg <= B80.UpperEdge())  _band = B80;	else
						if (_qrg >= B160.LowerEdge() && _qrg <= B160.UpperEdge()) _band = B160;
}

QVariant Qso::GetData(int idx)
{
	switch (idx)
	{
	case 0: return _qrg;
	case 1: return _mode;
	case 2: return _dateTime.toString("yyyy-MM-dd hhmm");
	case 3: return _callSent;
	case 4: return _exchSent;
	case 5: return _callRcvd;
	case 6: return _exchRcvd;
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
