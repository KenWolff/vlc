#pragma once
#include "qobject.h"
#include "Qso.h"

class Log : public QObject
{
	Q_OBJECT
public:
	Log(QObject *parent);
	Log(QObject *parent, QString path);
	~Log();

	void	AppendQso(Qso *);
	int		QsoCount()		const { return _qsos.size();	}
	Qso *	GetQso(int idx) const { return _qsos.at(idx);	}
	void	ReadLogFile(QString);

private:
	QVector <Qso *> _qsos;
};

