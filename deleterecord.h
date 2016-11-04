#ifndef DELETERECORD_H
#define DELETERECORD_H

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

private:
    Ui::DeleteRecord *ui;
};

#endif // DELETERECORD_H
