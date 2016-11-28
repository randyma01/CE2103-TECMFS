#ifndef PLAYER_H
#define PLAYER_H

#include <QThread>
#include <QMovie>
#include <QMutex>
#include <QImage>
#include <QWaitCondition>

#include <QAbstractButton>
#include <QAbstractAnimation>
#include <QTimer>

#include <Qt/qmovie.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/video.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * @brief The Player class
 * @author Nneji Stephen
 * @date May 27, 2013
 * @url: http://codingexodus.blogspot.com/2013/05/working-with-video-using-opencv-and-qt.html
 */

class Player : public QThread{
    Q_OBJECT

private:
   bool stop;
   QMutex mutex;
   QWaitCondition condition;
   Mat frame;
   int frameRate;
   VideoCapture *capture;
   Mat RGBframe;
   QImage img;
signals:
    //Signal to output frame to be displayed
     void processedImage(const QImage &image);
protected:
    void run();
    void msleep(int ms);
public:
   //Constructor
   Player(QObject *parent = 0);
   //Destructor
   ~Player();
   //Load a video from memory
   bool loadVideo(string filename);
   //Play the video
   void Play();
   //Stop the video
   void Stop();
   //check if the player has been stopped
   bool isStopped() const;
   void setCurrentFrame( int frameNumber);
   //
   int getFrameRate();
   int getCurrentFrame();
   int getNumberOfFrames();

};

#endif // PLAYER_H
