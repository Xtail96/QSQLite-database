#include "addbreeddialog.h"
#include "ui_addbreeddialog.h"

AddBreedDialog::AddBreedDialog(MainWindowController *_controller, QWidget *parent, bool _isUpdate) :
    QDialog(parent),
    ui(new Ui::AddBreedDialog),
    controller(_controller),
    isUpdate(_isUpdate)
{
    ui->setupUi(this);

    if(isUpdate)
    {
        fillFields();
    }
}

AddBreedDialog::~AddBreedDialog()
{
    delete ui;
}

void AddBreedDialog::on_buttonBox_accepted()
{
    QString tableName = "Breed";
    QString breedName = ui->nameLineEdit->text();
    QString averagePerfomance = QString::number(ui->averagePerfomanceLineEdit->text().toDouble());
    QString averageWeight = QString::number(ui->averageWeightLineEdit->text().toDouble());
    QString dietNumber = QString::number(ui->dietNumberLineEdit->text().toInt());

    QStringList arguments = {
        "name",
        "average_perfomance",
        "average_weight",
        "diet_number"
    };

    QStringList data = {
        "'" + breedName + "'",
        averagePerfomance,
        averageWeight,
        dietNumber
    };

    if(!isUpdate)
    {
        controller->getSqliteAdapter()->insertData(tableName, arguments, data);
    }
    else
    {
        //controller->getSqliteAdapter()->updateData(tableName, arguments[1], wage, arguments[0], passport);
    }
}

void AddBreedDialog::fillFields()
{

}
