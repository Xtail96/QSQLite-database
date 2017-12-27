#ifndef DELETECAGEDIALOG_H
#define DELETECAGEDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class DeleteCageDialog;
}

class DeleteCageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteCageDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~DeleteCageDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteCageDialog *ui;
    MainWindowController* controller;
};

#endif // DELETECAGEDIALOG_H
