#include "stdafx.h"
#include "ErrorFileModel.h"

QVariant ErrorFileModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() >= _lines.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return 	_lines.at(index.row());

	return QVariant();
}

int ErrorFileModel::rowCount(const QModelIndex &) const { return 0; }
ErrorFileModel::ErrorFileModel(QObject *parent)	: QObject(parent) { }
ErrorFileModel::~ErrorFileModel() { }
