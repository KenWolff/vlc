#include "stdafx.h"
#include "LogModel.h"

int LogModel::rowCount(const QModelIndex &) const {	return _log->QsoCount(); }
int LogModel::columnCount(const QModelIndex &) const { return Qso::FieldCount(); }

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
		return 	_log->GetQso(index.row())->GetData(index.column());

	if (role == Qt::TextAlignmentRole)
		return Qt::AlignCenter;

	return QVariant();
}

QStringList LogModel::hdrLabels = { "QRG", "Mode", "QTR", "Call Sent", "Zone Sent", "Call Rcvd", "Zone Rcvd" };
LogModel::LogModel(Log * log) : _log(log) {}
LogModel::~LogModel() {}
