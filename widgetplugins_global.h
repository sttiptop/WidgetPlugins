#ifndef WIDGETPLUGINS_GLOBAL_H
#define WIDGETPLUGINS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WIDGETPLUGINS_LIBRARY)
#  define WIDGETPLUGINSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WIDGETPLUGINSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WIDGETPLUGINS_GLOBAL_H
