#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupWidgets();
    setupMainWindowController();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete mainWindowController;
}

void MainWindow::setupWidgets()
{
    this->showMaximized();
    ui->mainToolBar->hide();
    setupStatusBar();
}

void MainWindow::setupStatusBar()
{
    ui->statusBar->setStyleSheet("background-color: #333; color: #00bb00");
}

void MainWindow::setupTablesList()
{
    QStringList databaseTables = mainWindowController->getTablesNames();
    ui->tablesListWidget->addItems(databaseTables);
}

void MainWindow::setupMainWindowController()
{
    mainWindowController = new MainWindowController();
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsOpen()), this, SLOT(showDatabaseConnected()));
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsNotOpen()), this, SLOT(showDatabaseDisconnected()));
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsOpen()), this, SLOT(setupDatabaseWidgets()));
    mainWindowController->openDatabase();

}

void MainWindow::setupDatabaseWidgets()
{
    setupTablesList();
}

void MainWindow::showDatabaseDisconnected()
{
    ui->statusBar->setStyleSheet("background-color: #333; color: #b22222");
    ui->statusBar->showMessage("Database is disconnected");
    showDatabaseTitle();
}

void MainWindow::showDatabaseConnected()
{
    ui->statusBar->setStyleSheet("background-color: #333; color: #00bb00");
    ui->statusBar->showMessage("Database is connected");
    showDatabaseTitle();
}

void MainWindow::showDatabaseTitle()
{
    this->setWindowTitle(mainWindowController->getDatabaseName());
}

void MainWindow::on_addWorkerPushButton_clicked()
{
    AddWorkerDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteWorkerPushButton_clicked()
{
   DeleteWorkerDialog(mainWindowController, this).exec();
}

void MainWindow::on_updateWorkerPushButton_clicked()
{
    AddWorkerDialog(mainWindowController, this, true).exec();
}

void MainWindow::on_addBreedPushButton_clicked()
{
    AddBreedDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteBreedPushButton_clicked()
{
    DeleteBreedDialog(mainWindowController, this).exec();
}
