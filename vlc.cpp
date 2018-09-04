#include "stdafx.h"
#include "LogModel.h"
#include "Log.h"
#include "vlc.h"
#include "RlCandidateModel.h"

vlc::vlc(QWidget *parent) : QMainWindow(parent),
	_log				(Q_NULLPTR),
	_logFileModel		(Q_NULLPTR),
	_rl					(Q_NULLPTR),
	_rlFileModel		(Q_NULLPTR),
	_rpt				(Q_NULLPTR),
	_uniFileModel		(Q_NULLPTR),
	_rlCandidateModel	(Q_NULLPTR),
	_errFileModel		(Q_NULLPTR),
	_cllFileModel		(Q_NULLPTR),
	_clxFileModel		(Q_NULLPTR),
	_causedFileModel	(Q_NULLPTR),
	_rcvdFileModel		(Q_NULLPTR)
{
	QApplication::setFont(QFont("Lucida Console"));
	ui.setupUi(this);
	QAction * contestAction	= ui.menuBar->addAction("Contest");
	QAction * uniAction		= ui.menuBar->addAction("Uniques");
	QAction * errAction		= ui.menuBar->addAction("Errors");
	QAction * cllAction		= ui.menuBar->addAction("Cll");
	QAction * clxAction		= ui.menuBar->addAction("Clx");
	QAction * causedAction	= ui.menuBar->addAction("Caused");
	QAction * rcvdAction	= ui.menuBar->addAction("Rcvd");

	_rl = new Log(this);
	_log = new Log(this);

	ui.errBox->setGeometry(ui.uniBox->geometry());
	ui.errBox->hide();
	ui.cllBox->setGeometry(ui.uniBox->geometry());
	ui.cllBox->hide();
	ui.clxBox->setGeometry(ui.uniBox->geometry());
	ui.clxBox->hide();
	ui.nilCausedBox->setGeometry(ui.uniBox->geometry());
	ui.nilCausedBox->hide();
	ui.nilRcvdBox->setGeometry(ui.uniBox->geometry());
	ui.nilRcvdBox->hide();

	connect(contestAction,		&QAction::triggered,	this,	&vlc::SelectContest);
	connect(uniAction,			&QAction::triggered,	this,	&vlc::ShowUnique);
	connect(errAction,			&QAction::triggered,	this,	&vlc::ShowError);
	connect(cllAction,			&QAction::triggered,	this,	&vlc::ShowCll);
	connect(clxAction,			&QAction::triggered,	this,	&vlc::ShowClx);
	connect(causedAction,		&QAction::triggered,	this,	&vlc::ShowCaused);
	connect(rcvdAction,			&QAction::triggered,	this,	&vlc::ShowRcvd);

	connect(ui.logView,			&QListView::pressed,	this,	&vlc::LogLineSelected);
	connect(ui.uniView,			&QListView::clicked,	this,	&vlc::UniLineSelected);
	connect(ui.uniView,			&QListView::activated,	this,	&vlc::UniLineSelected);
	connect(ui.rlCandidateView,	&QListView::entered,	this,	&vlc::UniCandidateLineSelected);

	ui.rlCandidateView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.uniView->setSelectionMode(QAbstractItemView::SingleSelection);

	_settings = new QSettings("K1EA Software", "Vlc", this);
	QString ctPath(_settings->value("Contest Directory").toString());
	
	_contestDir.cd(ctPath);
	_logDir	= _contestDir;
	_lgDir	= _contestDir;
	_resDir	= _contestDir;
	_rptDir	= _contestDir;
	_rlDir	= _contestDir;
	
	_lgDir .cd("lg");
	_logDir.cd("logs");
	_resDir.cd("results");
	_rptDir.cd("rpt");
	_rlDir .cd("rl");
	
	LoadLcDat();
}

void vlc::DisplayRlCandidates(Unique & unique)
{
	ui.label->setText("DISPLAY CANDIDATES");

	for (auto pair : unique.CandidateList())
	{
		Log rl;
		QString fileName = pair.second + ".rl";
		rl.ReadLogFile(_rlDir.filePath(fileName));
		Qso const * rq = rl.FindCloseQso(unique.UniqueQso());
		if (!rq)
			unique.RemoveCandidate(pair.second);
	}

	if (_rlCandidateModel) delete _rlCandidateModel;
	_rlCandidateModel = new RlCandidateModel(this, unique);
	ui.rlCandidateView->setModel(_rlCandidateModel);

	int count = _rlCandidateModel->rowCount(QModelIndex());
	ui.rlCandidateView->raise();
	ui.rlCandidateView->show();
}


