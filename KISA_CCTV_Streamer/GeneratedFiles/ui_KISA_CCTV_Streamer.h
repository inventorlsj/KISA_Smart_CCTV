/********************************************************************************
** Form generated from reading UI file 'KISA_CCTV_Streamer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KISA_CCTV_STREAMER_H
#define UI_KISA_CCTV_STREAMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KISA_CCTV_StreamerClass
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *videoFile_listWidget;
    QTableWidget *videoFile_tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *openDirectory_pushButton;
    QPushButton *play_pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *KISA_CCTV_StreamerClass)
    {
        if (KISA_CCTV_StreamerClass->objectName().isEmpty())
            KISA_CCTV_StreamerClass->setObjectName(QStringLiteral("KISA_CCTV_StreamerClass"));
        KISA_CCTV_StreamerClass->resize(655, 400);
        horizontalLayout = new QHBoxLayout(KISA_CCTV_StreamerClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        videoFile_listWidget = new QListWidget(KISA_CCTV_StreamerClass);
        videoFile_listWidget->setObjectName(QStringLiteral("videoFile_listWidget"));
        videoFile_listWidget->setAlternatingRowColors(false);
        videoFile_listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        horizontalLayout->addWidget(videoFile_listWidget);

        videoFile_tableWidget = new QTableWidget(KISA_CCTV_StreamerClass);
        if (videoFile_tableWidget->columnCount() < 3)
            videoFile_tableWidget->setColumnCount(3);
        videoFile_tableWidget->setObjectName(QStringLiteral("videoFile_tableWidget"));
        videoFile_tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        videoFile_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        videoFile_tableWidget->setSortingEnabled(true);
        videoFile_tableWidget->setColumnCount(3);
        videoFile_tableWidget->horizontalHeader()->setCascadingSectionResizes(true);

        horizontalLayout->addWidget(videoFile_tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openDirectory_pushButton = new QPushButton(KISA_CCTV_StreamerClass);
        openDirectory_pushButton->setObjectName(QStringLiteral("openDirectory_pushButton"));
        openDirectory_pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(openDirectory_pushButton);

        play_pushButton = new QPushButton(KISA_CCTV_StreamerClass);
        play_pushButton->setObjectName(QStringLiteral("play_pushButton"));

        verticalLayout->addWidget(play_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(KISA_CCTV_StreamerClass);

        QMetaObject::connectSlotsByName(KISA_CCTV_StreamerClass);
    } // setupUi

    void retranslateUi(QWidget *KISA_CCTV_StreamerClass)
    {
        KISA_CCTV_StreamerClass->setWindowTitle(QApplication::translate("KISA_CCTV_StreamerClass", "KISA_CCTV_Streamer", nullptr));
        openDirectory_pushButton->setText(QApplication::translate("KISA_CCTV_StreamerClass", "\353\224\224\353\240\211\355\206\240\353\246\254 \354\204\240\355\203\235", nullptr));
        play_pushButton->setText(QApplication::translate("KISA_CCTV_StreamerClass", "\354\236\254\354\203\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KISA_CCTV_StreamerClass: public Ui_KISA_CCTV_StreamerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KISA_CCTV_STREAMER_H
