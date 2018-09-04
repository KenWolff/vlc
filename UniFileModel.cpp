#include "stdafx.h"

UniFileModel::UniFileModel(QObject *parent)	: QAbstractTableModel(parent) {}
UniFileModel::~UniFileModel() {}

int UniFileModel::rowCount(const QModelIndex &) const { return _uniques.size(); }
int UniFileModel::columnCount(const QModelIndex &) const { return 1; }

QVariant UniFileModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::BackgroundRole)
		return QColor(Qt::white);

	if (role == Qt::ForegroundRole)
		return QColor(Qt::blue);

	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
			return QVariant();

		if (orientation == Qt::Vertical)
			return section + 1;
	}

	return QVariant();
}

QVariant UniFileModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::DisplayRole)
		return QVariant(_uniques.at(index.row()).ToString());

	if (role == Qt::TextAlignmentRole)
		return Qt::AlignLeft;

	return QVariant();
}

void UniFileModel::AddUnique(Unique unique) 
{ 
	_uniques.append(unique);
}
