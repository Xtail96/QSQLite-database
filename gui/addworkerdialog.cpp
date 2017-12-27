#include "addworkerdialog.h"
#include "ui_addworkerdialog.h"

AddWorkerDialog::AddWorkerDialog(MainWindowController *_controler, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWorkerDialog),
    controller(_controler)
{
    ui->setupUi(this);
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
    controller->getSqliteAdapter()->insertData(tableName, arguments, data);
}
