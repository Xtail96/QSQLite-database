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
    QString weight = QString::number(ui->weightLineEdit->text().toUInt());
    QString breed = ui->breedsComboBox->currentText();
    QString age = QString::number(ui->ageLineEdit->text().toUInt());

    QString condition = "weight = " + weight + " AND " + "breed = '" + breed + "' AND " + "age = " + age;

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
