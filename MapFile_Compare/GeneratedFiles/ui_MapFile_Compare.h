/********************************************************************************
** Form generated from reading UI file 'MapFile_Compare.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPFILE_COMPARE_H
#define UI_MAPFILE_COMPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mapview.h>

QT_BEGIN_NAMESPACE

class Ui_MapFile_CompareClass
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *newMapOpen_pushButton;
    QListWidget *newMapFiles_listWidget;
    QGridLayout *gridLayout;
    QTextEdit *oldMap_textEdit;
    QTextEdit *newMap_textEdit;
    QLabel *oldMap_label;
    QLabel *newMap_label;
    QFrame *line;
    MapView *mapview_widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *oldMapOpen_pushButton;
    QListWidget *oldMapFiles_listWidget;

    void setupUi(QWidget *MapFile_CompareClass)
    {
        if (MapFile_CompareClass->objectName().isEmpty())
            MapFile_CompareClass->setObjectName(QStringLiteral("MapFile_CompareClass"));
        MapFile_CompareClass->resize(1082, 661);
        horizontalLayout = new QHBoxLayout(MapFile_CompareClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        newMapOpen_pushButton = new QPushButton(MapFile_CompareClass);
        newMapOpen_pushButton->setObjectName(QStringLiteral("newMapOpen_pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newMapOpen_pushButton->sizePolicy().hasHeightForWidth());
        newMapOpen_pushButton->setSizePolicy(sizePolicy);
        newMapOpen_pushButton->setMinimumSize(QSize(120, 0));
        newMapOpen_pushButton->setMaximumSize(QSize(120, 16777215));

        verticalLayout->addWidget(newMapOpen_pushButton);

        newMapFiles_listWidget = new QListWidget(MapFile_CompareClass);
        newMapFiles_listWidget->setObjectName(QStringLiteral("newMapFiles_listWidget"));
        newMapFiles_listWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newMapFiles_listWidget->sizePolicy().hasHeightForWidth());
        newMapFiles_listWidget->setSizePolicy(sizePolicy1);
        newMapFiles_listWidget->setMinimumSize(QSize(120, 0));
        newMapFiles_listWidget->setMaximumSize(QSize(120, 16777215));

        verticalLayout->addWidget(newMapFiles_listWidget);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        oldMap_textEdit = new QTextEdit(MapFile_CompareClass);
        oldMap_textEdit->setObjectName(QStringLiteral("oldMap_textEdit"));

        gridLayout->addWidget(oldMap_textEdit, 1, 2, 1, 1);

        newMap_textEdit = new QTextEdit(MapFile_CompareClass);
        newMap_textEdit->setObjectName(QStringLiteral("newMap_textEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(newMap_textEdit->sizePolicy().hasHeightForWidth());
        newMap_textEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(newMap_textEdit, 1, 0, 1, 1);

        oldMap_label = new QLabel(MapFile_CompareClass);
        oldMap_label->setObjectName(QStringLiteral("oldMap_label"));
        oldMap_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(oldMap_label, 0, 2, 1, 1);

        newMap_label = new QLabel(MapFile_CompareClass);
        newMap_label->setObjectName(QStringLiteral("newMap_label"));
        newMap_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(newMap_label, 0, 0, 1, 1);

        line = new QFrame(MapFile_CompareClass);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setLineWidth(1);
        line->setMidLineWidth(5);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 2, 1);

        mapview_widget = new MapView(MapFile_CompareClass);
        mapview_widget->setObjectName(QStringLiteral("mapview_widget"));
        mapview_widget->setAutoFillBackground(true);

        gridLayout->addWidget(mapview_widget, 2, 0, 1, 3);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 2);

        horizontalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        oldMapOpen_pushButton = new QPushButton(MapFile_CompareClass);
        oldMapOpen_pushButton->setObjectName(QStringLiteral("oldMapOpen_pushButton"));
        sizePolicy.setHeightForWidth(oldMapOpen_pushButton->sizePolicy().hasHeightForWidth());
        oldMapOpen_pushButton->setSizePolicy(sizePolicy);
        oldMapOpen_pushButton->setMinimumSize(QSize(120, 0));
        oldMapOpen_pushButton->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(oldMapOpen_pushButton);

        oldMapFiles_listWidget = new QListWidget(MapFile_CompareClass);
        oldMapFiles_listWidget->setObjectName(QStringLiteral("oldMapFiles_listWidget"));
        sizePolicy1.setHeightForWidth(oldMapFiles_listWidget->sizePolicy().hasHeightForWidth());
        oldMapFiles_listWidget->setSizePolicy(sizePolicy1);
        oldMapFiles_listWidget->setMinimumSize(QSize(120, 0));
        oldMapFiles_listWidget->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(oldMapFiles_listWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(MapFile_CompareClass);

        QMetaObject::connectSlotsByName(MapFile_CompareClass);
    } // setupUi

    void retranslateUi(QWidget *MapFile_CompareClass)
    {
        MapFile_CompareClass->setWindowTitle(QApplication::translate("MapFile_CompareClass", "MapFile_Compare", nullptr));
        newMapOpen_pushButton->setText(QApplication::translate("MapFile_CompareClass", "\354\203\210 \352\262\203", nullptr));
        oldMap_label->setText(QApplication::translate("MapFile_CompareClass", "Old Map", nullptr));
        newMap_label->setText(QApplication::translate("MapFile_CompareClass", "New Map", nullptr));
        oldMapOpen_pushButton->setText(QApplication::translate("MapFile_CompareClass", "\355\227\214 \352\262\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapFile_CompareClass: public Ui_MapFile_CompareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPFILE_COMPARE_H
