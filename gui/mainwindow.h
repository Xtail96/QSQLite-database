#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "./controllers/mainwindowcontroller.h"
#include "./gui/addworkerdialog.h"
#include "./gui/deleteworkerdialog.h"
#include "./gui/addbreeddialog.h"
#include "./gui/deletebreeddialog.h"

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
    void showWorkers();

private slots:
    void showDatabaseDisconnected();
    void showDatabaseConnected();
    void showDatabaseTitle();

    void setupDatabaseWidgets();
    void on_tablesListWidget_itemClicked(QListWidgetItem *item);
    void on_exitAction_triggered();
    void on_addWorkerAction_triggered();
    void on_deleteWorkerAction_triggered();
    void on_addCageAction_triggered();
    void on_addBreedAction_triggered();
    void on_deleteBreedAction_triggered();
};

#endif // MAINWINDOW_H
