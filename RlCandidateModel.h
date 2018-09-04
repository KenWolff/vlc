#pragma once

class RlCandidateModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	RlCandidateModel(QObject *, Unique );
	~RlCandidateModel();

	int			rowCount			(const QModelIndex &) const;
	int			columnCount			(const QModelIndex &) const;
	QString		GetCandidateCall	(const QModelIndex &index) const { return _unique.GetCandidateCall(index);	}
	Qso const *	UniqueQso			(const QModelIndex &index) const { return _unique.UniqueQso();				}
	QVariant	data				(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant	headerData			(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Unique	const GetUnique() const { return _unique; }

private:
	Unique _unique;
};
