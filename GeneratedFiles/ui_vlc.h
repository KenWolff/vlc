/********************************************************************************
** Form generated from reading UI file 'vlc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VLC_H
#define UI_VLC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vlcClass
{
public:
    QWidget *centralWidget;
    QSlider *horizontalSlider;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vlcClass)
    {
        if (vlcClass->objectName().isEmpty())
            vlcClass->setObjectName(QStringLiteral("vlcClass"));
        vlcClass->resize(1138, 924);
        vlcClass->setWindowTitle(QStringLiteral("vlc"));
        vlcClass->setWindowFilePath(QStringLiteral(""));
        centralWidget = new QWidget(vlcClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(330, 360, 241, 111));
        horizontalSlider->setOrientation(Qt::Horizontal);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(420, 600, 471, 141));
        progressBar->setValue(24);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 60, 641, 131));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setText(QStringLiteral("TextLabel"));

        horizontalLayout->addWidget(label_6);

        vlcClass->setCentralWidget(centralWidget);
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_4->raise();
        horizontalSlider->raise();
        progressBar->raise();
        menuBar = new QMenuBar(vlcClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1138, 31));
        vlcClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(vlcClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        vlcClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(vlcClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        vlcClass->setStatusBar(statusBar);

        retranslateUi(vlcClass);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(vlcClass);
    } // setupUi

    void retranslateUi(QMainWindow *vlcClass)
    {
        Q_UNUSED(vlcClass);
    } // retranslateUi

};

namespace Ui {
    class vlcClass: public Ui_vlcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VLC_H
