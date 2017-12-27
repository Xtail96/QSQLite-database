#include "deletebreeddialog.h"
#include "ui_deletebreeddialog.h"

DeleteBreedDialog::DeleteBreedDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBreedDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

DeleteBreedDialog::~DeleteBreedDialog()
{
    delete ui;
}

void DeleteBreedDialog::on_buttonBox_accepted()
{
    QString tableName = "Breed";
    QString key = "name";
    QString value = "'" + ui->deleteBreedLineEdit->text() + "'";
    controller->getSqliteAdapter()->deleteData(tableName, key, value);
}
