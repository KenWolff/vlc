#include "stdafx.h"
#include "vlc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	vlc w;
	w.show();
	return a.exec();
}
