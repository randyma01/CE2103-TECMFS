/*
 * mainWindow.cpp
 *
 *  Created on: 19 nov. 2016
 *      Author: gustavo
 */

#include <QtGui>

#include "mainwindow.h"
#include "ui_odisseyMP.h"
#include "converter.h"



#include <MediaInfo/MediaInfo.h>
#include <MediaInfoDLL/MediaInfoDLL.h>



int counter;
QProgressBar *bar;
QTimer *timer;
QLabel *messageFull;
string pathV;
Converter convert;
QString name;


using namespace MediaInfoDLL;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){



    player = new Player(this);

    connect(player, SIGNAL(processedImage(QImage)),
            this, SLOT(updatePlayerUi(QImage)));


    ui->setupUi(this);
    ui->labelTextProject->setVisible(false);
    ui->labelTextOMP->setVisible(false);
    ui->labelTextHelp->setVisible(false);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->labelVideo->setStyleSheet("background-color:black;");
    ui->labelVideo->setPalette(Pal);


    //File
    connect(ui->action_UploadFile, SIGNAL(triggered(bool)),this, SLOT(uploadFile()));
    connect(ui->action_Open, SIGNAL(triggered(bool)), this, SLOT(openFile()));

    //Edit
    connect(ui->action_Search_E, SIGNAL(triggered(bool)), this, SLOT(editSearch()));

    //Streaming
    connect(ui->action_Search_S, SIGNAL(triggered(bool)), this, SLOT(streamingSearch()));


    connect(ui->action_How_to_use_OMP, SIGNAL(triggered(bool)), this, SLOT(helpOdssMP()));
    connect(ui->action_Project, SIGNAL(triggered(bool)), this, SLOT(aboutProject()));
    connect(ui->action_Odissey_Media_Player, SIGNAL(triggered(bool)), this, SLOT(aboutOdssMP()));


    /*
     * Control buttons
     */
    connect(ui->playButton, SIGNAL(pressed()), this, SLOT(on_playButton_pressed()));
    connect(ui->stopButton, SIGNAL(pressed()), this, SLOT(on_stopButton_pressed()));
    connect(ui->backButton, SIGNAL(pressed()), this, SLOT(on_backButton_pressed()));
    connect(ui->advanceButton, SIGNAL(pressed()), this, SLOT(on_advanceButton_pressed()));
    connect(ui->stopAllButton, SIGNAL(pressed()), this, SLOT(on_stopAllButton_pressed()));

}

MainWindow::~MainWindow()
{
    delete player;
    delete ui;
}

/*
 * Acciones para la opcion File
 */
//subir el video al RAID
void MainWindow::updateProgress(){
    if (counter <= 100){
        QString textV;
        textV = "Upload Video: ";
        textV.append(pathV.c_str());
        messageFull->setText(textV);
        messageFull->setGeometry(250, 177, 350, 20);
        messageFull->show();
        counter++;
        bar->setValue(counter);
        bar->show();
        if(counter == 50){
            string path1 = (path.toAscii()).data();
//            path1.erase(remove_if(path1.begin(), path1.end(), &IsParenthesesOrDash), path1.end());
//            QThread *thread = new QThread;
//            Worker *worker = new Worker();
//            worker->loadPath(path1.c_str());
//            worker->moveToThread(thread);
//            connect(thread, SIGNAL (started()), worker, SLOT (process()));
//            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//            thread->start();
            convert.loadVideo((path.toAscii()).data());
        }
        if(counter == 101){
            delete messageFull;
            messageFull = new QLabel(ui->centralwidget);
            messageFull->setText("Complete Upload!!!");
            messageFull->setGeometry(250, 223, 350, 20);
            messageFull->show();
        }
    }
    else{
        sleep(2);
        timer->stop();
        disconnect(timer);
        destroyed(messageFull);
        disconnect(messageFull);
        delete messageFull;
        delete timer;
        delete bar;
    }
}

