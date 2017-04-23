#include "querybrowser.h"
#include "ui_querybrowser.h"
#include "bplus.h"
#include "qmessagebox.h"

QueryBrowser::QueryBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryBrowser)
{
    ui->setupUi(this);
}

QueryBrowser::~QueryBrowser()
{
    delete ui;
}

void QueryBrowser::on_pushButton_clicked()
{
    QString qstr = ui->textEdit->toPlainText();
    QByteArray array = qstr.toLocal8Bit();
    char* buffer = array.data();

    root = run_multiple_query(root, buffer);

    QMessageBox::information(
        this,
        tr("Success."),
        tr("Query has been executed succesfully.") );

    this->close();

}
