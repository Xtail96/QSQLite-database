#ifndef ADDWORKERDIALOG_H
#define ADDWORKERDIALOG_H

#include <QDialog>

#include "controllers/mainwindowcontroller.h"

namespace Ui {
class AddWorkerDialog;
}

class AddWorkerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddWorkerDialog(MainWindowController* _controler, QWidget *parent = 0, bool _isUpdate = false);
    ~AddWorkerDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddWorkerDialog *ui;

    MainWindowController* controller;
    bool isUpdate;

    void fillFields();
};

#endif // ADDWORKERDIALOG_H
