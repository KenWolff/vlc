#pragma once

class LogModel : public QAbstractTableModel
{
	Q_OBJECT

	static QStringList hdrLabels;

public:
	LogModel(Log *);
	~LogModel();
	int rowCount(const QModelIndex &) const;
	int columnCount(const QModelIndex &) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qso const * FindCloseQso(Qso const *);
private:
	Log * _log;
};
