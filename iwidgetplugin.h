#ifndef IWIDGETPLUGIN_H
#define IWIDGETPLUGIN_H
#include "widgetplugins_global.h"
#include <QDebug>
#include <QObject>
#include <QApplication>
#include <QClipboard>
namespace WidgetPlugins
{
class IWidgetPlugin:public QObject

{
    Q_OBJECT
public:
    IWidgetPlugin(QWidget *parent = 0);
    virtual QWidget*  getControl()=0;
protected:
    QWidget *_wgt = nullptr;
    QString _fileName;
};
}
#endif // IWIDGETPLUGIN_H
