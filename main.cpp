#include <QCoreApplication>
#include "global_objects.h"
#include <QtCore>
#include "worker.h"

// global variables
QWaitCondition A_notConnected;
QWaitCondition B_notConnected;
QMutex mutex;
QTimer timer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"(GUI) main control thread: "<< QThread::currentThreadId();

    // declare worker objects and threads
    Worker A, B;
    QThread A_t, B_t;

    // workerThread.start() will signal-> worker.onStarted()
    QObject::connect(&A_t, SIGNAL(started()), &A, SLOT(onStarted()));
    QObject::connect(&B_t, SIGNAL(started()), &B, SLOT(onStarted()));

    // links each worker with global timer
    QObject::connect(&timer, SIGNAL(timeout()), &A, SLOT(onTimer()));
    QObject::connect(&timer, SIGNAL(timeout()), &B, SLOT(onTimer()));

    // start timer
    timer.start(1000);

    // move worker objects to their own thread
    A.moveToThread(&A_t);
    B.moveToThread(&B_t);

    // start the worker threads
    A_t.start();
    B_t.start();


    return a.exec();
}
