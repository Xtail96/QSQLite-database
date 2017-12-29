#include "deleteworkerdialog.h"
#include "ui_deleteworkerdialog.h"

DeleteWorkerDialog::DeleteWorkerDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWorkerDialog),
    controller(_controller)
{
    ui->setupUi(this);
    fillFields();
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
    QString workerTo = ui->workerComboBox->currentText();

    //QString request = "SELECT * FROM Cage WHERE worker = " + workerTo + ";";

    controller->getSqliteAdapter()->updateData("Cage", "worker", workerTo, "worker", value);

    controller->getSqliteAdapter()->deleteData(tableName, key, value);
}

void DeleteWorkerDialog::fillFields()
{
    QStringList workers = controller->getAllWorkersList();
    ui->workerComboBox->addItems(workers);
}
