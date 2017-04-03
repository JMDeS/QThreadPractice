#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QtCore>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);


signals:


public slots:
    void onStarted();
    void onTimer();

};

#endif // WORKER_H
