#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QDialog>
#include "bplus.h"


extern node* root;


namespace Ui {
class AddRecord;
}

class AddRecord : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecord(QWidget *parent = 0);
    ~AddRecord();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddRecord *ui;
};

#endif // ADDRECORD_H
