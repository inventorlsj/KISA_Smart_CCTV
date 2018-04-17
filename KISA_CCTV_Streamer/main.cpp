#include "KISA_CCTV_Streamer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KISA_CCTV_Streamer w;
	w.show();
	return a.exec();
}
