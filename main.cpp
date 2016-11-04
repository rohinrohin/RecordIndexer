#include "mainwindow.h"
#include <QApplication>
#include "bplus.h"

node* root = NULL;

int main(int argc, char *argv[])
{
    QApplication b(argc, argv);
    MainWindow w;
    w.show();

    return b.exec();
}
