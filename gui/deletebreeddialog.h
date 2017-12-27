#ifndef DELETEBREEDDIALOG_H
#define DELETEBREEDDIALOG_H

#include <QDialog>

#include "./controllers/mainwindowcontroller.h"

namespace Ui {
class DeleteBreedDialog;
}

class DeleteBreedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBreedDialog(MainWindowController* _controller, QWidget *parent = 0);
    ~DeleteBreedDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteBreedDialog *ui;
    MainWindowController* controller;
};

#endif // DELETEBREEDDIALOG_H
