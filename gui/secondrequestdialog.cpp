#include "secondrequestdialog.h"
#include "ui_secondrequestdialog.h"

SecondRequestDialog::SecondRequestDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondRequestDialog),
    controller(_controller)
{
    ui->setupUi(this);
    fillFields();
}

SecondRequestDialog::~SecondRequestDialog()
{
    delete ui;
}

void SecondRequestDialog::on_buttonBox_accepted()
{
    QString breed = ui->breedsComboBox->currentText();

    QString request = "SELECT cage_manufactory, COUNT(cage_manufactory) FROM Hen WHERE breed = '" + breed + "' GROUP BY cage_manufactory ORDER BY COUNT(cage_manufactory) DESC LIMIT 1;";

    QString response;

    QSqlQuery query = controller->getSqliteAdapter()->runSQL(request);
    while (query.next())
    {
        QString tmp = "Птиц породы " + breed + " больше всего в цехе #" + query.value(0).toString() + "("+ query.value(1).toString() +")";
        response = tmp;
        //break;
        /*qDebug() << "Hen";
        for(int i = 0; i < 3; i++)
        {
            qDebug() << query.value(i).toString();
        }
        qDebug() << "----";*/
    }

    QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}

void SecondRequestDialog::fillFields()
{
    QStringList breeds = controller->getAllBreedsList();
    ui->breedsComboBox->addItems(breeds);
}
