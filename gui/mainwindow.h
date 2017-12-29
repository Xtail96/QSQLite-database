#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "./controllers/mainwindowcontroller.h"
#include "./gui/addworkerdialog.h"
#include "./gui/deleteworkerdialog.h"
#include "./gui/addbreeddialog.h"
#include "./gui/deletebreeddialog.h"
#include "./gui/addcagedialog.h"
#include "./gui/deletecagedialog.h"
#include "./gui/addbirddialog.h"
#include "./deletebirddialog.h"
#include "./firstrequestdialog.h"

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
    void setupMainWindowController();

private slots:
    void showDatabaseDisconnected();
    void showDatabaseConnected();
    void showDatabaseTitle();



    void update();
    void updateWorkers();
    void updateHens();
    void updateBreeds();

    void setupDatabaseWidgets();
    void on_exitAction_triggered();
    void on_addWorkerAction_triggered();
    void on_deleteWorkerAction_triggered();
    void on_addCageAction_triggered();
    void on_addBreedAction_triggered();
    void on_deleteBreedAction_triggered();
    void on_deleteCageAction_triggered();
    void on_addHenAction_triggered();
    void on_deleteHenAction_triggered();
    void on_firstRequestPushButton_clicked();
};

#endif // MAINWINDOW_H
