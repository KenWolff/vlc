#pragma once

#include <QObject>

class ErrorLog : public QObject
{
	Q_OBJECT

public:
	ErrorLog(QObject *parent);
	~ErrorLog();

private:
	QStringList _lines;
};
