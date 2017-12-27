#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "./controllers/mainwindowcontroller.h"
#include "./gui/addworkerdialog.h"
#include "./gui/deleteworkerdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    MainWindowController *mainWindowController;

    void setupWidgets();
    void setupStatusBar();
    void setupTablesList();
    void setupMainWindowController();

private slots:
    void showDatabaseDisconnected();
    void showDatabaseConnected();
    void showDatabaseTitle();

    void setupDatabaseWidgets();
    void on_addWorkerPushButton_clicked();
    void on_deleteWorkerPushButton_clicked();
    void on_updateWorkerPushButton_clicked();
};

#endif // MAINWINDOW_H
