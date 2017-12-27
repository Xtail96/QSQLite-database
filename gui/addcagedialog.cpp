#include "addcagedialog.h"
#include "ui_addcagedialog.h"

AddCageDialog::AddCageDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCageDialog),
    controller(_controller)
{
    ui->setupUi(this);
    fillFields();
}

AddCageDialog::~AddCageDialog()
{
    delete ui;
}

void AddCageDialog::on_buttonBox_accepted()
{
    QString tableName = "Cage";
    QString manufactory_number = QString::number(ui->manufactoryLineEdit->text().toUInt());
    QString row_number = QString::number(ui->rowLineEdit->text().toUInt());
    QString cage_number = QString::number(ui->numberLineEdit->text().toUInt());
    QString worker = ui->workersComboBox->currentText();

    QStringList arguments = {
        "manufactory_number",
        "row_number",
        "cage_number",
        "worker"
    };

    QStringList data = {
        manufactory_number,
        row_number,
        cage_number,
        worker
    };
    controller->getSqliteAdapter()->insertData(tableName, arguments, data);
}

void AddCageDialog::fillFields()
{
    QStringList workers = controller->getAllWorkersList();
    ui->workersComboBox->addItems(workers);
}
