#ifndef CONTROL_H
#define CONTROL_H

#include <QtCore>
#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

public slots:
    void onStarted();

private:
    Worker A;
    Worker B;
//    QThread *A_t;
    QThread B_t;
    QTimer timer;
};

#endif // CONTROL_H
