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

void MainWindow::showWorkers()
{
    QList< QList<QTableWidgetItem*> > workers = mainWindowController->getAllWorkers();
    ui->dataTableWidget->clear();
    QStringList labels = {
        "Паспортные данные",
        "Заработная плата"
    };
    ui->dataTableWidget->setColumnCount(labels.size());
    ui->dataTableWidget->setHorizontalHeaderLabels(labels);
    ui->dataTableWidget->setRowCount(workers.size());
    for(int i = 0; i < ui->dataTableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->dataTableWidget->columnCount(); j++)
        {
            ui->dataTableWidget->setItem(i, j, workers[i][j]);
        }
    }

    ui->dataTableWidget->resizeColumnsToContents();
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

void MainWindow::on_tablesListWidget_itemClicked(QListWidgetItem *item)
{
    QString table = item->text();
    if(table == "Worker")
    {
        showWorkers();
    }
    else
    {
        ui->dataTableWidget->clear();
        ui->dataTableWidget->setColumnCount(0);
        ui->dataTableWidget->setRowCount(0);
    }
}
