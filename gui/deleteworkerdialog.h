#ifndef DELETEWORKERDIALOG_H
#define DELETEWORKERDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class DeleteWorkerDialog;
}

class DeleteWorkerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWorkerDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~DeleteWorkerDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteWorkerDialog *ui;

    MainWindowController* controller;
    void fillFields();
};

#endif // DELETEWORKERDIALOG_H
