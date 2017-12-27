#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include "./models/sqliteadapter.h"

class MainWindowController : public QObject
{
    Q_OBJECT
public:
    MainWindowController();
    ~MainWindowController();

    SQLiteAdapter *getSqliteAdapter() const;
    void setSqliteAdapter(SQLiteAdapter *value);

    void openDatabase();

    QString getDatabaseName();
    QStringList getTablesNames();
    QStringList readFromTable(QString data, QString tableName);

signals:

private:
    SQLiteAdapter* sqliteAdapter;
    QString path = "./PoultryFarm.db";

    void setupSQLiteAdapter();
};

#endif // MAINWINDOWCONTROLLER_H