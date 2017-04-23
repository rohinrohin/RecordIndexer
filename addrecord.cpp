#include "addrecord.h"
#include "ui_addrecord.h"
#include <iostream>
#include "bplus.h"
#include "addrecord.h"
#include "qmessagebox.h"


AddRecord::AddRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecord)
{
    ui->setupUi(this);
}

AddRecord::~AddRecord()
{
    delete ui;
}

void AddRecord::on_pushButton_clicked()
{
    QString name = ui->lineEdit_2->text();
    QByteArray array = name.toLocal8Bit();
    char* buffer = array.data();

    record *rc = find_record(root, ui->lineEdit->text().toInt(), false);
    if (rc != NULL) {
        QMessageBox::information(
            this,
            tr("Failed."),
            tr("Roll Number already exists. Delete the record before inserting another one. "));
    }
    else {
        root = insert(root, ui->lineEdit->text().toInt(), ui->lineEdit->text().toInt(), buffer, ui->lineEdit_3->text().toFloat());

        QMessageBox::information(
            this,
            tr("Success"),
            tr("Succesfully added to database.") );


        qDebug("Added element");
        print_tree(root);
        this->close();
    }



}

void AddRecord::on_pushButton_2_clicked()
{
//    if (delete_node(root, ui->lineEdit_2->text().toInt()) != NULL){
//        qDebug("Deleted");
//        print_tree(root);
//    } else {
//        qDebug("Did not delete");
//        print_tree(root);
//    }
}
