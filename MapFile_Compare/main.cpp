#pragma comment(lib, "qtmain.lib")
#pragma comment(lib, "Qt5Core.lib")
#pragma comment(lib, "Qt5Gui.lib")
#pragma comment(lib, "Qt5Widgets.lib")
#pragma comment(lib, "qtlibpng.lib")
#pragma comment(lib, "qtharfbuzz.lib")
#pragma comment(lib, "qtpcre2.lib")
#pragma comment(lib, "qtfreetype.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"Version.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"netapi32.lib")
#pragma comment(lib,"Userenv.lib")
#pragma comment(lib,"platforms/qwindows.lib")
#pragma comment(lib,"Qt5PlatformCompositorSupport.lib")
#pragma comment(lib,"Qt5FontDatabaseSupport.lib")
#pragma comment(lib,"Qt5EventDispatcherSupport.lib")
#pragma comment(lib,"Qt5ThemeSupport.lib")
#pragma comment(lib,"Qt5AccessibilitySupport.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"imm32.lib")
#pragma comment(lib,"Dwmapi.lib")
//#pragma comment(lib,"Qt5PlatformSupport.lib")
#pragma comment(lib,"qwindows.lib")

#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);


#include "MapFile_Compare.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MapFile_Compare w;
	w.show();
	return a.exec();
}
