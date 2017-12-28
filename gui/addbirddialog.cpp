#include "addbirddialog.h"
#include "ui_addbirddialog.h"

AddBirdDialog::AddBirdDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBirdDialog),
    controller(_controller)
{
    ui->setupUi(this);
    fillFields();
}

AddBirdDialog::~AddBirdDialog()
{
    delete ui;
}

void AddBirdDialog::fillFields()
{
    QStringList avaliableBreeds = controller->getAllBreedsList();
    ui->breedComboBox->addItems(avaliableBreeds);

    QStringList avaliableCages = controller->getAllFreeCagesList();
    ui->cageComboBox->addItems(avaliableCages);
}

void AddBirdDialog::on_buttonBox_accepted()
{
    QString tableName = "Hen";
    QString code = QString::number(ui->codeLineEdit->text().toUInt());
    QString weight = QString::number(ui->weightLineEdit->text().toDouble());
    QString age = QString::number(ui->ageLineEdit->text().toDouble());
    QString perfomance = QString::number(ui->perfomanceLineEdit->text().toDouble());
    QString breed = ui->breedComboBox->currentText();

    QString cage = ui->cageComboBox->currentText();
    QStringList cageLocation = cage.split(":");
    QString cageManufactory = QString::number(cageLocation[0].toUInt());
    QString cageRow = QString::number(cageLocation[1].toUInt());
    QString cageNumber = QString::number(cageLocation[2].toUInt());

    QStringList arguments = {
        //"code",
        "weight",
        "age",
        "perfomance",
        "breed",
        "cage_manufactory",
        "cage_row",
        "cage_number"
    };

    QStringList data = {
        //code,
        weight,
        age,
        perfomance,
        "'" + breed + "'",
        cageManufactory,
        cageRow,
        cageNumber
    };

   controller->getSqliteAdapter()->insertData(tableName, arguments, data);

}
