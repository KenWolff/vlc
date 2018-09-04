#include "stdafx.h"
#include "RlCandidateModel.h"

RlCandidateModel::RlCandidateModel(QObject *parent, Unique unique)	: QAbstractTableModel(parent), _unique(unique) {}
RlCandidateModel::~RlCandidateModel(){}

int RlCandidateModel::rowCount(const QModelIndex &) const { return _unique.CandidateCount(); }
int RlCandidateModel::columnCount(const QModelIndex &) const { return 1; }

QVariant RlCandidateModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
		return QVariant();

	return QVariant();
}

QVariant RlCandidateModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::ForegroundRole)
		return QColor(Qt::black);

	if (role == Qt::DisplayRole)
		return 	QVariant(_unique.GetCandidateStr(index));

	return QVariant();
}

