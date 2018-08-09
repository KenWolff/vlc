#pragma once

#include <QObject>

class ErrorFileModel : public QObject
{
	Q_OBJECT

public:
	ErrorFileModel(QObject *parent);
	~ErrorFileModel();

	int rowCount(const QModelIndex &) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
	QStringList _lines;
};
