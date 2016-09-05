#ifndef PLUGINABLEWIDGET_H
#define PLUGINABLEWIDGET_H

#include "widgetplugins_global.h"
#include "const_and_structs.h"
#include "iwidgetplugin.h"
#include "pluginpanel.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSharedPointer>
#include <QTimer>
#include "pluginfactory.h"

namespace WidgetPlugins {

class PluginableWidget:public QWidget
{

    Q_OBJECT

public:
    PluginableWidget(QWidget *parent,PluginInPlace place,QColor color);
    PluginableWidget(QWidget *parent,PluginInPlace place,QColor color, QList<PluginType> types);
    PluginableWidget(QWidget *parent, PluginInPlace place, QColor color, QList<PluginType> types,QString fileName);
    void  addPlugin(QWidget *parent, QList<PluginType> type, QString fileName=0);

protected:
    PluginPanel *_pluginPanel;

private:
    QMap<PluginType, QSharedPointer<IWidgetPlugin> > _pluginControls;
    PluginInPlace _plaginPanelPlace;
    QColor _pluginPanelColor;
    QTimer *_timer;
    QPropertyAnimation *_pluginPanelAnimationPropertyHide;
    QPropertyAnimation *_pluginPanelAnimationPropertyShow;
    void setGeometryPlugin();
public slots:
    void handleShowPluginPanel();
    void handleHidePluginPanel();
    void handleChangePluginColor();
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

};
}
#endif // PLUGINABLEWIDGET_H
