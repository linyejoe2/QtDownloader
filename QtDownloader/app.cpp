#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::App)
{
	ui->setupUi(this);
	this->setWindowTitle(QStringLiteral("QtDownloader"));
}

App::~App()
{
	delete ui;
}
