#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vlc.h"

class vlc : public QMainWindow
{
	Q_OBJECT

public:
	vlc(QWidget *parent = Q_NULLPTR);

private:
	Ui::vlcClass ui;
};
