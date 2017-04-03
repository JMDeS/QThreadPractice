#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
}


void Worker::onStarted()
{
    qDebug()<<"Worker::onStarted called from: "
           << QThread::currentThreadId();


//    qDebug()<<"Worker::onStarted called mutex.lock();";

    /*  TODO: (iss1) worker thread must wait for onStarted() to signal
     *      connectionSuccessful() before onTimer() can be called
     *
     *  potential solutions:
     *      i.---use a mutex
     *      ii.--use a waitCondition (or multiple)
     *      iii.-wait to initiate timer until signal is recieved
     *              --possibly have connectionSuccessful() signal onTimer()
     *
     */
}

void Worker::onTimer()
{
    qDebug()<<"Worker::onTimer called from: "
           << QThread::currentThreadId();
}
