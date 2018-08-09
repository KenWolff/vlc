#include "stdafx.h"
#include "vlc.h"

int main(int argc, char *argv[])
{
	QApplication::setStyle(QStyleFactory::create("windows"));
	QApplication a(argc, argv);
	vlc w;
	w.show();

	return a.exec();
}
