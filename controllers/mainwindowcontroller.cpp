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

    QString request = "SELECT manufactory_number, row_number, cage_number FROM Cage"
            " EXCEPT SELECT cage_manufactory, cage_row, cage_number FROM Hen";
    QSqlQuery query = sqliteAdapter->runSQL(request);
    while (query.next())
    {
        QString freeCage;
        freeCage += query.value("manufactory_number").toString() + ":" + query.value("row_number").toString() + ":" + query.value("cage_number").toString();
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

QList<QList<QTableWidgetItem *> > MainWindowController::getAllBreeds()
{
    QList< QList<QTableWidgetItem*> > breeds;
    QStringList names = sqliteAdapter->readFromTable("name", "Breed");

    for(auto name : names)
    {
        QList<QTableWidgetItem*> breed;
        QTableWidgetItem* item = new QTableWidgetItem(name);
        breed.push_back(item);
        breeds.push_back(breed);
    }

    for(int i = 0; i < names.size(); i++)
    {
        QString condition = "name = '" + names[i] + "'";
        QStringList averagePerfomance = sqliteAdapter->readFromTable("average_perfomance", "Breed", condition);
        QStringList averageWeight = sqliteAdapter->readFromTable("average_weight", "Breed", condition);
        QStringList dietNumber = sqliteAdapter->readFromTable("diet_number", "Breed", condition);

        breeds[i].push_back(new QTableWidgetItem(averagePerfomance[0]));
        breeds[i].push_back(new QTableWidgetItem(averageWeight[0]));
        breeds[i].push_back(new QTableWidgetItem(dietNumber[0]));
    }

    return breeds;
}

void MainWindowController::setBuffer(const QString &value)
{
    buffer = value;
}

QString MainWindowController::getBuffer() const
{
    return buffer;
}

void MainWindowController::setupSQLiteAdapter()
{
    sqliteAdapter = new SQLiteAdapter("/Users/Xtail/Projects/labs/db/course/databases/PoultryFarm.db");
}
