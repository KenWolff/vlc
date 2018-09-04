#pragma once

#include <QtWidgets/QMainWindow>
#include <QSettings>

#include "ui_vlc.h"
#include "Log.h"
#include "LogModel.h"
#include "Rpt.h"
#include "ErrorFileModel.h"
#include "UniFileModel.h"

class vlc : public QMainWindow
{
	Q_OBJECT

public:
	vlc(QWidget * parent = Q_NULLPTR);
	void HideBoxes();

public slots:
	void SelectContest();
	void ShowUnique();
	void ShowError();
	void ShowCll();
	void ShowClx();
	void ShowCaused();
	void ShowRcvd();

	void ErrorLineSelected			(QModelIndex);
	void LogLineSelected			(QModelIndex);
	void UniLineSelected			(QModelIndex);
	void UniCandidateLineSelected	(QModelIndex);
	
	void DisplayUniquesFile			(QString);
	void DisplayErrorFile			(QString);
	void DisplayCllFile				(QString);
	void DisplayClxFile				(QString);
	void DisplayCausedFile			(QString);
	void DisplayRcvdFile			(QString);

	void DisplayLog					(QString);
	void DisplayRl					(QString, Qso const *);
	void DisplayRlCandidates		(Unique &);


private:
	Ui::vlcClass ui;

	QStringList ReadFileLines(QString);
	void		LoadLcDat();

	QString				_contestType;
	QString				_contestName;
	QString				_contestTitle;
	QString				_contestMode;

	QDateTime			_start;
	QDateTime			_end;
	
	QStringListModel	*_errFileModel;
	QStringListModel	*_cllFileModel;
	QStringListModel	*_clxFileModel;
	QStringListModel	*_causedFileModel;
	QStringListModel	*_rcvdFileModel;

	LogModel			*_logFileModel;
	RlCandidateModel	*_rlCandidateModel;
	LogModel			*_rlFileModel;
	UniFileModel		*_uniFileModel;

	Log					*_log;
	Log					*_rl;
	Rpt					*_rpt;
	QSettings			*_settings;

	QDir				_contestDir;
	QDir				_logDir;
	QDir				_lgDir;
	QDir				_resDir;
	QDir				_rlDir;
	QDir				_rptDir;
};
