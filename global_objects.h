#ifndef GLOBAL_OBJECTS_H
#define GLOBAL_OBJECTS_H


#include "qtimer.h"
#include "qwaitcondition.h"
#include "qmutex.h"

extern QTimer timer;
extern QMutex mutex;
extern QWaitCondition A_notConnected, B_notConnected;


#endif // GLOBAL_OBJECTS_H
