#include "MapFile_Compare.h"
#include <qfiledialog.h>
#include <qxmlstream.h>
#include <qpainter.h>

MapFile_Compare::MapFile_Compare(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.mapview_widget->setVideoSize(QSize(1280, 720));
}


void MapFile_Compare::on_newMapOpen_pushButton_clicked()
{
	QString dir_path = QFileDialog::getExistingDirectory(this, tr("Open New .map Directory"), tr("D:/KISA"));

	if (!dir_path.isEmpty()) {
		newMap_dir_path = dir_path;

		QDir files_dir(dir_path);
		QStringList filters;
		filters << "*.map";
		files_dir.setNameFilters(filters);

		QStringList files = files_dir.entryList();

		ui.newMapFiles_listWidget->clear();

		for (auto f : files) {
			ui.newMapFiles_listWidget->addItem(f);
		}

		//ui.newMapFiles_listWidget->
	}
}

void MapFile_Compare::on_oldMapOpen_pushButton_clicked()
{
	QString dir_path = QFileDialog::getExistingDirectory(this, tr("Open Old .map Directory"), tr("D:/KISA"));

	if (!dir_path.isEmpty()) {
		oldMap_dir_path = dir_path;

		QDir files_dir(dir_path);
		QStringList filters;
		filters << "*.map";
		files_dir.setNameFilters(filters);

		QStringList files = files_dir.entryList();

		ui.oldMapFiles_listWidget->clear();

		for (auto f : files) {
			ui.oldMapFiles_listWidget->addItem(f);
		}
	}
}

void MapFile_Compare::on_newMapFiles_listWidget_itemSelectionChanged()
{
	on_newMapFiles_listWidget_itemClicked();
}

void MapFile_Compare::on_newMapFiles_listWidget_itemClicked()
{
	QList<QListWidgetItem*> selected_new_items =  ui.newMapFiles_listWidget->selectedItems();
	QString new_filename = selected_new_items.first()->text();

	QFile new_file(newMap_dir_path + "/" + new_filename);

	if (new_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		ui.newMap_textEdit->clear();
		ui.newMap_label->setText(new_filename);

		QByteArray new_text = new_file.readAll();
		ui.newMap_textEdit->append(new_text);

		ui.mapview_widget->clearDrawData();
		readMapFile(newMap_dir_path + "/" + new_filename, MapData::New);	
	}

	QList<QListWidgetItem*> found_old_items = ui.oldMapFiles_listWidget->findItems(new_filename, Qt::MatchFixedString);
	if (!found_old_items.empty()) {
		QString old_filename = found_old_items.first()->text();
		
		QFile old_file(oldMap_dir_path + "/" + old_filename);

		if (old_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			ui.oldMap_textEdit->clear();
			ui.oldMap_label->setText(old_filename);

			QByteArray old_text = old_file.readAll();
			ui.oldMap_textEdit->append(old_text);

			readMapFile(oldMap_dir_path + "/" + old_filename, MapData::Old);
		}
	}
	else {
		ui.oldMap_textEdit->clear();
		ui.oldMap_label->setText(tr("Not Found"));
	}

	ui.mapview_widget->update();
}

bool MapFile_Compare::readMapFile(QString filename, MapData::NewOld area_type)
{
	QXmlStreamReader xReader;

	QFile file(filename);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		//QMessageBox::information(NULL, "Map File Open", QString("%1 file open error : %2").arg(mapfile).arg(file.errorString()));
		return false;
	}

	xReader.setDevice(&file);
	xReader.readNext();
	QString noStr;

	while (!xReader.atEnd())
	{
		if (xReader.isStartElement())
		{
			QStringRef tag = xReader.name();
			if (tag == "DetectionAreas")
			{
				noStr = xReader.readElementText();
				xReader.readNext();
			}
			else if (tag == "Intrusion")		// 침입
			{
				MapData draw_data;
				draw_data.line_type = area_type;
				draw_data.color = MapData::Intrusion;

				xReader.readNext();
				while (!xReader.atEnd())
				{
					if (xReader.isStartElement())
					{
						if (xReader.name() == "Point")
						{
							QString pStr = xReader.readElementText();
							QStringList pts = pStr.split(",", QString::SkipEmptyParts);
							if (pts.size() == 2)
							{
								QPointF p(pts.at(0).toInt(), pts.at(1).toInt());
								draw_data.points << p;
							}
						}
						xReader.readNext();
					}
					else if (xReader.isEndElement())
					{
						QString aa = xReader.readElementText();
						xReader.readNext();
						break;
					}
					else
					{
						xReader.readNext();
					}
				}

				ui.mapview_widget->addDrawData(draw_data);
			}
			else if (tag == "Loitering")		// 배회
			{
				MapData draw_data;
				draw_data.line_type = area_type;
				draw_data.color = MapData::Loitering;

				xReader.readNext();
				while (!xReader.atEnd())
				{
					if (xReader.isStartElement())
					{
						if (xReader.name() == "Point")
						{
							QString pStr = xReader.readElementText();
							QStringList pts = pStr.split(",", QString::SkipEmptyParts);
							if (pts.size() == 2)
							{
								QPoint p(pts.at(0).toInt(), pts.at(1).toInt());
								draw_data.points << p;
							}
						}
						xReader.readNext();
					}
					else if (xReader.isEndElement())
					{
						QString aa = xReader.readElementText();
						xReader.readNext();
						break;
					}
					else
					{
						xReader.readNext();
					}
				}

				ui.mapview_widget->addDrawData(draw_data);
			}
			else if (tag == "DetectArea")		// trash
			{
				//if (noStr != "1")
				//{
				//	xReader.readNext();
				//	continue;
				//}

				MapData draw_data;
				draw_data.line_type = area_type;
				draw_data.color = MapData::DetectArea;

				xReader.readNext();
				while (!xReader.atEnd())
				{
					if (xReader.isStartElement())
					{
						if (xReader.name() == "Point")
						{
							QString pStr = xReader.readElementText();
							QStringList pts = pStr.split(",", QString::SkipEmptyParts);
							if (pts.size() == 2)
							{
								QPoint p(pts.at(0).toInt(), pts.at(1).toInt());
								draw_data.points << p;
							}
						}
						xReader.readNext();
					}
					else if (xReader.isEndElement())
					{
						QString aa = xReader.readElementText();
						xReader.readNext();
						break;
					}
					else
					{
						xReader.readNext();
					}
				}

				ui.mapview_widget->addDrawData(draw_data);
			}
			else
			{
				xReader.readNext();
			}
		}
		else
		{
			xReader.readNext();
		}
	}

	

	file.close();
	return true;
}