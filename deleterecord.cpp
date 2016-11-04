#include "deleterecord.h"
#include "ui_deleterecord.h"
#include "bplus.h"
#include "qmessagebox.h"

DeleteRecord::DeleteRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteRecord)
{
    ui->setupUi(this);
}

DeleteRecord::~DeleteRecord()
{
    delete ui;
}

void DeleteRecord::on_pushButton_clicked()
{
    record *rc = find_record(root, ui->lineEdit->text().toInt(), false);
    if (rc != NULL) {
        ui->lineEdit_2->setText(QString::number(rc->value));
    }
    else {
        QMessageBox::information(
            this,
            tr("Failed."),
            tr("Record not found in database.") );

    }

}
