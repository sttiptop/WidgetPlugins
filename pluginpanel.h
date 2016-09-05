#ifndef PLUGINPANEL_H
#define PLUGINPANEL_H
#include "widgetplugins_global.h"
#include <QDebug>
#include <QLayout>
#include <QWidget>
#include "const_and_structs.h"
namespace WidgetPlugins {
class PluginPanel : public QWidget
{
    Q_OBJECT
public:
    PluginPanel(PluginInPlace place, QColor color, QWidget *parent=0);
    void  addWidgetAtPanel(QWidget *wgt);
private:
    QBoxLayout *_panelLayout;

    // QWidget interface
protected:
    void enterEvent(QEvent *);
protected:
    void leaveEvent(QEvent *);
signals:
    void enter();
    void drop(int time);

    // QWidget interface
protected:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};
}

#endif // PLUGINPANEL_H
