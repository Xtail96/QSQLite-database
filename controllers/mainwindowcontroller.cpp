#include "mainwindowcontroller.h"

MainWindowController::MainWindowController()
{
    setupSQLiteAdapter();
}

MainWindowController::~MainWindowController()
{
    delete sqliteAdapter;
}

SQLiteAdapter *MainWindowController::getSqliteAdapter() const
{
    return sqliteAdapter;
}

void MainWindowController::setSqliteAdapter(SQLiteAdapter *value)
{
    sqliteAdapter = value;
}

void MainWindowController::openDatabase()
{
    try
    {
        sqliteAdapter->open();
    }
    catch(std::runtime_error e)
    {
        QMessageBox(QMessageBox::Warning, "Error", e.what()).exec();
    }
}

QString MainWindowController::getDatabaseName()
{
    return sqliteAdapter->getDatabaseName();
}

QStringList MainWindowController::getTablesNames()
{
    return sqliteAdapter->getTablesNames();
}

QStringList MainWindowController::readFromTable(QString data, QString tableName)
{
    return sqliteAdapter->readFromTable(data, tableName);
}

QList< QList<QTableWidgetItem*> >MainWindowController::getAllWorkers()
{
    QList< QList<QTableWidgetItem*> > workers;
    QStringList workersPassports = sqliteAdapter->readFromTable("passport", "Worker");
    //QStringList workersWages = sqliteAdapter->readFromTable("wage", "Worker", "");

    for(auto workerPassport : workersPassports)
    {
        QList<QTableWidgetItem*> worker;
        QTableWidgetItem* passport = new QTableWidgetItem(workerPassport);
        worker.push_back(passport);
        workers.push_back(worker);
    }

    for(int i = 0; i < workers.size(); i++)
    {
        QString condition = "passport = " + workersPassports[i];
        QStringList arguments = sqliteAdapter->readFromTable("wage", "Worker", condition);
        workers[i].push_back(new QTableWidgetItem(arguments[0]));
    }

    return workers;
}

QStringList MainWindowController::getAllWorkersList()
{
    return sqliteAdapter->readFromTable("passport", "Worker");
}

QStringList MainWindowController::getAllBreedsList()
{
    return sqliteAdapter->readFromTable("name", "Breed");
}

QStringList MainWindowController::getAllFreeCagesList()
{
    QStringList freeCages;

    QStringList bookedManufactoryNumbers = sqliteAdapter->readFromTable("cage_manufactory", "Hen");
    QStringList bookedRowNumbers = sqliteAdapter->readFromTable("cage_row", "Hen");
    QStringList bookedCagesNumbersInRow = sqliteAdapter->readFromTable("cage_number", "Hen");

    /*QString condition = "manufactory_number != " + bookedManufactoryNumbers + "AND" +
            "row_number != " + bookedRowNumbers + "AND" +
            "cage_number != " + bookedCagesNumbersInRow;*/

    QStringList freeManufactoryNumbers = sqliteAdapter->readFromTable("manufactory_number", "Cage");
    QStringList freeRowNumbers = sqliteAdapter->readFromTable("row_number", "Cage");
    QStringList freeCageNumbers = sqliteAdapter->readFromTable("cage_number", "Cage");

    size_t length = std::min(freeManufactoryNumbers.size(), std::min(freeRowNumbers.size(), freeCageNumbers.size()));

    for(size_t i = 0; i < length; i++)
    {
        QString freeCage = freeManufactoryNumbers[i] + ":" + freeRowNumbers[i] + ":" + freeCageNumbers[i];
        freeCages.push_back(freeCage);
    }

    return freeCages;
}

QList<QList<QTableWidgetItem *> > MainWindowController::getAllBirds()
{
    QList< QList<QTableWidgetItem*> > birds;
    QStringList birdsCodes = sqliteAdapter->readFromTable("code", "Hen");

    for(auto birdCode : birdsCodes)
    {
        QList<QTableWidgetItem*> bird;
        QTableWidgetItem* code = new QTableWidgetItem(birdCode);
        bird.push_back(code);
        birds.push_back(bird);
    }

    for(int i = 0; i < birdsCodes.size(); i++)
    {
        QString condition = "code = " + birdsCodes[i];
        QStringList weight = sqliteAdapter->readFromTable("weight", "Hen", condition);
        QStringList age = sqliteAdapter->readFromTable("age", "Hen", condition);
        QStringList perfomance = sqliteAdapter->readFromTable("perfomance", "Hen", condition);
        QStringList breed = sqliteAdapter->readFromTable("breed", "Hen", condition);
        QStringList cageManufactory = sqliteAdapter->readFromTable("cage_manufactory", "Hen", condition);
        QStringList cageRow = sqliteAdapter->readFromTable("cage_row", "Hen", condition);
        QStringList cageNumber = sqliteAdapter->readFromTable("cage_number", "Hen", condition);

        birds[i].push_back(new QTableWidgetItem(weight[0]));
        birds[i].push_back(new QTableWidgetItem(age[0]));
        birds[i].push_back(new QTableWidgetItem(perfomance[0]));
        birds[i].push_back(new QTableWidgetItem(breed[0]));
        birds[i].push_back(new QTableWidgetItem(cageManufactory[0]));
        birds[i].push_back(new QTableWidgetItem(cageRow[0]));
        birds[i].push_back(new QTableWidgetItem(cageNumber[0]));
    }

    return birds;
}

void MainWindowController::setupSQLiteAdapter()
{
    sqliteAdapter = new SQLiteAdapter("/Users/Xtail/Projects/labs/db/course/databases/PoultryFarm.db");
}
