#ifndef NEAR_SENSOR_GLOBAL_H
#define NEAR_SENSOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NEAR_SENSOR_LIBRARY)
#  define NEAR_SENSOR_EXPORT Q_DECL_EXPORT
#else
#  define NEAR_SENSOR_EXPORT Q_DECL_IMPORT
#endif

#endif // NEAR_SENSOR_GLOBAL_H
