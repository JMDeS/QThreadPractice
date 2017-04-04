#include "global_objects.h"

namespace
{
    QTimer timer;
    QMutex mutex;
    QWaitCondition camera_notConnected;
    QWaitCondition power_notConnected;
}
