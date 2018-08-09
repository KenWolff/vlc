#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vlc.h"
#include "Log.h"
#include "LogModel.h"
#include "Rpt.h"
#include "ErrorFileModel.h"

class vlc : public QMainWindow
{
	Q_OBJECT

public:
	vlc(QWidget * parent = Q_NULLPTR);
	QFileDialog * ContestDialog();
	QFileDialog * LogDialog();
	QFileDialog * DatDialog();
	QFileDialog * RlDialog();
	QFileDialog * TmDialog();

public slots:
	void setContestPath(QString);
	void logSelected(QString);
	void errorSelected(QModelIndex);

private:
	Ui::vlcClass ui;

	QStringList ReadFileLines(QString);
	Log		 *_log;
	LogModel *_logModel;
	Log		 *_rl;
	LogModel *_rlModel;
	Rpt		 *_rpt;
	QStringListModel *_errListModel;

	QFileDialog *_contestDialog;
	QFileDialog *_logDialog;
	QFileDialog *_datDialog;
	QFileDialog *_rlDialog;
	QFileDialog *_tmDialog;

	QAction *_contestAction;
	QAction *_logAction;
	QAction *_datAction;

	QDir	_contestDir;
	QDir	_logDir;
	QDir	_lgDir;
	QDir	_resDir;
	QDir	_rlDir;
	QDir	_rptDir;

	QDir	_directoryOfContests;

};
