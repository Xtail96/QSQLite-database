#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QTableWidgetItem>

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
    QList<QList<QTableWidgetItem *> > getAllWorkers();
    QStringList getAllWorkersList();
    QStringList getAllBreedsList();
    QStringList getAllFreeCagesList();
    QList<QList<QTableWidgetItem *> > getAllBirds();
    QList<QList<QTableWidgetItem *> > getAllBreeds();

signals:

private:
    SQLiteAdapter* sqliteAdapter;
    QString path = "./PoultryFarm.db";

    void setupSQLiteAdapter();
};

#endif // MAINWINDOWCONTROLLER_H
