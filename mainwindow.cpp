#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <iostream>
#include "bplus.h"
#include "addrecord.h"
#include "deleterecord.h"




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
    drec.setModal(true);
    drec.exec();
}
