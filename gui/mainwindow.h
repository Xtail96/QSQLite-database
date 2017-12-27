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
    void on_addWorkerPushButton_clicked();
    void on_deleteWorkerPushButton_clicked();
    void on_updateWorkerPushButton_clicked();
    void on_addBreedPushButton_clicked();
    void on_deleteBreedPushButton_clicked();
    void on_tablesListWidget_itemClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H
