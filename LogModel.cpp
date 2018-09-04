#include "stdafx.h"
#include "LogModel.h"

int LogModel::rowCount		(const QModelIndex &) const { return _log->QsoCount(); }
int LogModel::columnCount	(const QModelIndex &) const { return Qso::FieldCount(); }

Qso const * LogModel::FindCloseQso(Qso const * q) {	return _log->FindCloseQso(q); }


QVariant LogModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::BackgroundRole)
		return QColor(Qt::white);

	if (role == Qt::ForegroundRole)
		return QColor(Qt::blue);

	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
			return hdrLabels.at(section);

		if (orientation == Qt::Vertical)
			return section + 1;
	}

	return QVariant();
}

QVariant LogModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() >= _log->QsoCount()  || index.column() >= Qso::FieldCount())
		return QVariant();

	if(role == Qt::DisplayRole)
		return 	_log->GetQso(index.row())->ToString();

	if (role == Qt::TextAlignmentRole)
	{
		if(index.column() == 5)
			return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
		return Qt::AlignCenter;
	}

	return QVariant();
}

QStringList LogModel::hdrLabels = { "QRG", "Mode", "QTR", "Sent", "Exch", "Rcvd", "Exch" };
LogModel::LogModel(Log * log) : _log(log) {}
LogModel::~LogModel() {}
