#ifndef SQLITEADAPTER_H
#define SQLITEADAPTER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>

class SQLiteAdapter : public QObject
{
    Q_OBJECT
public:
    SQLiteAdapter(QString path);
    ~SQLiteAdapter();

    void open();

    QStringList readFromTable(QString data, QString tableName);

    QString getDatabaseName();
    QStringList getTablesNames();

    void insertData(QString tableName, QStringList arguments, QStringList data);

signals:
    void databaseIsOpen();
    void databaseIsNotOpen();
private:
    QSqlDatabase db;
};

#endif // SQLITEADAPTER_H
