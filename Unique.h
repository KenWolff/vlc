#pragma once
class Qso;

class Unique
{
public:
	Unique(Qso * testQso) : _uniqueQso(testQso) {}
	Unique() {}
	~Unique() {}
			
	int			CandidateCount	()					const	{ return _candidateList.size(); }
	QVariant	GetCandidateStr	(QModelIndex idx)	const	{ return QString("%1  %2").arg(_candidateList.at(idx.row()).second, -12).arg(_candidateList.at(idx.row()).first, 4); }
	QString		GetCandidateCall(QModelIndex idx)	const	{ return QString("%1").arg(_candidateList.at(idx.row()).second); }
	Qso const *	UniqueQso()							const	{ return _uniqueQso; }
	QString		ToString()							const	{ return _uniqueQso->ToString(); }
	
	void		AddCandidate(QString candidate, int count) { _candidateList.append(QPair <int, QString>(count, candidate)); }
	void		RemoveCandidate(QString candidate);
	QList < QPair<int, QString > >	CandidateList()	const { return _candidateList; }

private:
	Qso *							_uniqueQso;
	QList < QPair<int, QString > >	_candidateList;
};

