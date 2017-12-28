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
        "Заработная плата",
        "Обслуживаемые клетки"
    };
    ui->workersTableWidget->setColumnCount(labels.size());
    ui->workersTableWidget->setHorizontalHeaderLabels(labels);
    ui->workersTableWidget->setRowCount(workers.size());
    for(int i = 0; i < workers.size(); i++)
    {
        for(int j = 0; j < workers[i].size(); j++)
        {
            ui->workersTableWidget->setItem(i, j, workers[i][j]);
        }
    }


    QStringList workersCages;
    for(int i = 0; i < workers.size(); i++)
    {
        QString condition = "worker = " + workers[i][0]->text();
        QStringList cagesManufactoryNumbers = mainWindowController->getSqliteAdapter()->readFromTable("manufactory_number", "Cage", condition);
        QStringList cagesRowNumbers = mainWindowController->getSqliteAdapter()->readFromTable("row_number", "Cage", condition);
        QStringList cagesNumbers = mainWindowController->getSqliteAdapter()->readFromTable("cage_number", "Cage", condition);

        size_t length = std::min(cagesManufactoryNumbers.size(), std::min(cagesRowNumbers.size(), cagesNumbers.size()));
        QString cages;
        for(size_t j = 0; j < length; j++)
        {
            QString cage = cagesManufactoryNumbers[j] + ":" + cagesRowNumbers[j] + ":" + cagesNumbers[j];
            cages += cage + "; ";
        }
        workersCages.push_back(cages);
    }

    for(size_t i = 0; i < workers.size(); i++)
    {
        ui->workersTableWidget->setItem(i, workers[i].size(), new QTableWidgetItem(workersCages[i]));
    }

    ui->workersTableWidget->resizeColumnsToContents();
    ui->workersTableWidget->verticalHeader()->hide();
}

void MainWindow::updateHens()
{
    QList< QList<QTableWidgetItem*> > birds = mainWindowController->getAllBirds();
    ui->hensTableWidget->clear();
    QStringList labels = {
        "Код",
        "Вес",
        "Возраст",
        "Производительность",
        "Порода",
        "Номер цеха",
        "Номер ряда в цехе",
        "Номер клетки в ряду"
    };
    ui->hensTableWidget->setColumnCount(labels.size());
    ui->hensTableWidget->setHorizontalHeaderLabels(labels);
    ui->hensTableWidget->setRowCount(birds.size());
    for(int i = 0; i < ui->hensTableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->hensTableWidget->columnCount(); j++)
        {
            ui->hensTableWidget->setItem(i, j, birds[i][j]);
        }
    }

    ui->hensTableWidget->resizeColumnsToContents();
    ui->hensTableWidget->verticalHeader()->hide();
}

void MainWindow::updateBreeds()
{
    QList< QList<QTableWidgetItem*> > breeds = mainWindowController->getAllBreeds();
    ui->breedsTableWidget->clear();
    QStringList labels = {
        "Название",
        "Средняя производительность",
        "Средний вес",
        "Номер рекомендованной диеты",
    };
    ui->breedsTableWidget->setColumnCount(labels.size());
    ui->breedsTableWidget->setHorizontalHeaderLabels(labels);
    ui->breedsTableWidget->setRowCount(breeds.size());
    for(int i = 0; i < breeds.size(); i++)
    {
        for(int j = 0; j < breeds[i].size(); j++)
        {
            ui->breedsTableWidget->setItem(i, j, breeds[i][j]);
        }
    }

    ui->breedsTableWidget->resizeColumnsToContents();
    //ui->hensTableWidget->verticalHeader()->hide();
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
    updateBreeds();
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
    AddCageDialog(mainWindowController, this).exec();
}

void MainWindow::on_addBreedAction_triggered()
{
    AddBreedDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteBreedAction_triggered()
{
    DeleteBreedDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteCageAction_triggered()
{
    DeleteCageDialog(mainWindowController, this).exec();
}

void MainWindow::on_addHenAction_triggered()
{
    AddBirdDialog(mainWindowController, this).exec();
}

void MainWindow::on_deleteHenAction_triggered()
{
    DeleteBirdDialog(mainWindowController, this).exec();
}
