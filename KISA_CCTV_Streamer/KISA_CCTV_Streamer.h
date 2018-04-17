#pragma once

#include <QtWidgets/QWidget>
#include "ui_KISA_CCTV_Streamer.h"

#include <QProcess>
#include <QTimer>

class KISA_CCTV_Streamer : public QWidget
{
	Q_OBJECT
	
public:
	KISA_CCTV_Streamer(QWidget *parent = Q_NULLPTR);

private:
	Ui::KISA_CCTV_StreamerClass ui;

private slots:
void on_openDirectory_pushButton_clicked();
void on_play_pushButton_clicked();
void on_process_checker_timeout();

private:
	QTimer process_checker;
	QProcess vlc;
	QString videos_dir_path;
	QStringList selected_video_names;
	QBrush old_brush;
	int play_index;
};
