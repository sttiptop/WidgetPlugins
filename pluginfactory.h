#ifndef PLUGINFACTORY_H
#define PLUGINFACTORY_H
#include "widgetplugins_global.h"
#include "iwidgetplugin.h"
#include "const_and_structs.h"
#include <QSharedPointer>
#include <QDebug>


namespace WidgetPlugins
{
class  PluginFactory
{
public:
    static QSharedPointer<IWidgetPlugin> createPluginTest(QWidget *widget, PluginType type,QString fileName);
};
}

#endif // PLUGINFACTORY_H
