#include "deleterecord.h"
#include "ui_deleterecord.h"

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
