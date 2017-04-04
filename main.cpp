#include <QCoreApplication>
#include "global_objects.h"
#include <QtCore>
#include "worker.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"(GUI) main control thread: "<< QThread::currentThreadId();


//    Camera camera;
//    QThread cam_t;

//    Power power;
//    QThread pow_t;

    // declare worker objects and threads
    Worker camera, power;
    QThread cam_t, pow_t;

    // workerThread.start() will signal-> worker.onStarted()
    QObject::connect(&cam_t, SIGNAL(started()), &camera, SLOT(connectCamera()));
    QObject::connect(&pow_t, SIGNAL(started()), &power, SLOT(connectPower()));



    // links each worker with global timer
    QObject::connect(&timer, SIGNAL(timeout()), &camera, SLOT(cameraTimerEvent()));
    QObject::connect(&timer, SIGNAL(timeout()), &power, SLOT(powerTimerEvent()));

    // start timer
    timer.start(1000);

    // move worker objects to their own thread
    camera.moveToThread(&cam_t);
    power.moveToThread(&pow_t);

    // start the worker threads
    cam_t.start();
    pow_t.start();


    return a.exec();
}
