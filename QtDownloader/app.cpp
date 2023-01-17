#include "app.h"

#include "ui_app.h"

// Qt
#include <qstring.h>

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextEdit>

#include "core/ytdlp.h"
#include "ui/datarow.h"

App::App(QWidget *parent) : QMainWindow(parent), ui(new Ui::App) {
    initUi();

    // add input area to the top-left corner
    mainLayout->addWidget(inputArea, 0, 0, 0, 2);

    QPushButton *downloadButton = new QPushButton(tr("Download"), this);

    mainLayout->addWidget(downloadButton, 1, 1);

    QProgressBar *progressBar = new QProgressBar(this);
    mainLayout->addWidget(progressBar, 1, 0);

    // Set the stretch factor for the rows and columns in the mainLayout
    mainLayout->setRowStretch(0, 2);
    mainLayout->setRowStretch(1, 0);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 1);

    connect(downloadButton, SIGNAL(clicked()), this, SLOT(download()));
}

App::~App() { delete ui; }

void App::initUi() {
    ui->setupUi(this);
    this->setWindowTitle(tr("QtDownloader"));

    mainLayout = new QGridLayout(this);

    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(mainLayout);

    inputArea = new QTableWidget(this);
    inputArea->setColumnCount(6);
    inputArea->setHorizontalHeaderLabels({
        QStringLiteral("網址"),
        QStringLiteral("進度"),
        QStringLiteral("大小"),
        QStringLiteral("類型"),
        QStringLiteral("位置"),
        QStringLiteral("下載"),
    });

    inputArea->insertRow(0);  // 新增一列
    QTableWidgetItem *item = new QTableWidgetItem(
        "https://youtu.be/uh8U9_2SLCk" + QString::number(0));
    inputArea->setItem(0, 0, item);  // 第 0 列第 0 欄放入 URL

    QProgressBar *progressBar = new QProgressBar();
    inputArea->setCellWidget(0, 1,
                             progressBar);  // 第 0 列第 1 欄放入進度條

    QTableWidgetItem *size = new QTableWidgetItem("0MB");
    inputArea->setItem(0, 2, size);  // 第 0 列第 2 欄放入檔案大小

    QTableWidgetItem *format = new QTableWidgetItem("mp4");
    inputArea->setItem(0, 3, format);  // 第 0 列第 3 欄放入檔案格式

    QLineEdit *downloadLocation = new QLineEdit(this);
    inputArea->setCellWidget(0, 4, downloadLocation);

    auto a = new DataRow(inputArea);
    // inputArea->insertRow(1);  // 新增一列
    // inputArea->setCellWidget(1, 4, new DownloadLocation(this));

    QPushButton *downloadBtn = new QPushButton();
    downloadBtn->setText(QStringLiteral("準備中"));
    inputArea->setCellWidget(0, 5, downloadBtn);

    inputArea->resizeColumnsToContents();
    inputArea->resizeRowsToContents();
}

void App::download() {
    // QString url = inputArea->toPlainText();
    QString url = "https://youtu.be/uh8U9_2SLCk";
    qDebug() << url;
    YtDlp *dl = new YtDlp();
    dl->download(url);
}