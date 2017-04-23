#include "listpage.h"
#include "ui_listpage.h"
#include "bplus.h"

listpage::listpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listpage)
{
    ui->setupUi(this);
    QTableWidget *tbl = ui->tableWidget;
    tbl->setRowCount(20);
    tbl->setColumnCount(3);
    tbl->setHorizontalHeaderLabels(QStringList() << "USN" << "NAME" << "CGPA");
    tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
    tbl->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl->setStyleSheet("QTableView {selection-background-color: blue;}");
    tbl->setItem(0, 0, new QTableWidgetItem("Empty"));
    tbl->setItem(0, 1, new QTableWidgetItem("Empty"));
    tbl->setItem(0, 2, new QTableWidgetItem("Empty"));

    record ** rec = array_record(root);

         for(int j=0;j<nodecount;j++){
             tbl->setItem(j, 0, new QTableWidgetItem(QString::number(rec[j]->usn)));
             tbl->setItem(j, 1, new QTableWidgetItem(rec[j]->name));
             tbl->setItem(j, 2, new QTableWidgetItem(QString::number(rec[j]->cgpa)));
        }
}

listpage::~listpage()
{
    delete ui;
}

void listpage::on_pushButton_clicked()
{
    this->close();
}
