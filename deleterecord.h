#ifndef DELETERECORD_H
#define DELETERECORD_H
#include "bplus.h"

extern node* root;

#include <QDialog>

namespace Ui {
class DeleteRecord;
}

class DeleteRecord : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteRecord(QWidget *parent = 0);
    ~DeleteRecord();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteRecord *ui;
};

#endif // DELETERECORD_H
