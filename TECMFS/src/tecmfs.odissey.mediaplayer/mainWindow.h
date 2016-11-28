/*
 * mainWindow.h
 *
 *  Created on: 19 nov. 2016
 *      Author: gustavo
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <vector>


#include <QMainWindow>
#include <QProgressBar>
#include <QTextEdit>
#include <QLineEdit>
#include <QKeyEvent>


#include "player.h"

using namespace std;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString path;


private slots:
    //File
    void openFile();
    void updateProgress();
    void uploadFile();


    //Edit
    void editSearch();
    void getNameSearchEdit();

    //Streaming
    void streamingSearch();
    void getNameSearchStreaming();

    //Help
    void helpOdssMP();

    //About
    void aboutProject();
    void aboutOdssMP();

    //Control Panel(Buttons)
    void on_playButton_pressed();
    void on_stopButton_pressed();
    void on_advanceButton_pressed();
    void on_stopAllButton_pressed();
    void on_backButton_pressed();
    void updatePlayerUi(QImage img);


private:
    void invisibleAll();
private:
    Ui::MainWindow *ui;
    Player *player;
    QLineEdit *search;

};

#endif /* MAINWINDOW_H_ */
