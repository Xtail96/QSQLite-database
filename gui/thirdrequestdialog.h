#ifndef THIRDREQUESTDIALOG_H
#define THIRDREQUESTDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class ThirdRequestDialog;
}

class ThirdRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdRequestDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~ThirdRequestDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ThirdRequestDialog *ui;
    MainWindowController* controller;
};

#endif // THIRDREQUESTDIALOG_H
