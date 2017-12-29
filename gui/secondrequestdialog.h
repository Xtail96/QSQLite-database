#ifndef SECONDREQUESTDIALOG_H
#define SECONDREQUESTDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class SecondRequestDialog;
}

class SecondRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondRequestDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~SecondRequestDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SecondRequestDialog *ui;
    MainWindowController* controller;
    void fillFields();
};

#endif // SECONDREQUESTDIALOG_H
