#include "KISA_CCTV_Streamer.h"
#include <QFileDialog>
#include <QTableWidget>
#include <QTime>
#include <QDebug>

KISA_CCTV_Streamer::KISA_CCTV_Streamer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	vlc.setProgram("\"C:/Program Files (x86)/VideoLAN/VLC/vlc.exe\"");
	play_index = 0;


	connect(&process_checker, SIGNAL(timeout()), this, SLOT(on_process_checker_timeout()));

	/////////////////////////////////////////////////////////////////
	// TableWidget ¼³Á¤
	ui.videoFile_tableWidget->clear();
	ui.videoFile_tableWidget->setColumnCount(4);
	QTableWidgetItem *headerItem_0 = new QTableWidgetItem(tr("File name"));
	ui.videoFile_tableWidget->setHorizontalHeaderItem(0, headerItem_0);
	QTableWidgetItem *headerItem_1 = new QTableWidgetItem(tr("Site"));
	ui.videoFile_tableWidget->setHorizontalHeaderItem(1, headerItem_1);
	QTableWidgetItem *headerItem_2 = new QTableWidgetItem(tr("Time"));
	ui.videoFile_tableWidget->setHorizontalHeaderItem(2, headerItem_2);
	QTableWidgetItem *headerItem_3 = new QTableWidgetItem(tr("Result"));
	ui.videoFile_tableWidget->setHorizontalHeaderItem(3, headerItem_3);
	ui.videoFile_tableWidget->resizeColumnsToContents();
	/////////////////////////////////////////////////////////////////
}

void KISA_CCTV_Streamer::on_openDirectory_pushButton_clicked()
{
	qDebug() << "C++ Style Debug Message";

	QString dir_path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		tr("C:/kisaDB"));
	
	if (!dir_path.isEmpty()) {
		videos_dir_path = dir_path;

		QDir filesOfDir(dir_path);
		QStringList filters;
		filters << "*.mp4";
		filesOfDir.setNameFilters(filters);

		QStringList files = filesOfDir.entryList();

		ui.videoFile_tableWidget->clearContents();
		ui.videoFile_tableWidget->setRowCount(files.size());
				
		for(int i = 0; i < files.size(); ++i)
		{
			QString file_name = files[i];
			
			if(file_name.length() < 15)
				continue;

			QStringRef site_num_str(&file_name, 5, 2);
			QTableWidgetItem *site_num_item = new QTableWidgetItem(site_num_str.toString());
			ui.videoFile_tableWidget->setItem(i, 1, site_num_item);

			QTableWidgetItem *newItem = new QTableWidgetItem(files[i]);
			ui.videoFile_tableWidget->setItem(i, 0, newItem);
		}

		ui.videoFile_tableWidget->resizeColumnsToContents();
	}
}


void KISA_CCTV_Streamer::on_play_pushButton_clicked()
{
	auto selected_videos = ui.videoFile_tableWidget->selectedItems();
	
	ui.videoFile_listWidget->clear();
	selected_video_names.clear();

	for (auto item : selected_videos) {
		int num = item->column();
		if (0 == num) {
			ui.videoFile_listWidget->addItem(item->text());
			selected_video_names.append(item->text());
		}
	}


	if (!selected_video_names.empty()) {
		// 	- vvv C : \kisaDB\C001101_001.mp4 --play - and-exit :sout = #rtp{ sdp = rtsp://:8554/} :sout-keep
		QString video_path_str = tr("C:\\kisaDB\\") + selected_video_names[play_index];
		vlc.setArguments(QStringList() << "-vvv" << video_path_str << "--play-and-exit" << ":sout=#rtp{sdp=rtsp://:8554/}" << ":sout-keep");
		vlc.start();

		old_brush = ui.videoFile_listWidget->item(play_index)->foreground();
		ui.videoFile_listWidget->item(play_index)->setForeground(QBrush(QColor(255, 0, 0)));


		process_checker.start(1000);
	}
}

void KISA_CCTV_Streamer::on_process_checker_timeout() 
{
	QProcess::ProcessState vlc_state =  vlc.state();
	
	QTime current_time;
	current_time = QTime::currentTime();
	QString list_item_str = current_time.toString();

	switch (vlc_state) {
	case QProcess::NotRunning:
		list_item_str.append("NotRunning");
		break;
	case QProcess::Starting:
		list_item_str.append("Starting");
		break;
	case QProcess::Running:
		list_item_str.append("Running");
		break;
	}

	if (QProcess::NotRunning == vlc_state) {
		ui.videoFile_listWidget->item(play_index)->setForeground(old_brush);
		play_index++;

		if (selected_video_names.size() == play_index) {
			process_checker.stop();
		}
		else {
			QString video_path_str = tr("C:\\kisaDB\\") + selected_video_names[play_index];
			vlc.setArguments(QStringList() << "-vvv" << video_path_str << "--play-and-exit" << ":sout=#rtp{sdp=rtsp://:8554/}" << ":sout-keep");
			vlc.start();

			ui.videoFile_listWidget->item(play_index)->setBackground(QBrush(QColor(255, 0, 0)));
		}
	}


	//ui.videoFile_listWidget->addItem(list_item_str);
}