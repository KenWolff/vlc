#pragma once

#include <QObject>

class Qso : public QObject
{
	Q_OBJECT

public:
	Qso(QObject *parent);
	Qso(QObject *parent, QString line);
	~Qso();

static
	int FieldCount() {return 7;}
	
	QVariant GetData(int idx);
	void SetQrg(int);
	void SetMode(QString);
	void SetDateTime(QDateTime);
	void SetCallSent(QString);
	void SetExchSent(QString);
	void SetCallRcvd(QString);
	void SetExchRcvd(QString);

private:
	int			_qrg;
	QDateTime	_dateTime;
	QString		_mode;
	QString		_callSent;
	QString		_rstSent;
	QString		_exchSent;
	QString		_callRcvd;
	QString		_rstRcvd;
	QString		_exchRcvd;
};
