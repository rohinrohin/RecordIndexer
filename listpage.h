#ifndef LISTPAGE_H
#define LISTPAGE_H
#include "bplus.h"

#include <QDialog>

extern node*root;
extern int nodecount;

namespace Ui {
class listpage;
}

class listpage : public QDialog
{
    Q_OBJECT

public:
    explicit listpage(QWidget *parent = 0);
    ~listpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listpage *ui;
};

#endif // LISTPAGE_H
