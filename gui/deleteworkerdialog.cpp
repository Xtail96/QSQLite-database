#include "deleteworkerdialog.h"
#include "ui_deleteworkerdialog.h"

DeleteWorkerDialog::DeleteWorkerDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWorkerDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

DeleteWorkerDialog::~DeleteWorkerDialog()
{
    delete ui;
}

void DeleteWorkerDialog::on_buttonBox_accepted()
{
    QString tableName = "Worker";
    QString key = "passport";
    QString value = ui->passportLineEdit->text();
    controller->getSqliteAdapter()->deleteData(tableName, key, value);
}
