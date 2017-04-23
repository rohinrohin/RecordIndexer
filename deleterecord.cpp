#include "deleterecord.h"
#include "ui_deleterecord.h"
#include "bplus.h"
#include "qmessagebox.h"
#include "QPushButton"

DeleteRecord::DeleteRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteRecord)
{
    ui->setupUi(this);
    QPushButton *qp = ui->pushButton_2;
    qp->setEnabled(false);
    qp = ui->pushButton_3;
    qp->setEnabled(false);
}

void DeleteRecord::hideit() {

}

DeleteRecord::~DeleteRecord()
{
    delete ui;
}

void DeleteRecord::on_pushButton_clicked()
{

    record *rc = find_record(root, ui->lineEdit->text().toInt(), false);
    if (rc != NULL) {
        QPushButton *qbutton = new QPushButton(ui->pushButton_2);
        qbutton->setEnabled(true);
        ui->lineEdit_2->setText(QString::number(rc->usn));
        ui->lineEdit_3->setText(rc->name);
        ui->lineEdit_4->setText(QString::number(rc->cgpa));
        QPushButton *qp = ui->pushButton_2;
        qp->setEnabled(true);
        qp = ui->pushButton_3;
        qp->setEnabled(true);

    }
    else {
        QMessageBox::information(
            this,
            tr("Failed."),
            tr("Record not found in database.") );
    }

}

void DeleteRecord::on_pushButton_2_clicked()
{
    root = delete_node(root, ui->lineEdit->text().toInt());
    QMessageBox::information(
        this,
        tr("Success."),
        tr("Record deleted.") );
    this->close();

}

void DeleteRecord::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit_3->text();
    QByteArray array = name.toLocal8Bit();
    char* buffer = array.data();

    update_record(root, ui->lineEdit->text().toInt(), buffer, ui->lineEdit_4->text().toFloat());
    QMessageBox::information(
        this,
        tr("Success."),
        tr("Record updated succesfully.") );
    this->close();
}
