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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vlcClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *uniBox;
    QHBoxLayout *uniLayout;
    QListView *uniView;
    QGroupBox *rlBox;
    QVBoxLayout *rlLayout;
    QListView *rlView;
    QGroupBox *logBox;
    QVBoxLayout *logLayout;
    QTableView *logView;
    QGroupBox *candidateBox;
    QVBoxLayout *candidatesLayout;
    QListView *rlCandidateView;
    QGroupBox *msgBox;
    QVBoxLayout *msgLayout;
    QTextEdit *msgView;
    QGroupBox *cllBox;
    QVBoxLayout *cllLayout;
    QListView *cllView;
    QGroupBox *nilCausedBox;
    QVBoxLayout *nilCauseLayout;
    QListView *nilCausedView;
    QGroupBox *clxBox;
    QVBoxLayout *clxLayout;
    QListView *clxView;
    QGroupBox *nilRcvdBox;
    QVBoxLayout *nilRcvdLayout;
    QListView *nilRcvdView;
    QGroupBox *errBox;
    QHBoxLayout *errLayout;
    QListView *errView;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *vlcClass)
    {
        if (vlcClass->objectName().isEmpty())
            vlcClass->setObjectName(QStringLiteral("vlcClass"));
        vlcClass->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vlcClass->sizePolicy().hasHeightForWidth());
        vlcClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        vlcClass->setFont(font);
        vlcClass->setWindowTitle(QStringLiteral("Visual Log Checker"));
        vlcClass->setAutoFillBackground(true);
        vlcClass->setWindowFilePath(QStringLiteral(""));
        vlcClass->setAnimated(true);
        centralWidget = new QWidget(vlcClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 660, 881, 28));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 235, 164, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 245, 209, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(120, 117, 82, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(160, 157, 109, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label->setPalette(palette);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::Box);
        label->setLineWidth(2);
        label->setAlignment(Qt::AlignCenter);
        uniBox = new QGroupBox(centralWidget);
        uniBox->setObjectName(QStringLiteral("uniBox"));
        uniBox->setGeometry(QRect(20, 20, 911, 631));
        uniLayout = new QHBoxLayout(uniBox);
        uniLayout->setSpacing(6);
        uniLayout->setContentsMargins(11, 11, 11, 11);
        uniLayout->setObjectName(QStringLiteral("uniLayout"));
        uniView = new QListView(uniBox);
        uniView->setObjectName(QStringLiteral("uniView"));
        uniView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(uniView->sizePolicy().hasHeightForWidth());
        uniView->setSizePolicy(sizePolicy1);
        uniView->setMouseTracking(true);
        uniView->setAutoFillBackground(false);
        uniView->setFrameShape(QFrame::Box);
        uniView->setFrameShadow(QFrame::Plain);
        uniView->setLineWidth(2);
        uniView->setMidLineWidth(0);
        uniView->setAutoScrollMargin(2);
        uniView->setProperty("showDropIndicator", QVariant(true));
        uniView->setDragEnabled(false);
        uniView->setAlternatingRowColors(false);

        uniLayout->addWidget(uniView);

        rlBox = new QGroupBox(centralWidget);
        rlBox->setObjectName(QStringLiteral("rlBox"));
        rlBox->setGeometry(QRect(940, 20, 931, 631));
        rlLayout = new QVBoxLayout(rlBox);
        rlLayout->setSpacing(6);
        rlLayout->setContentsMargins(11, 11, 11, 11);
        rlLayout->setObjectName(QStringLiteral("rlLayout"));
        rlView = new QListView(rlBox);
        rlView->setObjectName(QStringLiteral("rlView"));
        rlView->setEnabled(true);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush7(QColor(127, 127, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush7);
        QBrush brush8(QColor(170, 170, 170, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush9(QColor(225, 225, 225, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        rlView->setPalette(palette1);
        rlView->setAutoFillBackground(false);
        rlView->setFrameShape(QFrame::Box);
        rlView->setFrameShadow(QFrame::Plain);
        rlView->setLineWidth(2);
        rlView->setMidLineWidth(0);
        rlView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        rlView->setAutoScrollMargin(2);
        rlView->setProperty("showDropIndicator", QVariant(true));
        rlView->setDragEnabled(false);
        rlView->setAlternatingRowColors(false);

        rlLayout->addWidget(rlView);

        logBox = new QGroupBox(centralWidget);
        logBox->setObjectName(QStringLiteral("logBox"));
        logBox->setGeometry(QRect(1080, 670, 791, 301));
        logLayout = new QVBoxLayout(logBox);
        logLayout->setSpacing(6);
        logLayout->setContentsMargins(11, 11, 11, 11);
        logLayout->setObjectName(QStringLiteral("logLayout"));
        logView = new QTableView(logBox);
        logView->setObjectName(QStringLiteral("logView"));
        logView->setEnabled(true);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        logView->setPalette(palette2);
        logView->setAutoFillBackground(false);
        logView->setFrameShape(QFrame::Box);
        logView->setFrameShadow(QFrame::Plain);
        logView->setLineWidth(2);
        logView->setMidLineWidth(0);
        logView->setAutoScrollMargin(2);
        logView->setProperty("showDropIndicator", QVariant(true));
        logView->setDragEnabled(false);
        logView->setAlternatingRowColors(false);
        logView->setShowGrid(false);
        logView->setGridStyle(Qt::SolidLine);
        logView->setCornerButtonEnabled(true);
        logView->horizontalHeader()->setVisible(true);
        logView->verticalHeader()->setVisible(false);

        logLayout->addWidget(logView);

        candidateBox = new QGroupBox(centralWidget);
        candidateBox->setObjectName(QStringLiteral("candidateBox"));
        candidateBox->setGeometry(QRect(20, 730, 461, 241));
        candidatesLayout = new QVBoxLayout(candidateBox);
        candidatesLayout->setSpacing(6);
        candidatesLayout->setContentsMargins(11, 11, 11, 11);
        candidatesLayout->setObjectName(QStringLiteral("candidatesLayout"));
        rlCandidateView = new QListView(candidateBox);
        rlCandidateView->setObjectName(QStringLiteral("rlCandidateView"));
        rlCandidateView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rlCandidateView->sizePolicy().hasHeightForWidth());
        rlCandidateView->setSizePolicy(sizePolicy2);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        rlCandidateView->setPalette(palette3);
        rlCandidateView->setMouseTracking(true);
        rlCandidateView->setToolTipDuration(9);
        rlCandidateView->setAutoFillBackground(false);
        rlCandidateView->setFrameShape(QFrame::Box);
        rlCandidateView->setFrameShadow(QFrame::Plain);
        rlCandidateView->setLineWidth(2);
        rlCandidateView->setMidLineWidth(0);
        rlCandidateView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        rlCandidateView->setAutoScrollMargin(2);
        rlCandidateView->setProperty("showDropIndicator", QVariant(true));
        rlCandidateView->setDragEnabled(false);
        rlCandidateView->setAlternatingRowColors(false);
        rlCandidateView->setMovement(QListView::Static);
        rlCandidateView->setResizeMode(QListView::Adjust);
        rlCandidateView->setUniformItemSizes(false);
        rlCandidateView->setSelectionRectVisible(true);

        candidatesLayout->addWidget(rlCandidateView);

        msgBox = new QGroupBox(centralWidget);
        msgBox->setObjectName(QStringLiteral("msgBox"));
        msgBox->setGeometry(QRect(510, 730, 551, 241));
        msgLayout = new QVBoxLayout(msgBox);
        msgLayout->setSpacing(6);
        msgLayout->setContentsMargins(11, 11, 11, 11);
        msgLayout->setObjectName(QStringLiteral("msgLayout"));
        msgView = new QTextEdit(msgBox);
        msgView->setObjectName(QStringLiteral("msgView"));
        msgView->setFrameShape(QFrame::Box);
        msgView->setFrameShadow(QFrame::Plain);
        msgView->setLineWidth(2);

        msgLayout->addWidget(msgView);

        cllBox = new QGroupBox(centralWidget);
        cllBox->setObjectName(QStringLiteral("cllBox"));
        cllBox->setGeometry(QRect(80, 1010, 288, 252));
        cllLayout = new QVBoxLayout(cllBox);
        cllLayout->setSpacing(6);
        cllLayout->setContentsMargins(11, 11, 11, 11);
        cllLayout->setObjectName(QStringLiteral("cllLayout"));
        cllView = new QListView(cllBox);
        cllView->setObjectName(QStringLiteral("cllView"));
        cllView->setFrameShape(QFrame::Panel);
        cllView->setFrameShadow(QFrame::Plain);
        cllView->setLineWidth(2);

        cllLayout->addWidget(cllView);

        nilCausedBox = new QGroupBox(centralWidget);
        nilCausedBox->setObjectName(QStringLiteral("nilCausedBox"));
        nilCausedBox->setGeometry(QRect(100, 1300, 288, 252));
        nilCauseLayout = new QVBoxLayout(nilCausedBox);
        nilCauseLayout->setSpacing(6);
        nilCauseLayout->setContentsMargins(11, 11, 11, 11);
        nilCauseLayout->setObjectName(QStringLiteral("nilCauseLayout"));
        nilCausedView = new QListView(nilCausedBox);
        nilCausedView->setObjectName(QStringLiteral("nilCausedView"));
        nilCausedView->setFrameShape(QFrame::Panel);
        nilCausedView->setFrameShadow(QFrame::Plain);
        nilCausedView->setLineWidth(2);

        nilCauseLayout->addWidget(nilCausedView);

        clxBox = new QGroupBox(centralWidget);
        clxBox->setObjectName(QStringLiteral("clxBox"));
        clxBox->setGeometry(QRect(450, 1020, 288, 252));
        clxLayout = new QVBoxLayout(clxBox);
        clxLayout->setSpacing(6);
        clxLayout->setContentsMargins(11, 11, 11, 11);
        clxLayout->setObjectName(QStringLiteral("clxLayout"));
        clxView = new QListView(clxBox);
        clxView->setObjectName(QStringLiteral("clxView"));
        clxView->setFrameShape(QFrame::Panel);
        clxView->setFrameShadow(QFrame::Plain);
        clxView->setLineWidth(2);

        clxLayout->addWidget(clxView);

        nilRcvdBox = new QGroupBox(centralWidget);
        nilRcvdBox->setObjectName(QStringLiteral("nilRcvdBox"));
        nilRcvdBox->setGeometry(QRect(440, 1300, 288, 252));
        nilRcvdLayout = new QVBoxLayout(nilRcvdBox);
        nilRcvdLayout->setSpacing(6);
        nilRcvdLayout->setContentsMargins(11, 11, 11, 11);
        nilRcvdLayout->setObjectName(QStringLiteral("nilRcvdLayout"));
        nilRcvdView = new QListView(nilRcvdBox);
        nilRcvdView->setObjectName(QStringLiteral("nilRcvdView"));
        nilRcvdView->setFrameShape(QFrame::Panel);
        nilRcvdView->setFrameShadow(QFrame::Plain);
        nilRcvdView->setLineWidth(2);

        nilRcvdLayout->addWidget(nilRcvdView);

        errBox = new QGroupBox(centralWidget);
        errBox->setObjectName(QStringLiteral("errBox"));
        errBox->setGeometry(QRect(990, 1010, 911, 631));
        errLayout = new QHBoxLayout(errBox);
        errLayout->setSpacing(6);
        errLayout->setContentsMargins(11, 11, 11, 11);
        errLayout->setObjectName(QStringLiteral("errLayout"));
        errView = new QListView(errBox);
        errView->setObjectName(QStringLiteral("errView"));
        errView->setEnabled(true);
        sizePolicy1.setHeightForWidth(errView->sizePolicy().hasHeightForWidth());
        errView->setSizePolicy(sizePolicy1);
        errView->setMouseTracking(true);
        errView->setAutoFillBackground(false);
        errView->setFrameShape(QFrame::Box);
        errView->setFrameShadow(QFrame::Plain);
        errView->setLineWidth(2);
        errView->setMidLineWidth(0);
        errView->setAutoScrollMargin(2);
        errView->setProperty("showDropIndicator", QVariant(true));
        errView->setDragEnabled(false);
        errView->setAlternatingRowColors(false);
        errView->setMovement(QListView::Free);

        errLayout->addWidget(errView);

        vlcClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vlcClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 44));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        menuBar->setFont(font1);
        menuBar->setNativeMenuBar(false);
        vlcClass->setMenuBar(menuBar);

        retranslateUi(vlcClass);

        QMetaObject::connectSlotsByName(vlcClass);
    } // setupUi

    void retranslateUi(QMainWindow *vlcClass)
    {
        label->setText(QApplication::translate("vlcClass", "test", Q_NULLPTR));
        uniBox->setTitle(QApplication::translate("vlcClass", "Uniques", Q_NULLPTR));
        rlBox->setTitle(QApplication::translate("vlcClass", "Reverse Log", Q_NULLPTR));
        logBox->setTitle(QApplication::translate("vlcClass", "Log", Q_NULLPTR));
        candidateBox->setTitle(QApplication::translate("vlcClass", "Candidates", Q_NULLPTR));
        msgBox->setTitle(QApplication::translate("vlcClass", "Messages", Q_NULLPTR));
        cllBox->setTitle(QApplication::translate("vlcClass", "CLL", Q_NULLPTR));
        nilCausedBox->setTitle(QApplication::translate("vlcClass", "Nil Caused", Q_NULLPTR));
        clxBox->setTitle(QApplication::translate("vlcClass", "CLX", Q_NULLPTR));
        nilRcvdBox->setTitle(QApplication::translate("vlcClass", "NIL Rcvd", Q_NULLPTR));
        errBox->setTitle(QApplication::translate("vlcClass", "QSO Errors", Q_NULLPTR));
        Q_UNUSED(vlcClass);
    } // retranslateUi

};

namespace Ui {
    class vlcClass: public Ui_vlcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VLC_H
