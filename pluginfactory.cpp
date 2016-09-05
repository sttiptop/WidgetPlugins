#include "pluginfactory.h"
#include "iwidgetplugin.h"
#include "csvtableplugin.h"
#include "screenshotwidgetplugin.h"
#include "csvtablereportplugin.h"
#include "screenshotreportplugin.h"
namespace WidgetPlugins {
QSharedPointer<IWidgetPlugin> PluginFactory::createPluginTest(QWidget *widget, PluginType type, QString fileName)
{
    switch(type)
    {
    case PluginType::Unknown:
        qWarning("choose correct type");
        break;
    case PluginType::CSVPlugin:
        return QSharedPointer<CSVTablePlugin>::create(widget);
        break;
    case PluginType::ScreenShot:
        return QSharedPointer<ScreenShotWidgetPlugin>::create(widget);
        break;
    case PluginType::CSVPluginToFile:
        return QSharedPointer<CSVTableReportPlugin>(new CSVTableReportPlugin(fileName,widget));
        break;
    case PluginType::ScreenShotToFile:
        return QSharedPointer<ScreenShotReportPlugin>(new ScreenShotReportPlugin(fileName,widget));
        break;
    }
}

}
