#include "stdafx.h"
#include "LogModel.h"
#include "Log.h"
#include "vlc.h"

vlc::vlc(QWidget *parent) : QMainWindow(parent),
	_log			(Q_NULLPTR),
	_logModel		(Q_NULLPTR),
	_rl				(Q_NULLPTR),
	_rlModel		(Q_NULLPTR),
	_contestDialog	(Q_NULLPTR),
	_logDialog		(Q_NULLPTR),
	_datDialog		(Q_NULLPTR),
	_rlDialog		(Q_NULLPTR),
	_tmDialog		(Q_NULLPTR),
	_contestAction	(Q_NULLPTR),
	_logAction		(Q_NULLPTR),
	_datAction		(Q_NULLPTR),
	_rpt			(Q_NULLPTR),
	_errListModel	(Q_NULLPTR)
{
	ui.setupUi(this);

	_directoryOfContests.setPath("e:/contests");
	_contestDialog = new QFileDialog(this, tr("Select Contest"));
	_contestDialog->setDirectory(_directoryOfContests);
	_contestDialog->setFileMode(QFileDialog::DirectoryOnly);

	_logDialog = new QFileDialog(this, tr("Select Log"));
	_logDialog->setNameFilter(tr("Log File (*.log)"));
	_logDialog->setDirectory(_directoryOfContests);
	_logDialog->setFileMode(QFileDialog::ExistingFile);

	QAction * _contestAction = ui.menuBar->addAction("Contest");
	QAction * _logAction = ui.menuBar->addAction("Log");

	connect(_contestAction, SIGNAL(triggered()), _contestDialog, SLOT(exec()));
	connect(_contestDialog, SIGNAL(fileSelected(QString)), this, SLOT(setContestPath(QString)));

	connect(_logAction, SIGNAL(triggered()), _logDialog, SLOT(exec()));
	connect(_logDialog, SIGNAL(fileSelected(QString)), this, SLOT(logSelected(QString)));
	connect(ui.listView, &QListView::pressed, this, &vlc::errorSelected); // new method that checks signature at compile time

	setContestPath("e:/contests/cq-ww-cw-2017");
}

void vlc::errorSelected(QModelIndex mi)
{
	QString text = mi.data(Qt::DisplayRole).toString();
	QStringList parts = text.split(' ', QString::SkipEmptyParts);
	
	if (parts.size() < 3)
		return;

	QString call = parts[0];
	int lineNum = parts[2].toInt();
	logSelected(_logDir.filePath(parts[0].toLower() + ".log"));

	ui.logView->selectRow(lineNum);
}

void vlc::logSelected(QString logSelectedPath)
{
	QFileInfo info(logSelectedPath);
	QString base = info.baseName();

	if (_log) delete _log;
	_log = new Log(this, logSelectedPath);
	_log->ReadLogFile(logSelectedPath);

	if (_logModel) delete _logModel;
	_logModel = new LogModel(_log);

	if (_rl) delete _rl;;
	_rl = new Log(this);
	_rl->ReadLogFile(_rlDir.filePath(base + ".rl"));

	if (_rlModel) delete _rlModel;
	_rlModel = new LogModel(_rl);

	if (_rpt) delete _rpt;
	_rpt = new Rpt(this);

	ui.logView->setModel(_logModel);
	ui.logView->resizeColumnsToContents();
	ui.logView->show();

	ui.rlView->setModel(_rlModel);
	ui.rlView->resizeColumnsToContents();
	ui.rlView->show();

	ui.label->setText(QString("%1").arg(logSelectedPath));
}

void vlc::setContestPath(QString contestPath)
{
	_contestDir.setCurrent(contestPath);
	_lgDir.setPath(contestPath + "/lg");
	_logDir.setPath(contestPath + "/logs");
	_resDir.setPath(contestPath + "/results");
	_rptDir.setPath(contestPath + "/rpt");
	_rlDir.setPath(contestPath + "/rl");

	_logDialog->setDirectory(_logDir);
	_contestDialog->close();

	if (_errListModel) delete _errListModel;
	_errListModel = new QStringListModel;

	QStringList resList = _resDir.entryList();

	foreach(auto fileName, resList)
	{
		if (fileName.endsWith(".err"))
		{
			_errListModel->setStringList(ReadFileLines(_resDir.filePath(fileName)));
			ui.listView->setModel(_errListModel);
		}
	}

	ui.label->setText(QString("%1").arg(_contestDir.canonicalPath()));
}

QStringList vlc::ReadFileLines(QString fileName)
{
	QFile inFile(fileName);
	inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream inStrm(&inFile);
	QStringList list;
	
	while (!inStrm.atEnd())
		list.append(inStrm.readLine());
	return list;
}


QFileDialog * vlc::ContestDialog()	{ return _contestDialog;}
QFileDialog * vlc::LogDialog()		{ return _logDialog;	}
QFileDialog * vlc::DatDialog()		{ return _datDialog;	}
QFileDialog * vlc::RlDialog()		{ return _rlDialog;		}
QFileDialog * vlc::TmDialog()		{ return _tmDialog;		}