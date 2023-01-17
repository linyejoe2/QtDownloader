#ifndef DATAROW_H
#define DATAROW_H

#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "datapathlineedit.hpp"

//! 一個實例代表一行下載的資料
class DataRow : public QObject {
    Q_OBJECT
   public:
    DataRow(QTableWidget *table);

    //! 行號
    int id;

   private:
    //! 網址
    QTableWidgetItem *mDownloadUrl;
    //! 進度條
    QProgressBar *mProgressBar;
    //! 檔案大小
    QTableWidgetItem *mDataSize;
    //! 檔案類型
    QTableWidgetItem *mDataType;
    //! 位置
    DataPathLineEdit *mDataPath;
    //! 下載按鈕
    QPushButton *mDownloadButton;
};

#endif  // DATAROW_H
