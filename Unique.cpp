#include "stdafx.h"

void Unique::RemoveCandidate(QString candidate) 
{
	QMutableListIterator < QPair<int, QString > > it(_candidateList);

	while (it.hasNext())
	{
		auto pair = it.next();
		if (pair.second == candidate)
			it.remove();
	}
}
