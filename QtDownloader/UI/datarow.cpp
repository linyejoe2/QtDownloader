#include "datarow.h"

#include <QDir>
#include <QFileDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

DataRow::DataRow(QTableWidget *table) {
    // 定義編號，即行號。
    id = table->rowCount();
    table->insertRow(id);

    // 定義行內資料。
    mDownloadUrl = new QTableWidgetItem();
    table->setItem(id, 0, mDownloadUrl);
    mProgressBar = new QProgressBar();
    table->setCellWidget(id, 1, mProgressBar);
    mDataSize = new QTableWidgetItem();
    table->setItem(id, 2, mDataSize);
    mDataType = new QTableWidgetItem();
    table->setItem(id, 3, mDataType);
    mDataPath = new DataPathLineEdit();
    mDataPath->setReadOnly(true);
    table->setCellWidget(id, 4, mDataPath);
    mDownloadButton = new QPushButton();
    table->setCellWidget(id, 5, mDownloadButton);

    // 在 mDataPath 上設定 mouseDoubleClickEvent 事件
    connect(mDataPath, &DataPathLineEdit::clicked, this, [this]() {
        // 使用 QFileDialog::getExistingDirectory() 來選擇檔案路徑
        QString directory = QFileDialog::getExistingDirectory(
            mDataPath, tr("Select download location"), QDir::homePath());
        // 如果有選擇檔案路徑，則將路徑顯示在 mDataPath 中
        if (!directory.isEmpty()) {
            mDataPath->setText(directory);
            mDataPath->setReadOnly(false);
        } else
            mDataPath->setReadOnly(true);
    });
}
