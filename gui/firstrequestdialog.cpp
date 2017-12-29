#include "firstrequestdialog.h"
#include "ui_firstrequestdialog.h"

FirstRequestDialog::FirstRequestDialog(MainWindowController *_controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstRequestDialog),
    controller(_controller)
{
    ui->setupUi(this);
    fillFields();
}

FirstRequestDialog::~FirstRequestDialog()
{
    delete ui;
}

void FirstRequestDialog::on_buttonBox_accepted()
{
    QString minWeight = QString::number(ui->minWeightLineEdit->text().toDouble());
    QString maxWeight = QString::number(ui->maxWeightLineEdit->text().toDouble());

    QString breed = ui->breedsComboBox->currentText();

    QString minAge = QString::number(ui->minAgeLineEdit->text().toDouble());
    QString maxAge = QString::number(ui->maxAgeLineEdit->text().toDouble());

    QString condition = "weight >= " + minWeight + " AND weight <= " + maxWeight + " AND " + "breed = '" + breed + "' AND " + "age >= " + minAge + " AND age <= " + maxAge ;

    QString request = "SELECT code, perfomance FROM Hen WHERE " + condition + ";";

    QString response;

    QSqlQuery query = controller->getSqliteAdapter()->runSQL(request);
    while (query.next())
    {
        QString tmp = "От птицы с кодом #" + query.value("code").toString() + " получают " + query.value("perfomance").toString() + " яиц \n";
        response += tmp;
    }
    QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}

void FirstRequestDialog::fillFields()
{
    QStringList breeds = controller->getAllBreedsList();
    ui->breedsComboBox->addItems(breeds);
}
