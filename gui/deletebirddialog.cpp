#include "deletebirddialog.h"
#include "ui_deletebirddialog.h"

DeleteBirdDialog::DeleteBirdDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBirdDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

DeleteBirdDialog::~DeleteBirdDialog()
{
    delete ui;
}

void DeleteBirdDialog::on_buttonBox_accepted()
{
    QString code = QString::number(ui->codeLineEdit->text().toUInt());
    QString condition = "code = " + code;
    controller->getSqliteAdapter()->deleteData("Hen", condition);
}
