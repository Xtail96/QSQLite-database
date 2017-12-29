#ifndef FIRSTREQUESTDIALOG_H
#define FIRSTREQUESTDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class FirstRequestDialog;
}

class FirstRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstRequestDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~FirstRequestDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::FirstRequestDialog *ui;
    MainWindowController* controller;
    void fillFields();
};

#endif // FIRSTREQUESTDIALOG_H
