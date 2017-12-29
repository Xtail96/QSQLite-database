#include "thirdrequestdialog.h"
#include "ui_thirdrequestdialog.h"

ThirdRequestDialog::ThirdRequestDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdRequestDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

ThirdRequestDialog::~ThirdRequestDialog()
{
    delete ui;
}

void ThirdRequestDialog::on_buttonBox_accepted()
{
    QString minAge = QString::number(ui->minAgeLineEdit->text().toDouble());
    QString maxAge = QString::number(ui->maxAgeLineEdit->text().toDouble());
    QString dietNumber = QString::number(ui->dietNumberLineEdit->text().toUInt());

    QString request = "SELECT Hen.code, Hen.cage_manufactory, Hen.cage_row, Hen.cage_number, Hen.breed FROM Hen WHERE Hen.age >= " + minAge + " AND Hen.age <= " + maxAge + " GROUP BY Hen.code HAVING Hen.breed = (SELECT Breed.name FROM Breed WHERE Breed.diet_number = " + dietNumber + ");";
    QString response;
    QSqlQuery query = controller->getSqliteAdapter()->runSQL(request);
    while (query.next())
    {
        QString cageTmp = query.value("cage_manufactory").toString() + ":" + query.value("cage_row").toString() + ":" + query.value("cage_number").toString();
        QString tmp = "Птица с кодом #" + query.value("code").toString() + " находится в клетке #" + cageTmp +"\n";
        response += tmp;
    }
    controller->setBuffer(response);
    //QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}
