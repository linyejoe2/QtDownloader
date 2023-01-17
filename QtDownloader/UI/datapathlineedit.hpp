#ifndef DATAPATHLINEEDIT_H
#define DATAPATHLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>

class DataPathLineEdit : public QLineEdit {
    Q_OBJECT
   public:
    explicit DataPathLineEdit(QWidget *parent = nullptr) : QLineEdit(parent){};

    void mouseDoubleClickEvent(QMouseEvent *event) override {
        QLineEdit::mouseDoubleClickEvent(event);
        emit clicked();
    };
   signals:
    void clicked();
};

#endif  // DATAPATHLINEEDIT_H