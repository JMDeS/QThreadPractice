#include "global_objects.h"

namespace
{
    QTimer timer;
    QMutex mutex;
    QWaitCondition A_notConnected;
    QWaitCondition B_notConnected;
}
