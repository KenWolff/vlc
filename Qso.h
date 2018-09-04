#pragma once

#include <QObject>

class Qso : public QObject
{
	Q_OBJECT

public:
	Qso(QObject *parent);
	Qso(QObject *parent, QString line, int row = 0);
	~Qso();

	int			Qrg()		const { return _qrg;		}
	int			Row()		const { return _row;		}
	QDateTime	DateTime()	const { return _dateTime;	}
	QString		Mode()		const { return _mode;		}
	QString		CallSent()	const { return _callSent;	}
	QString		RstSent()	const { return _rstSent;	}
	QString		ExchSent()	const { return _exchSent;	}
	QString		CallRcvd()	const { return _callRcvd;	}
	QString		RstRcvd	()	const { return _rstRcvd;	}
	QString		ExchRcvd()	const { return _exchRcvd;	}
	BandInfo	Band()		const { return _band;		}
	QString		DateStr()	const { return _dateTime.date().toString("yyyy-MM-dd"); }
	QString		TimeStr()	const { return _dateTime.time().toString("hhmm"); }

	QString Qso::ToString() const
	{
		return QString("%1 %2 %3 %4 %5 %6 %7 %8")
			.arg(_qrg, 5)
			.arg(_mode, 2)
			.arg(DateStr())
			.arg(TimeStr())
			.arg(_callSent, -10)
			.arg(_exchSent, 5)
			.arg(_callRcvd, -10)
			.arg(_exchRcvd, 5);
	}

	QVariant GetData(int idx);
	void SetQrg(int);
	void SetMode(QString);
	void SetDateTime(QDateTime);
	void SetCallSent(QString);
	void SetExchSent(QString);
	void SetCallRcvd(QString);
	void SetExchRcvd(QString);

	static	int FieldCount() { return 7; }

private:
	int			_qrg;
	int			_row;
	QDateTime	_dateTime;
	QString		_mode;
	QString		_callSent;
	QString		_rstSent;
	QString		_exchSent;
	QString		_callRcvd;
	QString		_rstRcvd;
	QString		_exchRcvd;
	BandInfo	_band;
};
