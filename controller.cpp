#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{

}

void Controller::onStarted()
{
    qDebug()<<"ControlThread::onStarted called from: "
           << QThread::currentThreadId();
    QThread A_t;
    QObject::connect(&A_t, SIGNAL(started()), &A, SLOT(doFirst()));
    A.moveToThread(&A_t);
    A_t.start();
}
