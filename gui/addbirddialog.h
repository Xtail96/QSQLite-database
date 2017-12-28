#ifndef ADDBIRDDIALOG_H
#define ADDBIRDDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class AddBirdDialog;
}

class AddBirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBirdDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~AddBirdDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddBirdDialog *ui;
    MainWindowController* controller;
    void fillFields();
};

#endif // ADDBIRDDIALOG_H
