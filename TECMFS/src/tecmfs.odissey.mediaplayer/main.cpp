/*
 * main.cpp
 *
 *  Created on: 7 nov. 2016
 *      Author: gustavo
 */

#include "mainwindow.h"
#include "converter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


}


