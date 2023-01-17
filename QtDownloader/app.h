#ifndef APP_H
#define APP_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class App;
class DataRow;
}  // namespace Ui
QT_END_NAMESPACE

class App : public QMainWindow {
    Q_OBJECT

   public:
    App(QWidget *parent = nullptr);
    ~App();

   public slots:

    //! 下載影片
    void download();
    //! 選擇下載位置
    // void selectFileLocation();

   private:
    Ui::App *ui;

    QTableWidget *inputArea;

    QGridLayout *mainLayout;

    // QLineEdit *locationEdit;

    void initUi();
};

#endif  // APP_H
