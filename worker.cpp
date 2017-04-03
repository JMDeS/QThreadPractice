#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::onStarted()
{
    qDebug()<<"Worker::onStarted called from: "
           << QThread::currentThreadId();
}

void Worker::onTimer()
{
    qDebug()<<"Worker::onTimer called from: "
           << QThread::currentThreadId();
}
