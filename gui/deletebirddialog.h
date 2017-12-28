#ifndef DELETEBIRDDIALOG_H
#define DELETEBIRDDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class DeleteBirdDialog;
}

class DeleteBirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBirdDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~DeleteBirdDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteBirdDialog *ui;
    MainWindowController* controller;
};

#endif // DELETEBIRDDIALOG_H