void MainWindow::uploadFile(){
    invisibleAll();
    QFileDialog fileVideo(this);
    path = fileVideo.getOpenFileName(this,tr("Open Video"), "/home/gustavo/qt/OdisseyMediaPlayer/videos",tr("Video Files (*.mp4 *.vlc *.avi)"));
    const char *video = (path.toAscii().data());
    const string videoPath = (path.toAscii().data());


//   MediaInfo infoVideo;
//   size_t value = infoVideo.Open(video);
//   if (value < 0){
//       cout << "ERROR on Open()" << endl;
//   }
   //   cout << "Fecha: " << (infoVideo.Get(Stream_General, 0, 257)) << endl;
   //
   //	 cout << "Director: " << (infoVideo.Get(Stream_General, 0, "Author")) << endl;
   //
   //	 cout << "Descripcion: " << (infoVideo.Get(Stream_General, 0, "Comment")) << endl;
   //
   //	 cout << "Nombre: " << (infoVideo.Get(Stream_General, 0, "Title")) << endl;
   //
   //	 cout << "Duration: " << (infoVideo.Get(Stream_General, 0, "Duration")) << endl;


    if(!path.isEmpty()){
        QFileInfo pathVideo((path.toAscii()).data());

        pathV = (pathVideo.fileName().toAscii().data());
        cout << "File name Video: " << (pathVideo.fileName().toAscii().data()) << endl;


        bar = new QProgressBar(ui->centralwidget);
        bar->setRange(0, 100);
        bar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        bar->text();
        bar->setGeometry(250, 200, 350, 20);
        messageFull = new QLabel(ui->centralwidget);

        counter = 0;
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateProgress()));

        int time = convert.byteVideo(video);
        timer->start((time/800000));
    }

}

//open video
void MainWindow::openFile(){
    invisibleAll();
    QFileDialog fileVideo(this);
    QString pathVideo = fileVideo.getOpenFileName(this,tr("Open Video"), "/home/gustavo/qt/OdisseyMediaPlayer/videos",tr("Video Files (*.mp4 *.vlc *.avi)"));



    if (!pathVideo.isEmpty()){
        if(!player->loadVideo(pathVideo.toAscii().data())){
            QMessageBox msgBox;
            msgBox.setText("No se pudo abrir");
            msgBox.exec();
        }else{
            ui->progressVideo->setMaximum(player->getNumberOfFrames());
        }
    }

}

void MainWindow::on_playButton_pressed(){
   player->Play();

}

void MainWindow::on_stopButton_pressed(){
    player->Stop();
}


void MainWindow::on_advanceButton_pressed(){
    int frame = player->getCurrentFrame();
    player->Stop();
    frame += 15;
    player->setCurrentFrame(frame);
    player->Play();
}

void MainWindow::on_stopAllButton_pressed(){
    player->Stop();
    player->setCurrentFrame(0);
}


void MainWindow::on_backButton_pressed(){
    int frame = player->getCurrentFrame();
    player->Stop();
    frame -= 15;
    player->setCurrentFrame(frame);
    player->Play();
}

void MainWindow::updatePlayerUi(QImage img){
    if (!img.isNull()){
        ui->labelVideo->setAlignment(Qt::AlignCenter);
        ui->labelVideo->setPixmap(QPixmap::fromImage(img).scaled(ui->labelVideo->size(),
                                  Qt::KeepAspectRatio, Qt::FastTransformation));
        ui->progressVideo->setValue(player->getCurrentFrame());

    }
}

/*
 * Acciones para la opcion Edit
 */

void MainWindow::editSearch(){
    invisibleAll();
    search = new QLineEdit(ui->centralwidget);
    search->setGeometry(250, 100, 200, 80);
    search->setText("File Name: ");
    search->installEventFilter(this);
    search->show();
    connect(search, SIGNAL(returnPressed()), this, SLOT(getNameSearchEdit()));

}

void MainWindow::getNameSearchEdit(){
    name = search->text();
    string nameToServer = name.toAscii().data();
    cout << nameToServer.substr(11, nameToServer.length()-1) << endl;
    search->deleteLater();
}

/*
 * Acciones para la opcion Streaming
 */
void MainWindow::streamingSearch(){
    invisibleAll();
    search = new QLineEdit(ui->centralwidget);
    search->setGeometry(250, 100, 200, 80);
    search->setText("File Name: ");
    search->installEventFilter(this);
    search->show();
    connect(search, SIGNAL(returnPressed()), this, SLOT(getNameSearchStreaming()));

}

void MainWindow::getNameSearchStreaming(){
    name = search->text();
    string nameToServer = name.toAscii().data();
    cout << nameToServer.substr(11, nameToServer.length()-1) << endl;
    search->deleteLater();
}


/*
 * Acciones para la opcion Help
 */
void MainWindow::helpOdssMP(){
    invisibleAll();
    ui->labelTextHelp->setVisible(true);
}

/*
 * Acciones para la opcion About
 *
 */
void MainWindow::aboutProject(){
    invisibleAll();
    ui->labelTextProject->setVisible(true);
    ui->labelTextProject->setOpenExternalLinks(true);
}

void MainWindow::aboutOdssMP(){
    invisibleAll();
    ui->labelTextOMP->setVisible(true);
}


/*
 * Ocultar todos los cuadros de texto
 * */
void MainWindow::invisibleAll(){
    ui->labelTextProject->setVisible(false);
    ui->labelTextOMP->setVisible(false);
    ui->labelTextHelp->setVisible(false);
}
