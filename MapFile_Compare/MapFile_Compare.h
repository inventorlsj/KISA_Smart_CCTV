#pragma once

#include <QtWidgets/QWidget>
#include "ui_MapFile_Compare.h"

class MapFile_Compare : public QWidget
{
	Q_OBJECT

public:
	MapFile_Compare(QWidget *parent = Q_NULLPTR);

protected:
	bool readMapFile(QString filename, MapData::NewOld area_type);

private:
	Ui::MapFile_CompareClass ui;

	QString newMap_dir_path;
	QString oldMap_dir_path;

private slots:
void on_newMapOpen_pushButton_clicked();
void on_oldMapOpen_pushButton_clicked();
void on_newMapFiles_listWidget_itemClicked();
void on_newMapFiles_listWidget_itemSelectionChanged();
};
