#include "MapView.h"
#include <QPainter>

MapView::MapView(QWidget *parent)
	: QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
}

MapView::~MapView()
{
}


void MapView::addDrawData(const MapData &in_data)
{
	draw_datas.append(in_data);
}

void MapView::clearDrawData()
{
	draw_datas.clear();
}

void MapView::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	QPen pen;

	QSize widgetsize = this->size();
	painter.scale(qreal(widgetsize.width()) / qreal(video_size.width()), qreal(widgetsize.height()) / qreal(video_size.height()));


	for (auto &d : draw_datas) {
		switch (d.line_type)
		{
		case MapData::New:
			pen.setStyle(Qt::PenStyle::SolidLine);
			pen.setWidth(2);
			break;
		case MapData::Old:
			pen.setStyle(Qt::PenStyle::DotLine);
			pen.setWidth(4);
			break;
		default:
			pen.setStyle(Qt::PenStyle::SolidLine);
			pen.setWidth(2);
			break;
		}

		switch (d.color)
		{
		case MapData::DetectArea:
			pen.setColor(Qt::black);
			break;
		case MapData::Intrusion:
			pen.setColor(Qt::red);
			break;
		case MapData::Loitering:
			pen.setColor(Qt::blue);
			break;
		default:
			pen.setColor(Qt::black);
			break;
		}

		painter.setPen(pen);

		painter.drawPolygon(d.points);
	}

	painter.end();
}