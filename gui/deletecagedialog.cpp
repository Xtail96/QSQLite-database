#include "deletecagedialog.h"
#include "ui_deletecagedialog.h"

DeleteCageDialog::DeleteCageDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteCageDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

DeleteCageDialog::~DeleteCageDialog()
{
    delete ui;
}

void DeleteCageDialog::on_buttonBox_accepted()
{
    QString tableName = "Cage";
    QString manufactoryKey = "manufactory_number";
    QString rowKey = "row_number";
    QString numberKey = "cage_number";
    QString manufactoryValue = QString::number(ui->manufactoryLineEdit->text().toUInt());
    QString rowValue = QString::number(ui->rowLineEdit->text().toUInt());
    QString numberValue = QString::number(ui->numberLineEdit->text().toUInt());

    QString condition = manufactoryKey + " = " + manufactoryValue; /* + " AND "
            + rowKey + " = " + rowValue + " AND "
            + numberKey + " = " + numberValue;*/
    controller->getSqliteAdapter()->deleteData(tableName, condition);
}
