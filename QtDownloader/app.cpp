#include "app.h"

#include "ui_app.h"

// Qt
#include <qstring.h>

#include <QDebug>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>

#include "core/ytdlp.h"

App::App(QWidget *parent) : QMainWindow(parent), ui(new Ui::App) {
    ui->setupUi(this);
    this->setWindowTitle(tr("QtDownloader"));

    QGridLayout *layout = new QGridLayout(this);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSizeConstraint(QLayout::SetNoConstraint);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);

    inputArea = new QTextEdit(this);
    // add input area to the top-left corner
    layout->addWidget(inputArea, 0, 0);

    QGroupBox *adjustmentArea = new QGroupBox(tr("Adjustment"), this);
    QVBoxLayout *adjustmentLayout = new QVBoxLayout(adjustmentArea);

    QRadioButton *qualityOption =
        new QRadioButton(tr("Quality"), adjustmentArea);
    adjustmentLayout->addWidget(qualityOption);

    QRadioButton *formatOption = new QRadioButton(tr("Format"), adjustmentArea);
    adjustmentLayout->addWidget(formatOption);

    QLineEdit *downloadLocation = new QLineEdit(adjustmentArea);
    adjustmentLayout->addWidget(downloadLocation);

    QPushButton *downloadButton =
        new QPushButton(tr("Download"), adjustmentArea);

    adjustmentLayout->addWidget(downloadButton);

    layout->addWidget(adjustmentArea, 0, 1);

    QProgressBar *progressBar = new QProgressBar(this);
    layout->addWidget(progressBar, 1, 0);

    QLabel *messageLabel = new QLabel(this);
    layout->addWidget(messageLabel, 1, 1);

    // Set the stretch factor for the rows and columns in the layout
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 0);
    layout->setColumnStretch(0, 2);
    layout->setColumnStretch(1, 1);

    connect(downloadButton, SIGNAL(clicked()), this, SLOT(download()));
}

App::~App() { delete ui; }

void App::download() {
    QString url = inputArea->toPlainText();
    qDebug() << url;
    YtDlp *dl = new YtDlp();
    dl->download(url);
}
