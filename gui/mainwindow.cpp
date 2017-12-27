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

void MainWindow::setupMainWindowController()
{
    mainWindowController = new MainWindowController();
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsOpen()), this, SLOT(showDatabaseConnected()));
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsNotOpen()), this, SLOT(showDatabaseDisconnected()));
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseIsOpen()), this, SLOT(setupDatabaseWidgets()));
    mainWindowController->openDatabase();
}

void MainWindow::updateWorkers()
{
    QList< QList<QTableWidgetItem*> > workers = mainWindowController->getAllWorkers();
    ui->workersTableWidget->clear();
    QStringList labels = {
        "Паспортные данные",
        "Заработная плата"
    };
    ui->workersTableWidget->setColumnCount(labels.size());
    ui->workersTableWidget->setHorizontalHeaderLabels(labels);
    ui->workersTableWidget->setRowCount(workers.size());
    for(int i = 0; i < ui->workersTableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->workersTableWidget->columnCount(); j++)
        {
            ui->workersTableWidget->setItem(i, j, workers[i][j]);
        }
    }

    ui->workersTableWidget->resizeColumnsToContents();
    ui->workersTableWidget->verticalHeader()->hide();
}

void MainWindow::updateHens()
{

}

void MainWindow::setupDatabaseWidgets()
{
    update();
    connect(mainWindowController->getSqliteAdapter(), SIGNAL(databaseStateIsChanged()), this, SLOT(update()));
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

void MainWindow::update()
{
    updateHens();
    updateWorkers();
}

void MainWindow::on_exitAction_triggered()
{
    this->close();
}

void MainWindow::on_addWorkerAction_triggered()
{
    AddWorkerDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteWorkerAction_triggered()
{
    DeleteWorkerDialog(mainWindowController, this).exec();
}

void MainWindow::on_addCageAction_triggered()
{

}

void MainWindow::on_addBreedAction_triggered()
{
    AddBreedDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteBreedAction_triggered()
{
    DeleteBreedDialog(mainWindowController, this).exec();
}
