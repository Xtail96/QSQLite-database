#ifndef FOURTHREQUESTDIALOG_H
#define FOURTHREQUESTDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class FourthRequestDialog;
}

class FourthRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FourthRequestDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~FourthRequestDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::FourthRequestDialog *ui;
    MainWindowController* controller;
};

#endif // FOURTHREQUESTDIALOG_H
