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
    QString requestAdditional = "SELECT COUNT(cage_manufactory) FROM Hen WHERE breed = '" + breed + "'";
    QString requestGeneral = "SELECT cage_manufactory FROM Hen WHERE breed = '" + breed + "' "
            "GROUP BY cage_manufactory HAVING COUNT(cage_manufactory) = MAX("+ requestAdditional +");";

    QString response;

    QSqlQuery query = controller->getSqliteAdapter()->runSQL(requestGeneral);
    while (query.next())
    {
        qDebug() << query.value(0).toString() << ":" << query.value("manufactory_max").toString();
    }

    /*size_t count = std::min(quantity.size(), codes.size());
    for(size_t i = 0; i < count; i++)
    {
        QString tmp = "От птицы с кодом №" + codes[i] + " получают " + quantity[i] + " яиц \n";
        response += tmp;
    }*/

    QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}

void SecondRequestDialog::fillFields()
{
    QStringList breeds = controller->getAllBreedsList();
    ui->breedsComboBox->addItems(breeds);
}
