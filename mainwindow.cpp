#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <iostream>
#include "bplus.h"
#include "addrecord.h"
#include "deleterecord.h"
#include "QFileDialog"
#include "listpage.h"
#include "querybrowser.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{



}

void MainWindow::on_pushButton_3_clicked()
{
    AddRecord addrecord;
    addrecord.setModal(true);
    addrecord.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    DeleteRecord drec;
    drec.hideit();
    drec.setModal(true);
    drec.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString filename = QFileDialog::getSaveFileName();
    QByteArray array = filename.toLocal8Bit();
    char* buffer = array.data();
    save_leaves(root, buffer);
    QMessageBox::information(
        this,
        tr("Save success!"),
        tr("Succesfully saved the database.") );

}

void MainWindow::on_pushButton_7_clicked()
{
    QString filename = QFileDialog::getOpenFileName();
    QByteArray array = filename.toLocal8Bit();
    char* buffer = array.data();
    root = load_leaves(root, buffer);

    QMessageBox::information(
        this,
        tr("Load success!"),
        tr("Succesfully loaded the database.") );

}

void MainWindow::on_pushButton_4_clicked()
{
    listpage lp;
    lp.setModal(true);
    lp.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    QueryBrowser qb;
    qb.setModal(true);
    qb.exec();
}
