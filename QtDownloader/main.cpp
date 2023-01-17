#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication::setStyle("Fusion");
	QApplication a(argc, argv);
	App w;
	w.show();
	return a.exec();
}
