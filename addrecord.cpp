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
    root = insert(root, ui->lineEdit->text().toInt(), ui->lineEdit->text().toInt());

    QMessageBox::information(
        this,
        tr("Success"),
        tr("Succesfully added to database.") );


    qDebug("Added element");
    print_tree(root);
    this->close();
}

void AddRecord::on_pushButton_2_clicked()
{
    if (delete_node(root, ui->lineEdit_2->text().toInt()) != NULL){
        qDebug("Deleted");
        print_tree(root);
    } else {
        qDebug("Did not delete");
        print_tree(root);
    }
}
