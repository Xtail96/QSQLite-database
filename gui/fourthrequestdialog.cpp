#include "fourthrequestdialog.h"
#include "ui_fourthrequestdialog.h"

FourthRequestDialog::FourthRequestDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FourthRequestDialog),
    controller(_controller)
{
    ui->setupUi(this);
}

FourthRequestDialog::~FourthRequestDialog()
{
    delete ui;
}

void FourthRequestDialog::on_buttonBox_accepted()
{
    QString passport = QString::number(ui->passportLineEdit->text().toULongLong());

    //QString request = "SELECT Hen.code, Hen.cage_manufactory, Hen.cage_row, Hen.cage_number, Hen.breed FROM Hen WHERE Hen.age = " + age + " GROUP BY Hen.code HAVING Hen.breed = (SELECT Breed.name FROM Breed WHERE Breed.diet_number = " + dietNumber + ");";

    //QString request = "SELECT * FROM Hen INNER JOIN Cage WHERE worker = " + passport + ";";

    QString response;
    //QSqlQuery query = controller->getSqliteAdapter()->runSQL(request);
    //while (query.next())
    //{
        //qDebug() << query.value(0).toString() << ":" << query.value(1).toString() << ":" << query.value(2).toString();
        //QString cageTmp = query.value("cage_manufactory").toString() + ":" + query.value("cage_row").toString() + ":" + query.value("cage_number").toString();
        //QString tmp = "Птица с кодом #" + query.value("code").toString() + " находится в клетке #" + cageTmp +"\n";
        //response += tmp;
    //}
    //QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}
