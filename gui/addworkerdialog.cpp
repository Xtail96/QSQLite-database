#include "addworkerdialog.h"
#include "ui_addworkerdialog.h"

AddWorkerDialog::AddWorkerDialog(MainWindowController *_controler, QWidget *parent, bool _isUpdate) :
    QDialog(parent),
    ui(new Ui::AddWorkerDialog),
    controller(_controler),
    isUpdate(_isUpdate)
{
    ui->setupUi(this);
    if(isUpdate)
    {
        fillFields();
    }
}

AddWorkerDialog::~AddWorkerDialog()
{
    delete ui;
}

void AddWorkerDialog::on_buttonBox_accepted()
{
    QString tableName = "Worker";
    QString passport = ui->passportLineEdit->text();
    QString wage = QString::number(ui->wageLineEdit->text().toInt());

    QStringList arguments = {
        "passport",
        "wage"
    };

    QStringList data = {
        passport,
        wage
    };

    if(!isUpdate)
    {
        controller->getSqliteAdapter()->insertData(tableName, arguments, data);
    }
    else
    {
        controller->getSqliteAdapter()->updateData(tableName, arguments[1], wage, arguments[0], passport);
    }
}

void AddWorkerDialog::fillFields()
{
}
