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

void MainWindowController::setupSQLiteAdapter()
{
    sqliteAdapter = new SQLiteAdapter("/Users/Xtail/Projects/labs/db/course/databases/PoultryFarm.db");
}
