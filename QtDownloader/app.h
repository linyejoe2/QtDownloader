#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QString>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class App;
}
QT_END_NAMESPACE

class App : public QMainWindow {
    Q_OBJECT

   public:
    App(QWidget *parent = nullptr);
    ~App();

   public slots:

    //! 下載影片
    void download();

   private:
    Ui::App *ui;

    QTextEdit *inputArea;
};
#endif  // APP_H
