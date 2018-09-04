#pragma once

#include <QAbstractTableModel>

class UniFileModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	UniFileModel(QObject *parent);
	~UniFileModel();
	void		AddUnique	(Unique uniBlk);
	int			rowCount	(const QModelIndex &) const;
	int			columnCount	(const QModelIndex &) const;
	QVariant	data		(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant	headerData	(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Unique		GetUnique	(int idx) { return _uniques.at(idx); }

private:
	QVector <Unique>	_uniques;

};
