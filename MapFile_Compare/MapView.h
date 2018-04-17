#pragma once

#include <QtWidgets/QWidget>

struct MapData {
	enum NewOld {
		New, Old
	};
	enum AreaType{
		DetectArea, Loitering, Intrusion
	};

	NewOld line_type;
	AreaType color;
	QPolygonF points;
};

class MapView : public QWidget
{
	Q_OBJECT

public:
	MapView(QWidget *parent = Q_NULLPTR);
	~MapView();

	void addDrawData(const MapData &in_data);
	void clearDrawData();
	void setVideoSize(const QSize in_size) {
		video_size = in_size;
	};

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	QList<MapData> draw_datas;
	QSize video_size;
};