void vlc::DisplayRl(QString fileName, Qso const * q = 0)
{
	ui.label->setText("DISPLAY RL");
	if (!_rlDir.exists(fileName))
		return;

	_rl->Clear();
	_rl->ReadLogFile(_rlDir.filePath(fileName));

	if (_rlFileModel)
		delete _rlFileModel;
	_rlFileModel = new LogModel(_rl);
	ui.rlView->setModel(_rlFileModel);
	
	if(q)
	{
		Qso const * rq = _rl->FindCloseQso(q);
		if (rq)
		{
			QModelIndex idx = _rlFileModel->index(rq->Row(), 0);
			ui.rlView->setCurrentIndex(idx);
			ui.rlView->scrollTo(idx, QAbstractItemView::PositionAtCenter);
			int diff = q->DateTime().secsTo(rq->DateTime());
			ui.label->setText(QString("Nearest RL QSO %1 minutes away").arg(diff/60));
		}
		else
			ui.label->setText(QString("No RL QSO found on %1").arg(q->Band().Name()));
	}
	ui.rlView->raise();
	ui.rlView->show();
}

void vlc::ShowUnique()	{ DisplayUniquesFile(_contestName); }
void vlc::ShowError()	{ DisplayErrorFile	(_contestName); }
void vlc::ShowCll()		{ DisplayCllFile	(_contestName); }
void vlc::ShowClx()		{ DisplayClxFile	(_contestName); }
void vlc::ShowCaused()	{ DisplayCausedFile	(_contestName); }
void vlc::ShowRcvd()	{ DisplayRcvdFile	(_contestName); }

