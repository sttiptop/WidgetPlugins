#ifndef SCREENSHOTWIDGETPLUGIN_H
#define SCREENSHOTWIDGETPLUGIN_H
#include <QDebug>
#include "iwidgetplugin.h"
#include <QApplication>
#include <QClipboard>
#include <QPushButton>
#include <QWidget>
namespace WidgetPlugins
{
class  ScreenShotWidgetPlugin: public IWidgetPlugin
{
    Q_OBJECT
public:
    ScreenShotWidgetPlugin(QWidget *parent=0);
    QWidget *  getControl();

private:
    QPushButton *_btn=nullptr;

    // IWidgetPlugin interface
public slots:
    void  handleScreenShot(bool);
};
}
#endif // SCREENSHOTWIDGETPLUGIN_H
