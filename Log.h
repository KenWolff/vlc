#pragma once
#include "qobject.h"
#include "Qso.h"

class Log : public QObject
{
	Q_OBJECT
public:
	Log(QObject *parent = Q_NULLPTR);
	Log(QObject *parent, QString path);
	~Log();

	void			AppendQso(Qso *);
	int				QsoCount()		const { return _qsos.size();	}
	Qso *			GetQso(int idx) const { return _qsos.at(idx);	}
	void			ReadLogFile(QString);
	void			Clear();
	Qso const	*	FindCloseQso(Qso const *) const;

private:
	QVector <Qso *> _qsos;
};

