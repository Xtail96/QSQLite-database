#ifndef ADDBREEDDIALOG_H
#define ADDBREEDDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class AddBreedDialog;
}

class AddBreedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBreedDialog(MainWindowController* _controller, QWidget *parent = 0, bool _isUpdate = false);
    ~AddBreedDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddBreedDialog *ui;
    MainWindowController* controller;
    bool isUpdate;
    void fillFields();
};

#endif // ADDBREEDDIALOG_H
