#ifndef ADDCAGEDIALOG_H
#define ADDCAGEDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class AddCageDialog;
}

class AddCageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCageDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~AddCageDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddCageDialog *ui;
    MainWindowController* controller;

    void fillFields();
};

#endif // ADDCAGEDIALOG_H
