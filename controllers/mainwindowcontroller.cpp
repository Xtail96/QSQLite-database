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

void MainWindowController::setupSQLiteAdapter()
{
    sqliteAdapter = new SQLiteAdapter("/Users/Xtail/Projects/labs/db/course/databases/PoultryFarm.db");
}