void vlc::SelectContest()
{
	QString ctPath(_contestDir.canonicalPath());
	_contestDir.cd(QFileDialog::getExistingDirectory(this, "Select Contest Directory", ctPath, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
	ctPath = _contestDir.canonicalPath();
	_settings->setValue("Contest Directory", ctPath);
	_settings->sync();
	
	_lgDir.cd(ctPath	+ "/lg");
	_logDir.cd(ctPath	+ "/logs");
	_resDir.cd(ctPath	+ "/results");
	_rptDir.cd(ctPath	+ "/rpt");
	_rlDir.cd(ctPath	+ "/rl");

	ui.label->setText(QString("%1").arg(_contestDir.canonicalPath()));
}

void vlc::DisplayUniquesFile(QString fileName)
{
	if (_uniFileModel)
		delete _uniFileModel;
	_uniFileModel = new UniFileModel(this);

	QFile inFile(_resDir.filePath(fileName + ".uni"));
	bool res = inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream strm(&inFile);
	QString line;
	QString txt;

	while (!strm.atEnd())
	{
		QString line = strm.readLine();
		txt += line + '\n';
		line = line.simplified();
		QStringList parts = line.split(' ');

		//start of Unique
		if (parts.size() >= 8 && parts[0].toInt() != 0)
		{
			Qso * uniqueQso = new Qso(this, line);
			Unique unique(uniqueQso);

			while (!strm.atEnd())
			{
				QString line = strm.readLine().simplified();
				txt += line + '\n';
				if (line.isEmpty())
					break;

				QRegularExpression re("([A-Z0-9]+)\\s+\\(([0-9]+)\\)");
				QRegularExpressionMatch match;
				QString candidate;
				int		count(0);
				match = re.match(line);
				if (match.hasMatch())
				{
					candidate = match.captured(1);
					count = match.captured(2).toInt();
					unique.AddCandidate(candidate, count);
				}
			}
			_uniFileModel->AddUnique(unique);
		}
	}

	ui.uniView->setModel(_uniFileModel);
	ui.uniBox->setMinimumWidth(ui.uniView->sizeHintForColumn(0));
	HideBoxes();
	ui.uniBox->show();
}

void vlc::DisplayErrorFile(QString fileName)
{
	fileName += ".qso.err";
	if (!_resDir.exists(fileName))
		return;

	if (_errFileModel) delete _errFileModel;
	_errFileModel = new QStringListModel;
	_errFileModel->setStringList(ReadFileLines(_resDir.absoluteFilePath(fileName)));

	ui.errView->setModel(_errFileModel);
	HideBoxes();
	ui.errBox->show();
}

void vlc::DisplayCllFile(QString fileName)
{
	fileName += ".cll";
	if (!_resDir.exists(fileName))
		return;

	if (_cllFileModel) delete _cllFileModel;
	_cllFileModel = new QStringListModel;
	_cllFileModel->setStringList(ReadFileLines(_resDir.absoluteFilePath(fileName)));

	ui.cllView->setModel(_cllFileModel);
	HideBoxes();
	ui.cllBox->show();
}

void vlc::DisplayClxFile(QString fileName)
{
	fileName += ".clx";
	if (!_resDir.exists(fileName))
		return;

	if (_clxFileModel) delete _clxFileModel;
	_clxFileModel = new QStringListModel;
	_clxFileModel->setStringList(ReadFileLines(_resDir.absoluteFilePath(fileName)));

	ui.clxView->setModel(_clxFileModel);
	HideBoxes();
	ui.clxBox->show();
}

void vlc::DisplayCausedFile(QString fileName)
{
	fileName += ".nil_c";
	if (!_resDir.exists(fileName))
		return;

	if (_causedFileModel) delete _causedFileModel;
	_causedFileModel = new QStringListModel;
	_causedFileModel->setStringList(ReadFileLines(_resDir.absoluteFilePath(fileName)));

	ui.nilCausedView->setModel(_causedFileModel);
	HideBoxes();
	ui.nilCausedBox->show();
}

void vlc::DisplayRcvdFile(QString fileName)
{
	fileName += ".nil_r";
	if (!_resDir.exists(fileName))
		return;

	if (_rcvdFileModel) delete _rcvdFileModel;
	_rcvdFileModel = new QStringListModel;
	_rcvdFileModel->setStringList(ReadFileLines(_resDir.absoluteFilePath(fileName)));

	ui.nilRcvdView->setModel(_rcvdFileModel);
	HideBoxes();
	ui.nilRcvdBox->show();
}

void vlc::ErrorLineSelected(QModelIndex idx)
{
	QString text = idx.data(Qt::DisplayRole).toString();
	QStringList parts = text.split(' ', QString::SkipEmptyParts);

	if (parts.size() < 3)
		return;

	QString call = parts[0];
	int lineNum = parts[2].toInt();
	DisplayLog(_logDir.filePath(parts[0].toLower()));
	ui.logView->selectRow(lineNum);
}

void vlc::LogLineSelected(QModelIndex idx)
{
	QString text = idx.data(Qt::DisplayRole).toString();
	QStringList parts = text.split(' ', QString::SkipEmptyParts);

	if (parts.size() < 3)
		return;

	QString call = parts[0];
	int lineNum = parts[2].toInt();
	DisplayLog(_logDir.filePath(parts[0].toLower()));
	ui.logView->selectRow(lineNum);
}

void vlc::UniLineSelected(QModelIndex idx)
{
	ui.uniView->setCurrentIndex(idx);
	Unique unique = _uniFileModel->GetUnique(idx.row());
	DisplayRlCandidates(unique);
	ui.label->setText(QString("%1").arg("SELECTED"));
}

void vlc::UniCandidateLineSelected(QModelIndex idx)
{
	ui.rlCandidateView->setCurrentIndex(idx);
	QString candidateCall = _rlCandidateModel->GetCandidateCall(idx);
	QString fileName = candidateCall.toLower() +".rl";
	Qso const * q = _rlCandidateModel->GetUnique().UniqueQso();
	DisplayRl(fileName, q);
	ui.rlCandidateView->setFocus();
}

void vlc::DisplayLog(QString filename)
{
	if (!_logDir.exists(filename))
		return;

	_log->Clear();
	_log->ReadLogFile(_logDir.absoluteFilePath(filename));

	if (_logFileModel) delete _logFileModel;
	_logFileModel = new LogModel(_log);

	ui.logView->setModel(_logFileModel);
	//ui.logView->selectRow(lineNum);
	ui.logView->resizeColumnsToContents();
	ui.logView->raise();
	ui.logView->show();

	ui.label->setText(QString("%1").arg(filename));
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

void vlc::LoadLcDat()
{
	QString fileName("lc.dat");
	if (!_logDir.exists(fileName))
	{
		ui.label->setText("lc.dat not found");
		return;
	}

	QFile inFile(_logDir.filePath(fileName));
	inFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream strm(&inFile);
	while (!strm.atEnd())
	{
		QString line = strm.readLine();
		QStringList parts = line.split('=', QString::SkipEmptyParts);
		if (line.isEmpty() || parts.size() < 2)
			continue;
		QString tag = parts[0].trimmed();
		QString data = parts[1].trimmed();
		ui.msgView->append(QString("%1 %2").arg(tag, -13).arg(data));

		if (tag == "ContestType")	_contestType = data;
		if (tag == "NameOfContest")	_contestName = data.toLower();
		if (tag == "Title")			_contestTitle = data;
		if (tag == "StartTime")		_start = QDateTime::fromString(data, "yyyy-MM-dd hhmm");
		if (tag == "EndTime")		_end = QDateTime::fromString(data, "yyyy-MM-dd hhmm");
		if (tag == "Mode")			_contestMode = data;
	}
	ui.label->setText(QString("%1").arg(_contestName));
	ui.msgView->show();
}

void vlc::HideBoxes()
{
	ui.uniBox->hide();
	ui.errBox->hide();
	ui.cllBox->hide();
	ui.clxBox->hide();
	ui.nilCausedBox->hide();
	ui.nilRcvdBox->hide();
}
