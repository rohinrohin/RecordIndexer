#include "addrecord.h"
#include "ui_addrecord.h"

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
