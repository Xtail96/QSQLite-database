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
    QStringList quantity = controller->getSqliteAdapter()->readFromTable("perfomance", "Hen", condition);
    QStringList codes = controller->getSqliteAdapter()->readFromTable("code", "Hen", condition);

    QString response;

    size_t count = std::min(quantity.size(), codes.size());
    for(size_t i = 0; i < count; i++)
    {
        QString tmp = "От птицы с кодом №" + codes[i] + " получают " + quantity[i] + " яиц \n";
        response += tmp;
    }

    QMessageBox(QMessageBox::Information, "Ответ", response).exec();
}

void FirstRequestDialog::fillFields()
{
    QStringList breeds = controller->getAllBreedsList();
    ui->breedsComboBox->addItems(breeds);
}
