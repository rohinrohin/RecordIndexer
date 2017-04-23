#ifndef QUERYBROWSER_H
#define QUERYBROWSER_H

#include <QDialog>
#include "bplus.h"

extern node*root;

namespace Ui {
class QueryBrowser;
}

class QueryBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit QueryBrowser(QWidget *parent = 0);
    ~QueryBrowser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QueryBrowser *ui;
};

#endif // QUERYBROWSER_H
